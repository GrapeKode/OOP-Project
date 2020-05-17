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
void ClientManagement(App*, Farmacie*);

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
    cout << Application.getHeader();
    cout << "E. Administrare entitati\n"
         << "M. Administrare medicamente\n"
         << "A. Administrare angajati\n"
         << "C. Administrare clienti\n"
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
      ClientManagement(&Application, &Pharmacy);
      break;
    case 'I':
      cout << Application.getHeader();
      cout << "I. Informatii suplimentare referitoare la functionarea aplicatiei\n\n";
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
