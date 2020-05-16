// Classes
#include "Farmacie.h"
#include "Angajat.h"

using namespace std;

// Main Functions
void Employee_add();
void Employee_edit();
void Employee_delete();

// Setters
void Employee_setName();
void Employee_setLocation();
void Employee_setUuid();

// Getters

/**
 * Employee Management
 */
void EmployeeManagement(App* Application, Farmacie* Pharmacy)
{
  Angajat Employee = Angajat();

  bool exit = false;
  char opt;
  do
  {
    system("cls");
    cout << Application->getHeader();
    cout << "A. Administrarea Angajatilor\n\n";

    cout << "1. Adaugare angajat/personal\n"
         << "2. Editare angajat/personal\n"
         << "3. Stergere angajat/personal\n"
         << "X. Meniul principal\n\n";

    cout << "Alegeti optiunea: ";
    cin >> opt;
    switch (toupper(opt))
    {
    case '1':
      cout << Application->getHeader();
      cout << "1. Adaugare angajat/personal\n\n";
      Employee_add();
      getch();
      break;
    case '2':
      cout << Application->getHeader();
      cout << "2. Editare angajat/personal\n\n";
      Employee_edit();
      getch();
      break;
    case '3':
      cout << Application->getHeader();
      cout << "3. Stergere angajat/personal\n\n";
      Employee_delete();
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
void Employee_add() {}
void Employee_edit() {}
void Employee_delete() {}

// Setters
void Employee_setName() {}
void Employee_setLocation() {}
void Employee_setUuid() {}

// Getters
