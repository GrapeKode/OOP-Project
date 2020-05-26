// Classes
#include "Farmacie.h"

using namespace std;

// Main Functions
void Employee_create(App*, Farmacie*, Angajat*);
void Employee_add(App*, Farmacie*, Angajat*);
void Employee_edit(App*, Farmacie*, Angajat*);
void Employee_delete(App*, Farmacie*, Angajat*);

// Setters
void Employee_setUuid(Farmacie*, Angajat*);
void Employee_setName(Angajat*);
void Employee_setCNP(Angajat*);
void Employee_setSalary(Angajat*);
void Employee_setSchedule(Angajat*);
void Employee_setLocation(Angajat*);
void Employee_setRank(Angajat*);

// Getters
string Employee_print(App*, Farmacie*, Angajat*);

/**
 * Employee Management
 */
void EmployeeManagement(App* Application, Farmacie* Pharmacy, Angajat* Employee)
{
  // Initiate component
  Application->setCurrentComponent("Employee");

  bool exit = false;
  char opt;
  do
  {
    system("cls");
    cout << Application->getHeader();
    cout << "A. Administrarea Angajatilor\n\n";

    cout << "1. Adaugare angajat\n"
         << "2. Editare angajat\n"
         << "3. Stergere angajat\n"
         << "4. Afisare anajat\n"
         << "5. Adaugare angajat\n"
         << "X. Meniul principal\n\n";

    cout << "Alegeti optiunea: ";
    cin >> opt;
    switch (toupper(opt))
    {
    case '1':
      cout << Application->getHeader();
      cout << "1. Adaugare angajat\n\n";
      Employee_create(Application, Pharmacy, Employee);
      getch();
      break;
    case '2':
      cout << Application->getHeader();
      cout << "2. Editare angajat\n\n";
      Employee_edit(Application, Pharmacy, Employee);
      getch();
      break;
    case '3':
      cout << Application->getHeader();
      cout << "3. Stergere angajat\n\n";
      Employee_delete(Application, Pharmacy, Employee);
      getch();
      break;
    case '4':
      cout << Application->getHeader();
      cout << "4. Afisare angajat\n\n";
      cout << Employee_print(Application, Pharmacy, Employee);
      getch();
      break;
    case '5':
      cout << Application->getHeader();
      cout << "5. Adaugare angajat\n\n";
      Employee_add(Application, Pharmacy, Employee);
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
void Employee_create(App* Application, Farmacie* Pharmacy, Angajat* Employee) {
  Employee_setName(Employee);
  Employee_setCNP(Employee);
  Employee_setSalary(Employee);
  Employee_setSchedule(Employee);
  Employee_setLocation(Employee);
  Employee_setRank(Employee);

  if (Employee->isValidPersoana()) {
    Employee_setUuid(Pharmacy, Employee);
    cout << "Angajatul a fost creat cu succes.";
  } else {
    cout << "Angajatul a fost creat, dar este invalid.";
  }
}
void Employee_add(App* Application, Farmacie* Pharmacy, Angajat* Employee) {
  if (!Pharmacy->isValidFarmacie()) {
    cout << "Creati o entitate inaite de a adauga angajati.";
    return;
  }

  if (!Employee->isValidPersoana()) {
    cout << "Datele angajatului sunt invalide.";
    return;
  }

  Pharmacy->setAngajat(*Employee);
}
void Employee_edit(App* Application, Farmacie* Pharmacy, Angajat* Employee) {
  char opt;

  cout << Application->getHeader()
       << "2. Editare angajat\n\n"
       << Employee->getPersoana()
       << "\n\n"
       << "1. Editeaza numele\n"
       << "2. Editeaza CNP-ul\n"
       << "3. Editeaza programul de lucru\n"
       << "4. Editeaza suma salariului\n"
       << "5. Editeaza adresa domicilului\n"
       << "6. Editeaza pozitia ocupata\n"
       << "X. Iesire din modul editare\n\n";

  cout << "Alegeti optiunea: ";
  cin >> opt;

  switch(toupper(opt)) {
  case '1':
    Employee_setName(Employee);
    break;
  case '2':
    Employee_setCNP(Employee);
    break;
  case '3':
    Employee_setSchedule(Employee);
    break;
  case '4':
    Employee_setSalary(Employee);
    break;
  case '5':
    Employee_setLocation(Employee);
    break;
  case '6':
    Employee_setRank(Employee);
    break;
  case 'X':
    return;
  default:
    cout << "Comanda invalida!";
    getch();
    break;
  }

  Employee_edit(Application, Pharmacy, Employee);
}
void Employee_delete(App* Application, Farmacie* Pharmacy, Angajat* Employee) {
  std::string remove;

  cout << Employee->getPersoana()
       << "\n\n"
       << "Pentru a sterge introduceti numele angajatului: ";
  cin.clear();
  cin.ignore();
  getline(cin, remove, '\n');

  if (Pharmacy->customCap(remove) == (Pharmacy->customCap(Employee->getPrenume() + " " + Pharmacy->customCap(Employee->getNume())))) {
    *Employee = Angajat();

    cout << "Angajatul a fost sters cu succes.";
    return;
  }

  cout << "Numele introdus nu corespunde.";
}

// Setters
void Employee_setUuid(Farmacie* Pharmacy, Angajat* Employee) {
  int length;

  // Set as default
  if (!Pharmacy->isValidFarmacie()) {
    Employee->setUuid(1);
  } else {
    length = Pharmacy->getLengthPersonal(Pharmacy->getAngajati(), true);
    Employee->setUuid(length + 1);
  }
}
void Employee_setName(Angajat* Employee) {
  string firstName, lastName;

  cout << "Introduceti prenumele: ";
  cin.ignore();
  cin.ignore();
  getline(cin, firstName, '\n');

  cout << "Introduceti numele de familie: ";
  cin.ignore();
  cin.ignore();
  getline(cin, lastName, '\n');

  Employee->setPrenume(firstName);
  Employee->setNume(lastName);
}
void Employee_setCNP(Angajat* Employee) {
  unsigned long long int CNP;

  cout << "Introduceti CNP-ul (13 cifre): ";
  cin >> CNP;

  if (std::cin.fail() || !Employee->isValidCNP(CNP)) {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return Employee_setCNP(Employee);
  }

  Employee->setCNP(CNP);
}
void Employee_setSalary(Angajat* Employee) {
  double salary;

  cout << "Introduceti suma salariului: ";
  cin >> salary;

  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return Employee_setSalary(Employee);
  }

  Employee->setSalariu(salary);
}
void Employee_setSchedule(Angajat* Employee) {
  int schedule;

  cout << "Introduceti numarul de ore pe zi (4-8): ";
  cin >> schedule;

  if (std::cin.fail() || !Employee->isValidProgram(schedule)) {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return Employee_setSchedule(Employee);
  }

  Employee->setProgram(schedule);
}
void Employee_setLocation(Angajat* Employee) {
  std::string location;

  cout << "Introduceti adresa: ";
  cin.ignore();
  cin.clear();
  getline(cin, location, '\n');

  if (!Employee->isValidLocatie(location)) {
    return Employee_setLocation(Employee);
  }

  Employee->setLocatie(location);
}
void Employee_setRank(Angajat* Employee) {
  std::string rank;

  cout << "Introduceti gradul angajatului: ";
  cin.ignore();
  cin.ignore();
  getline(cin, rank, '\n');

  if (!Employee->isValidGrad(rank)) {
    return Employee_setRank(Employee);
  }

  Employee->setGrad(rank);
}

// Getters
string Employee_print(App* Application, Farmacie* Pharmacy, Angajat* Employee) {
  return Employee->getPersoana();
}
