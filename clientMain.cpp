// Classes
#include "Farmacie.h"
#include "Client.h"

using namespace std;

// Main Functions
void Client_add();
void Client_edit();
void Client_delete();

// Setters
void Client_setName();
void Client_setLocation();
void Client_setUuid();

/**
 * Client Management
 */
void ClientManagement(App* Application, Farmacie* Pharmacy)
{
  Client Customer = Client();

  bool exit = false;
  char opt;
  do
  {
    cout << Application->getHeader();
    cout << "M. Administrare medicamente\n\n";

    cout << "1. Creare client\n"
         << "2. Editare client\n"
         << "3. Stergere client\n"
         << "X. Meniul principal\n\n";

    cout << "Alegeti optiunea: ";
    cin >> opt;
    switch (toupper(opt))
    {
    case '1':
      cout << Application->getHeader();
      cout << "1. Creare client\n\n";
      cout << "\n\nPress any key followed by <enter>";
      getch();
      break;
    case '2':
      cout << Application->getHeader();
      cout << "2. Editare client\n\n";
      cout << "\n\nPress any key followed by <enter>";
      getch();
      break;
    case '3':
      cout << Application->getHeader();
      cout << "3. Stergere client\n\n";
      cout << "\n\nPress any key followed by <enter>";
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
void Client_add() {}
void Client_edit() {}
void Client_delete() {}

// Setters
void Client_setName() {}
void Client_setLocation() {}
void Client_setUuid() {}
