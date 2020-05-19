// Classes
#include "App.h"
#include "Farmacie.h"

using namespace std;

// Main Functions
void Entity_create(Farmacie*);
void Entity_edit(Farmacie*);
void Entity_delete(Farmacie*);

// Setters
void Entity_setName(Farmacie*);
void Entity_setLocation(Farmacie*);
void Entity_setUuid(Farmacie*);
void Entity_setDSize(Farmacie*);
void Entity_setPSize(Farmacie*);

// Getters
string Entity_print(Farmacie*);

/**
 * Entity Management
 */
void EntityManagement(App* Application, Farmacie* Pharmacy)
{
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
      Entity_create(Pharmacy);
      getch();
      break;
    case '2':
      cout << Application->getHeader();
      cout << "2. Editare entitate/firma\n\n";
      Entity_edit(Pharmacy);
      getch();
      break;
    case '3':
      cout << Application->getHeader();
      cout << "3. Stergere entitate/firma\n\n";
      Entity_delete(Pharmacy);
      getch();
      break;
    case '4':
      cout << Application->getHeader();
      cout << "4. Afisare entitate/firma\n\n";
      cout << Entity_print(Pharmacy);
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
void Entity_create(Farmacie* Pharmacy)
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
void Entity_edit(Farmacie* Pharmacy) {
  if (!Pharmacy->isValidFarmacie()) {
    cout << "Creati o entitate inainte de a o edita";
    return;
  }

  bool exit = false;
  char opt;

  do {
    system("cls");
    cout << Pharmacy->getHeader();
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
void Entity_delete(Farmacie* Pharmacy) {
  char remove;

  if (!Pharmacy->isValidEntity()) {
    cout << "Entitatea nu exista sau este invalida.\n\n";
    return;
  }

  cout << "Entitatea curenta:\n" << Pharmacy->printEntitate() << endl;
  
  cout << "Sunteti sigur ca doriti sa stergeti entitatea? (y/N): ";
  cin >> remove;
  if (toupper(remove) == 'Y') {
    Pharmacy->setRemove(true);
  }
}

// Setters
void Entity_setName(Farmacie* Pharmacy)
{
  std::string name;
  cout << "Inserati numele entitatii: ";
  cin.ignore();
  getline(cin, name, '\n');

  Pharmacy->setNume(name);
}
void Entity_setLocation(Farmacie* Pharmacy)
{
  std::string location;
  cout << "Inserati adresa entitatii: ";
  // cin.ignore();
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
string Entity_print(Farmacie* Pharmacy) {
  return Pharmacy->printEntitate();
}
