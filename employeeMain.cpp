// Classes
#include "Farmacie.h"

using namespace std;

// Main Functions
void Employee_create(Farmacie*, Angajat*);
void Employee_add(Farmacie*, Angajat*);
void Employee_edit(Farmacie*, Angajat*);
void Employee_delete();

// Setters
void Employee_setUuid(Farmacie*, Angajat*);
void Employee_setName(Angajat*);
void Employee_setCNP(Angajat*);
void Employee_setSalary(Angajat*);
void Employee_setSchedule(Angajat*);
void Employee_setLocation(Angajat*);
void Employee_setRank(Angajat*);

// Getters

/**
 * Employee Management
 */
void EmployeeManagement(App* Application, Farmacie* Pharmacy, Angajat* Employee)
{
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
      Employee_create(Pharmacy, Employee);
      getch();
      break;
    case '2':
      cout << Application->getHeader();
      cout << "2. Editare angajat\n\n";
      Employee_edit(Pharmacy, Employee);
      getch();
      break;
    case '3':
      cout << Application->getHeader();
      cout << "3. Stergere angajat\n\n";
      Employee_delete();
      getch();
      break;
    case '4':
      cout << Application->getHeader();
      cout << "4. Afisare angajat\n\n";
      // Employee_add(Pharmacy, Employee);
      getch();
      break;
    case '5':
      cout << Application->getHeader();
      cout << "5. Adaugare angajat\n\n";
      Employee_add(Pharmacy, Employee);
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
void Employee_create(Farmacie* Pharmacy, Angajat* Employee) {
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
void Employee_add(Farmacie* Pharmacy, Angajat* Employee) {
  if (!Employee->isValidPersoana()) {
    cout << "Datele angajatului sunt invalide.";
    return;
  }

  Pharmacy->setAngajat(*Employee);
}
void Employee_edit(Farmacie* Pharmacy, Angajat* Employee) {
  char opt;

  system("cls");
  cout << Pharmacy->getHeader()
       << "2. Edicate angajat\n\n"
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
    Employee_setUuid(Pharmacy, Employee);
    cout << "\n\nuuid = " << Employee->getUuid() << "\n\n";
    getch();
    break;
  case 'X':
    return;
  }

  Employee_edit(Pharmacy, Employee);
}
void Employee_delete() {}

// Setters
void Employee_setUuid(Farmacie* Pharmacy, Angajat* Employee) {
  int length;

  // Set as default
  if (!Pharmacy->isValidFarmacie()) {
    Employee->setUuid(1);
  } else {
    length = Pharmacy->getLengthPersonal(Pharmacy->getAngajati());
    cout << "Length >>> " << length;
    Employee->setUuid(length + 1);
  }
}
void Employee_setName(Angajat* Employee) {
  string firstName, lastName;

  cout << "Introduceti prenumele: ";
  cin.ignore();
  getline(cin, firstName, '\n');

  cout << "Introduceti numele de familie: ";
  // cin.ignore();
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
  // cin.ignore();
  getline(cin, location, '\n');

  if (!Employee->isValidLocatie(location)) {
    return Employee_setLocation(Employee);
  }

  Employee->setLocatie(location);
}
void Employee_setRank(Angajat* Employee) {
  std::string rank;

  cout << "Introduceti gradul angajatului: ";
  // cin.ignore();
  getline(cin, rank, '\n');

  if (!Employee->isValidGrad(rank)) {
    return Employee_setRank(Employee);
  }

  Employee->setGrad(rank);
}

// Getters
