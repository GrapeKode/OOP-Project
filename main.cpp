// Classes
#include "App.h"
#include "Entitate.h"
#include "Farmacie.h"
#include "Persoana.h"
#include "Angajat.h"
#include "Client.h"
#include "Medicament.h"

using namespace std;

// Main functions
void EntityManagement(App*, Farmacie*);
void MedicineManagement(App*, Farmacie*, Pastile*, Sirop*);
void EmployeeManagement(App*, Farmacie*, Angajat*);
void ClientManagement(App*, Farmacie*, Client*);
void AppSettings(App*);

// Setters
void Main_setAutoSave(App*);
void Main_setAutoValidate(App*);

int main()
{
  App Application = App();
  Farmacie Pharmacy = Farmacie();
  Pastile Pill = Pastile();
  Sirop Syrup = Sirop();
  Angajat Employee = Angajat();
  Client Consumer = Client();

  char opt;
  do
  {
    // Initiate current component
    Application.setCurrentComponent("Main");
    
    cout << Application.getHeader();
    cout << "E. Administrare entitati\n"
         << "M. Administrare medicamente\n"
         << "A. Administrare angajati\n"
         << "C. Administrare clienti\n"
         << "S. Setarile aplicatiei\n"
         << "I. Info\n"
         << "X. Iesire\n\n";

    cout << "Alege optiunea: ";
    cin >> opt;

    switch (toupper(opt))
    {
    case 'E':
      EntityManagement(&Application, &Pharmacy);
      break;
    case 'M':
      MedicineManagement(&Application, &Pharmacy, &Pill, &Syrup);
      break;
    case 'A':
      EmployeeManagement(&Application, &Pharmacy, &Employee);
      break;
    case 'C':
      ClientManagement(&Application, &Pharmacy, &Consumer);
      break;
    case 'S':
      AppSettings(&Application);
      break;
    case 'I':
      // cout << Application.getHeader();
      system("cls");
      cout << "I. Informatii\n\n";
      Application.Info();
      getch();
      break;
    case 'X':
      cout << Application.getHeader();
      Application.Exit();
      break;
    }
  } while (1);
  return 0;
}

void AppSettings(App* Application) {
  char opt;

  cout << Application->getHeader()
       << "S. Setarile aplicatiei\n\n"
       << Application->getSettings()
       << "\n\n"
       << "1. Modifica auto-salvarea\n"
       << "2. Modifica auto-validarea\n"
       << "X. Revenire la meniul principal\n\n";

  cout << "Alegeti optiunea: ";
  cin >> opt;

  switch(toupper(opt)) {
  case '1':
    Main_setAutoSave(Application);
    break;
  case '2':
    Main_setAutoValidate(Application);
    break;
  case 'X':
    cout << Application->getHeader();
    cout << "Se trece in meniul principal...";
    Application->Sleep(500);
    return;
  default:
    cout << "Optiune invalida!";
    getch();
    break;
  }

  return AppSettings(Application);
}

// Setters
void Main_setAutoSave(App* Application) {
  char autoSave;
  bool isAutoSave = Application->getAutoSave();

  if (isAutoSave) {
    cout << "\n\nDezactivati auto-salvarea? (y/N): ";
    cin >> autoSave;
  } else {
    cout << "\n\nActivati auto-salvarea? (Y/n): ";
    cin >> autoSave;
  }

  if (toupper(autoSave) == 'Y') {
    Application->setAutoSave(!isAutoSave);
  }
}
void Main_setAutoValidate(App* Application) {
  char autoValidate;
  bool isAutoValidate = Application->getAutoValidare();

  if (isAutoValidate) {
    cout << "\n\nDezactivati auto-validarea? (Y/n): ";
    cin >> autoValidate;
  } else {
    cout << "\n\nActivati auto-validarea? (y/N): ";
    cin >> autoValidate;
  }

  if (toupper(autoValidate) == 'Y') {
    Application->setAutoValidare(!isAutoValidate);
  }
}
