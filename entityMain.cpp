// Classes
#include "App.h"
#include "Farmacie.h"

using namespace std;

// Main Functions
void Entity_create(App*, Farmacie*);
void Entity_edit(App*, Farmacie*);
void Entity_delete(App*, Farmacie*);

// Recover entity
bool Entity_recover(Farmacie*);

// Setters
void Entity_setName(Farmacie*);
void Entity_setLocation(Farmacie*);
void Entity_setUuid(Farmacie*);
void Entity_setDSize(Farmacie*);
void Entity_setPSize(Farmacie*);

// Getters
void Entity_print(App*, Farmacie*);

/**
 * Entity Management
 */
void EntityManagement(App* Application, Farmacie* Pharmacy)
{
  Application->setCurrentComponent("Entity");

  bool exit = false;
  char opt;
  do
  {
    cout << Application->getHeader();
    cout << "E. Administrarea Eentitatilor\n\n";

    cout << "1. Creare entitate/firma\n"
         << "2. Editare entitate/firma\n"
         << "3. Stergere entitate/firma\n"
         << "4. Afisare entitate/firma\n"
         << "X. Meniul principal\n\n";

    cout << "Alegeti optiunea: ";
    cin >> opt;
    switch (toupper(opt))
    {
    case '1':
      cout << Application->getHeader();
      cout << "1. Creare entitate/firma\n\n";
      Entity_create(Application, Pharmacy);
      getch();
      break;
    case '2':
      cout << Application->getHeader();
      cout << "2. Editare entitate/firma\n\n";
      Entity_edit(Application, Pharmacy);
      getch();
      break;
    case '3':
      cout << Application->getHeader();
      cout << "3. Stergere entitate/firma\n\n";
      Entity_delete(Application, Pharmacy);
      getch();
      break;
    case '4':
      Entity_print(Application, Pharmacy);
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
void Entity_create(App* Application, Farmacie* Pharmacy)
{
  *Pharmacy = Farmacie();

  cout << endl;
  Entity_setName(Pharmacy);
  Entity_setLocation(Pharmacy);
  Entity_setUuid(Pharmacy);
  Entity_setDSize(Pharmacy);
  Entity_setPSize(Pharmacy);

  if (Pharmacy->isValidFarmacie()) {
    cout << "\nEntitatea (" << Pharmacy->getNume() << ") a fost creata cu succes.";
  } else {
    cout << "Entitatea creata nu este valida.";
  }
}
void Entity_edit(App* Application, Farmacie* Pharmacy) {
  if (!Pharmacy->isValidFarmacie()) {
    cout << "Creati o entitate inainte de a o edita";
    return;
  }

  bool exit = false;
  char opt;

  do {
    system("cls");
    cout << Application->getHeader();
    cout << "Editati entitatea curenta [" << Pharmacy->getId() << "] " << Pharmacy->getNume() << "\n\n";
    cout << "1. Editeaza numele entitatii\n"
         << "2. Editeaza locatia entitatii\n"
         << "3. Editeaza numarul disponibil de medicamente\n"
         << "4. Editeaza numarul disponibil de angajati\n"
         << "X. Iesire din modul editate\n\n";

    cout << "Alegeti optiunea:";
    cin >> opt;

    switch(opt) {
      case '1':
        cout << "1. Editeaza numele entitatii\n";
        Entity_setName(Pharmacy);
        getch();
        break;
      case '2':
        cout << "2. Editeaza locatia entitatii\n";
        Entity_setLocation(Pharmacy);
        getch();
        break;
      case '3':
        cout << "3. Editeaza numarul disponibil de medicamente\n";
        Entity_setDSize(Pharmacy);
        getch();
        break;
      case '4':
        cout << "4. Editeaza numarul disponibil de angajati\n";
        Entity_setPSize(Pharmacy);
        getch();
        break;
      case 'x':
      case 'X':
        cout << "Se iese din modul editare.\n";
        exit = true;
        break;
      default:
        cout << "Optiune invalida!";
        getch();
        break;
    }

    if (exit) {
      break;
    }
  } while(1);
}
void Entity_delete(App* Application, Farmacie* Pharmacy) {
  std::string remove;
  bool isRecovered;

  if (Pharmacy->isValidEntity() && Pharmacy->isRemovedEntity()) {
    cout << "Entitatea a fost stearsa!\n\n";
    isRecovered = Entity_recover(Pharmacy);

    if (!isRecovered) {
      cout << "Nu s-a putut recupera entitatea...";
      return;
    } else {
      cout << "Entitatea a fost recuperata cu succes.";
      return;
    }
  }

  cout << Pharmacy->printEntitate()
       << "\n\n"
       << "Pentru a sterge introduceti numele entitatii: ";
  cin.clear();
  cin.ignore();
  getline(cin, remove, '\n');

  if (Pharmacy->customCap(remove) == Pharmacy->customCap(Pharmacy->getNume())) {
    Pharmacy->setRemove(true);

    cout << "\nEntitatea a fost stearsa cu succes.\n\n";
    return;
  }

  cout << "Numele introdus nu corespunde.";
}

// Recover entity
bool Entity_recover(Farmacie* Pharmacy) {
  char recover;

  cout << "Doriti s-o recuperati? (Y/n): ";
  cin >> recover;

  if (toupper(recover) == 'Y') {
    Pharmacy->setRemove(false);

    return true;
  }

  return false;
}

// Setters
void Entity_setName(Farmacie* Pharmacy)
{
  std::string name;
  cout << "Inserati numele entitatii: ";
  cin.clear();
  cin.ignore();
  getline(cin, name, '\n');

  Pharmacy->setNume(name);
}
void Entity_setLocation(Farmacie* Pharmacy)
{
  std::string location;
  cout << "Inserati adresa entitatii: ";
  cin.clear();
  cin.ignore();
  getline(cin, location, '\n');

  Pharmacy->setLocatie(location);
}
void Entity_setUuid(Farmacie* Pharmacy)
{
  int uuid;
  cout << "Inserati id-ul entitatii: ";
  cin >> uuid;

  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return Entity_setUuid(Pharmacy);
  }

  Pharmacy->setId(uuid);
}
void Entity_setDSize(Farmacie* Pharmacy) {
  int dSize;
  cout << "Introduceti numarul de medicamente disponibile in depozit: ";
  cin >> dSize;

  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return Entity_setDSize(Pharmacy);
  }

  Pharmacy->setDepozitSize(dSize);
}
void Entity_setPSize(Farmacie* Pharmacy) {
  int pSize;
  cout << "Introduceti numarul disponibil de angajati: ";
  cin >> pSize;
  Pharmacy->setPersonalSize(pSize);
}

// Getters
void Entity_print(App* Application, Farmacie* Pharmacy) {
  char opt;
  int pLen, sLen, aLen, cLen;

  cout << Application->getHeader()
       << "4. Afisare entitate/firma\n\n"
       << Pharmacy->printEntitate()
       << "1. Afisati pastilele\n"
       << "2. Afisati siropurile\n"
       << "3. Afisati angajatii\n"
       << "4. Afisati clientii\n"
       << "X. Iesire din modul afisare\n\n"
       << "Alegeti optiunea: ";
  cin >> opt;

  switch(toupper(opt)) {
  case '1':
    pLen = Pharmacy->getLengthPastile();

    cout << "\n\nPastile [" << pLen << "]:\n\n";
    cout << Pharmacy->printPastile();

    getch();
    break;
  case '2':
    sLen = Pharmacy->getLengthSiropuri();

    cout << "\n\nSiropuri [" << sLen << "]:\n\n";
    cout << Pharmacy->printSiropuri();

    getch();
    break;
  case '3':
    aLen = Pharmacy->getLengthAngajati();

    cout << "\n\nAngajati [" << aLen << "]:\n\n";
    cout << Pharmacy->printAngajati();

    getch();
    break;
  case '4':
    cLen = Pharmacy->getLengthClienti();

    cout << "\n\nClienti [" << cLen << "]:\n\n";
    cout << Pharmacy->printClienti();

    getch();
    break;
  case 'X':
    return;
  default:
    cout << "Optiune invalida!";
    getch();
    break;
  }

  return Entity_print(Application, Pharmacy);;
}
