// Classes
#include "Farmacie.h"

using namespace std;

// Main Functions
void Client_create(Farmacie*, Client*);
void Client_add(Farmacie*, Client*);
void Client_edit();
void Client_delete();

// Setters
void Client_setName(Client*);
void Client_setCNP(Client*);
void Client_setRecomandare(Client*);
void Client_setReteta(Client*);
void Client_setClientFidel(Client*);

// Getters
string Client_print(Client*);

/**
 * Client Management
 */
void ClientManagement(App* Application, Farmacie* Pharmacy, Client* Consumer)
{
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
         << "5. Adaugare client\n"
         << "X. Meniul principal\n\n";

    cout << "Alegeti optiunea: ";
    cin >> opt;
    switch (toupper(opt))
    {
    case '1':
      cout << Application->getHeader();
      cout << "1. Creare client\n\n";
      Client_create(Pharmacy, Consumer);
      getch();
      break;
    case '2':
      cout << Application->getHeader();
      cout << "2. Editare client\n\n";
      getch();
      break;
    case '3':
      cout << Application->getHeader();
      cout << "3. Stergere client\n\n";
      getch();
      break;
    case '4':
      cout << Application->getHeader();
      cout << "4. Afisare client\n\n";
      getch();
      break;
    case '5':
      cout << Application->getHeader();
      cout << "5. Adaugare client\n\n";
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
void Client_create(Farmacie* Pharmacy, Client* Consumer) {
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
void Client_add(Farmacie* Pharmacy, Client* Consumer) {
  if (!Consumer->isValidPersoana()) {
    cout << "Datele clientului sunt invalide.";
    return;
  }

  Pharmacy->setClient(*Consumer);
}
void Client_edit(Farmacie* Pharmacy, Client* Consumer) {
  char opt;

  system("cls");
  cout << Pharmacy->getHeader()
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
}
void Client_delete(Farmacie* Pharmacy, Client* Consumer) {
  std::string remove;

  cout << Consumer->getPersoana()
       << "\n\n"
       << "Pentru a sterge introduceti numele clientului: ";
  cin >> remove;

  if (remove == Consumer->getNume()) {
    *Consumer = Client();

    cout << "Clientul a fost sters cu succes.";
    return;
  }

  cout << "Numele introdus nu corespunde.";
}

// Setters
void Client_setName(Client* Consumer) {
  string firstName, lastName;

  cout << "Introduceti prenumele: ";
  cin.ignore();
  getline(cin, firstName, '\n');

  cout << "Introduceti numele de familie: ";
  // cin.ignore();
  getline(cin, lastName, '\n');

  Consumer->setPrenume(firstName);
  Consumer->setNume(lastName);
}
void Client_setCNP(Client* Consumer) {
  unsigned long long int CNP;

  cout << "Introduceti CNP-ul (13 cifre): ";
  cin >> CNP;

  if (std::cin.fail() || !Consumer->isValidCNP(CNP)) {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return Client_setCNP(Consumer);
  }

  Consumer->setCNP(CNP);
}
void Client_setRecomandare(Client* Consumer) {
  std::string recomandare;

  cout << "Introduceti recomandarea (medicamente): ";
  getline(cin, recomandare, '\n');

  Consumer->setRecomandare(recomandare);
}
void Client_setReteta(Client* Consumer) {}
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
string Client_print(Client* Consumer) {
  return Consumer->getPersoana();
}
