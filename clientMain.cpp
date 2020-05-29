// Classes
#include "Farmacie.h"

using namespace std;

// Main Functions
void Client_create(App*, Farmacie*, Client*);
void Client_add(App*, Farmacie*, Client*);
void Client_edit(App*, Farmacie*, Client*);
void Client_delete(App*, Farmacie*, Client*);
// Farmacie
void Client_findP(App*, Farmacie*, Client*);
void Client_editP(App*, Farmacie*, Client*);
void Client_deleteP(App*, Farmacie*, Client*);

// Setters
void Client_setName(Client*);
void Client_setCNP(Client*);
void Client_setRecomandare(Client*);
void Client_setReteta(Client*);
void Client_setClientFidel(Client*);

// Getters
string Client_print(App*, Farmacie*, Client*);

// Utils
unsigned long long int Client_getCNP(Client*);

/**
 * Client Management
 */
void ClientManagement(App* Application, Farmacie* Pharmacy, Client* Consumer)
{
  // Initiate component
  Application->setCurrentComponent("Client");

  bool exit = false;
  char opt;
  do
  {
    system("cls");
    cout << Application->getHeader();
    cout << "M. Administrarea Clientilor\n\n";

    cout << "1. Creare client\n"
         << "2. Editare client\n"
         << "3. Stergere client\n"
         << "4. Afisare client\n"
         << "5. Adaugare in baza de date\n"
         << "6. Cautare in baza de date\n"
         << "7. Editare din baza de date\n"
         << "8. Stergere din baza de date\n"
         << "X. Meniul principal\n\n";

    cout << "Alegeti optiunea: ";
    cin >> opt;
    switch (toupper(opt))
    {
    case '1':
      cout << Application->getHeader();
      cout << "1. Creare client\n\n";
      Client_create(Application, Pharmacy, Consumer);
      if (Application->getAutoValidare()) {
        Consumer->autoValidate();
      }
      getch();
      break;
    case '2':
      cout << Application->getHeader();
      cout << "2. Editare client\n\n";
      Client_edit(Application, Pharmacy, Consumer);
      if (Application->getAutoValidare()) {
        Consumer->autoValidate();
      }
      getch();
      break;
    case '3':
      cout << Application->getHeader();
      cout << "3. Stergere client\n\n";
      Client_delete(Application, Pharmacy, Consumer);
      getch();
      break;
    case '4':
      cout << Application->getHeader();
      cout << "4. Afisare client\n\n";
      cout << Client_print(Application, Pharmacy, Consumer);
      getch();
      break;
    case '5':
      cout << Application->getHeader();
      cout << "5. Adaugare client in baza de date\n\n";
      Client_add(Application, Pharmacy, Consumer);
      getch();
      break;
    case '6':
      cout << Application->getHeader();
      cout << "6. Cautare client in baza de date\n\n";
      Client_findP(Application, Pharmacy, Consumer);
      getch();
      break;
    case '7':
      cout << Application->getHeader();
      cout << "7. Editare client din baza de date\n\n";
      Client_editP(Application, Pharmacy, Consumer);
      getch();
      break;
    case '8':
      cout << Application->getHeader();
      cout << "8. Stergere client din baza de date\n\n";
      Client_deleteP(Application, Pharmacy, Consumer);
      getch();
      break;
    case 'X':
      cout << Application->getHeader();
      cout << "Se trece in meniul principal...";
      Application->Sleep(500);
      exit = true;
      break;
    }

    if (exit)
    {
      break;
    }

  } while (1);
}

// Main Functions
void Client_create(App* Application, Farmacie* Pharmacy, Client* Consumer) {
  Client_setName(Consumer);
  Client_setCNP(Consumer);
  Client_setReteta(Consumer);
  Client_setRecomandare(Consumer);
  Client_setClientFidel(Consumer);

  if (Consumer->isValidPersoana()) {
    cout << "Clientul a fost creat cu succes.";
  } else {
    cout << "Clientul a fost creat, dar este invalid.";
  }
}
void Client_add(App* Application, Farmacie* Pharmacy, Client* Consumer) {
  if (!Consumer->isValidPersoana()) {
    cout << "Datele clientului sunt invalide.";
    return;
  }
  if (!Pharmacy->isValidFarmacie()) {
    cout << "Creati o entitate inainte de a adauga un client.";
    return;
  }

  Pharmacy->setClient(*Consumer);

  // Auto-save
  if (Application->getAutoSave()) {
    Pharmacy->saveEntity();
  }
}
void Client_edit(App* Application, Farmacie* Pharmacy, Client* Consumer) {
  char opt;

  cout << Application->getHeader()
       << "2. Editare client\n\n"
       << Consumer->getPersoana()
       << "\n\n"
       << "1. Editeaza numele\n"
       << "2. Editeaza CNP_ul\n"
       << "3. Editeaza reteta\n"
       << "4. Editeaza recomandarea\n"
       << "5. Editeaza fidelitatea clientului\n"
       << "X. Iesire din modul editare\n\n";

  cout << "Alegeti optiunea: ";
  cin >> opt;

  switch(toupper(opt)) {
  case '1':
    Client_setName(Consumer);
    break;
  case '2':
    Client_setCNP(Consumer);
    break;
  case '3':
    Client_setReteta(Consumer);
    break;
  case '4':
    Client_setRecomandare(Consumer);
    break;
  case '5':
    Client_setClientFidel(Consumer);
    break;
  case 'X':
    return;
  default:
    cout << "Comanda invalida!";
    getch();
    break;
  }

  return Client_edit(Application, Pharmacy, Consumer);
}
void Client_delete(App* Application, Farmacie* Pharmacy, Client* Consumer) {
  std::string remove;

  cout << Consumer->getPersoana()
       << "\n\n"
       << "Pentru a sterge introduceti numele clientului: ";
  cin >> remove;

  if (Pharmacy->customCap(remove) == Pharmacy->customCap(Consumer->getNume())) {
    *Consumer = Client();

    cout << "Clientul a fost sters cu succes.";
    return;
  }

  cout << "Numele introdus nu corespunde.";
}
// Farmacie
void Client_findP(App* Application, Farmacie* Pharmacy, Client* Consumer) {
  char allow;

  if (!Pharmacy->isValidFarmacie()) {
    cout << "INFO: Farmacia nu exista sau este invalida.";
    return;
  }
  cout << "WARNING: Aceasta actiune va sterge clientul curent! Continuati? (y/N): ";
  cin >> allow;
  if (toupper(allow) == 'N') {
    return;
  }

  unsigned long long int CNP = Client_getCNP(Consumer);
  int findIndex;
  Client C;

  findIndex = Pharmacy->findIndexClient(CNP);
  if (findIndex == -1) {
    cout << "INFO: Clientul nu a fost gasit.";
    return;
  }
  C = Pharmacy->findClient(findIndex);
  if (!C.isValidPersoana()) {
    cout << "INFO: Clientul nu exista in baza de date sau este invalid.";
    return;
  }

  *Consumer = C;
  cout << "INFO: Clientul a fost gasit.\n\n"
       << C.getPersoana();
}
void Client_editP(App* Application, Farmacie* Pharmacy, Client* Consumer) {
  if (!Pharmacy->isValidFarmacie()) {
    cout << "INFO: Farmacia nu exista sau este invalida.";
    return;
  }

  unsigned long long int CNP = Client_getCNP(Consumer);
  int findIndex;
  Client C;

  findIndex = Pharmacy->findIndexClient(CNP);
  if (findIndex == -1) {
    cout << "INFO: Clientul nu a fost gasit.";
    return;
  }
  C = Pharmacy->findClient(findIndex);
  if (!C.isValidPersoana()) {
    cout << "INFO: Clientul nu exista in baza de date sau este invalid.";
    return;
  }

  Client_edit(Application, Pharmacy, &C);
  Pharmacy->setClient(C, findIndex);

  // Auto-save
  if (Application->getAutoSave()) {
    Pharmacy->saveEntity();
  }
}
void Client_deleteP(App* Application, Farmacie* Pharmacy, Client* Consumer) {
  if (!Pharmacy->isValidFarmacie()) {
    cout << "INFO: Farmacia nu exista sau este invalida.";
    return;
  }

  unsigned long long int CNP = Client_getCNP(Consumer);
  int findIndex;
  Client C;

  findIndex = Pharmacy->findIndexClient(CNP);
  if (findIndex == -1) {
    cout << "INFO: Clientul nu a fost gasit.";
    return;
  }
  C = Pharmacy->findClient(findIndex);
  if (!C.isValidPersoana()) {
    cout << "INFO: Clientul nu exista in baza de date sau este invalid.";
    return;
  }

  Pharmacy->removeClient(findIndex);
  cout << "INFO: Clientul a fost sters cu succes.";

  // Auto-save
  if (Application->getAutoSave()) {
    Pharmacy->saveEntity();
  }
}

// Setters
void Client_setName(Client* Consumer) {
  string firstName, lastName;

  cout << "Introduceti prenumele: ";
  cin.clear();
  cin.ignore();
  getline(cin, firstName, '\n');

  cout << "Introduceti numele de familie: ";
  cin.clear();
  // cin.ignore();
  getline(cin, lastName, '\n');

  Consumer->setPrenume(firstName);
  Consumer->setNume(lastName);
}
void Client_setCNP(Client* Consumer) {
  unsigned long long int CNP = Client_getCNP(Consumer);

  Consumer->setCNP(CNP);
}
void Client_setRecomandare(Client* Consumer) {
  std::string recomandare;

  cout << "Introduceti recomandarea (medicamente): ";
  cin.clear();
  // cin.ignore();
  getline(cin, recomandare, '\n');

  Consumer->setRecomandare(recomandare);
}
void Client_setReteta(Client* Consumer) {
  std::string reteta;

  cout << "Introduceti reteta: ";
  cin.clear();
  cin.ignore();
  getline(cin, reteta, '\n');

  Consumer->setReteta(reteta);
}
void Client_setClientFidel(Client* Consumer) {
  char isClientFidel;

  cout << "Este client fidel? (Y/n): ";
  cin >> isClientFidel;

  if (tolower(isClientFidel) == 'y') {
    Consumer->setClientFidel(true);
  } else {
    Consumer->setClientFidel(false);
  }
}

// Getters
string Client_print(App* Application, Farmacie* Pharmacy, Client* Consumer) {
  return Consumer->getPersoana();
}

// Utils
unsigned long long int Client_getCNP(Client* Consumer) {
  unsigned long long int CNP;

  cout << "Introduceti CNP-ul (13 cifre): ";
  cin >> CNP;

  if (std::cin.fail() || !Consumer->isValidCNP(CNP)) {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return Client_getCNP(Consumer);
  }

  return CNP;
}
