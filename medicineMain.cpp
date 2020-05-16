// Classes
#include "Farmacie.h"
#include "Sirop.h"
#include "Pastile.h"

using namespace std;

// Main Functions
void Medicine_create(Farmacie*, Pastile*, Sirop*);
void Medicine_add(Farmacie*, Pastile*, Sirop*);
void Medicine_edit(Farmacie*, Pastile*, Sirop*);
void Medicine_editMedicament(Farmacie*, Pastile*, Sirop*, int);
void Medicine_delete(Farmacie*, Pastile*, Sirop*);

template <typename T>
void Medicine_setDefault(T*);
int Medicine_choose();

// Setters
template <typename T>
void Medicine_setName(T*);
template <typename T>
void Medicine_setInterval(T*);
template <typename T>
void Medicine_setGramaj(T*);
template <typename T>
void Medicine_setPret(T*);
template <typename T>
void Medicine_setValabilitate(T*);
template <typename T>
void Medicine_setTinta(T*);
template <typename T>
void Medicine_setScop(T*);
template <typename T>
void Medicine_setCuloare(T*);
// Pills
void Pills_setNr(Pastile*);
void Pills_setTip(Pastile*);
// Syrups
void Syrups_setCantitate(Sirop*);
void Syrups_setTip(Sirop*);

// Getters
string Medicine_print(Farmacie*, Pastile*, Sirop*);

/**
 * Medicine Management
 */
void MedicineManagement(App* Application, Farmacie* Pharmacy, Pastile* Pill, Sirop* Syrup)
{
  bool exit = false;
  char opt;
  do
  {
    cout << Application->getHeader();
    cout << "C. Administrarea Clientilor\n\n";

    cout << "1. Creare medicament\n"
         << "2. Editare medicament\n"
         << "3. Stergere medicament\n"
         << "4. Afisare medicament\n"
         << "5. Adaugare medicament in depozit\n"
         << "X. Meniul principal\n\n";

    cout << "Alegeti optiunea: ";
    cin >> opt;
    switch (toupper(opt))
    {
    case '1':
      cout << Application->getHeader();
      cout << "1. Creare medicament\n\n";
      Medicine_create(Pharmacy, Pill, Syrup);
      getch();
      break;
    case '2':
      Medicine_edit(Pharmacy, Pill, Syrup);
      getch();
      break;
    case '3':
      cout << Application->getHeader();
      cout << "3. Stergere medicament\n\n";
      Medicine_delete(Pharmacy, Pill, Syrup);
      getch();
      break;
    case '4':
      cout << Application->getHeader();
      cout << "4. Afisare medicament\n\n";
      cout << Medicine_print(Pharmacy, Pill, Syrup);
      getch();
      break;
    case '5':
      cout << Application->getHeader();
      cout << "5. Adaugare medicament in depozit\n\n";
      Medicine_add(Pharmacy, Pill, Syrup);
      getch();
      break;
    case 'X':
      cout << Application->getHeader();
      cout << "Se trece in meniul principal...";
      Application->Sleep(500);
      exit = true;
      break;
    }

    if (exit) {
      break;
    }

  } while (1);
}

// Main Functions
void Medicine_create(Farmacie* Pharmacy, Pastile* Pill, Sirop* Syrup) {
  int type = Medicine_choose();

  if (type == 1) {
    Medicine_setDefault(Pill);
    Pills_setNr(Pill);
    Pills_setTip(Pill);
  } else {
    Medicine_setDefault(Syrup);
    Syrups_setCantitate(Syrup);
    Syrups_setTip(Syrup);
  }

  // Save the changes
  // Pharmacy->
}
void Medicine_add(Farmacie* Pharmacy, Pastile* Pill, Sirop* Syrup) {
  int type = Medicine_choose();

  if ((type == 1 && !Pill->isValidMedicament()) || (type == 2 && !Syrup->isValidMedicament())) {
    cout << "Creati un medicament inaite de a-l adauga.";
    return;
  }

  if (!Pharmacy->isValidFarmacie()) {
    cout << "Creati o entitate inainte de a adauga medicamente.";
    return;
  }

  if (type == 1) {
    Pharmacy->setPastile(*Pill);
  } else {
    Pharmacy->setSirop(*Syrup);
  }
}
void Medicine_edit(Farmacie* Pharmacy, Pastile* Pill, Sirop* Syrup) {
  int type = Medicine_choose();

  if ((type == 1 && !Pill->isValidMedicament()) || (type == 2 && !Syrup->isValidMedicament())) {
    cout << "Creati un medicament inainte de a o edita.";
    return;
  }

  Medicine_editMedicament(Pharmacy, Pill, Syrup, type);
}
void Medicine_editMedicament(Farmacie* Pharmacy, Pastile* Pill, Sirop* Syrup, int type) {
  char opt;

  system("cls");
  cout << Pharmacy->getHeader();
  cout << "2. Editare medicament; tipul selectat: ";
  if (type == 1) {
    cout <<"Pastile\n\n";
  } else {
    cout << "Sirop\n\n";
  }
  cout << "1. Editeaza numele\n"
       << "2. Editeaza gramajul\n"
       << "3. Editeaza intervalul orar\n"
       << "4. Editeaza pretul\n"
       << "5. Editeaza termenul de valabilitate\n"
       << "6. Editeaza tinta (Copii | Adulti)\n"
       << "7. Editeaza scopul\n"
       << "8. Editeaza culoarea\n";
  if (type == 1) {
    cout << "9. Editeaza numarul de pastile\n";
  } else {
    cout << "9. Editeaza cantitatea\n";
  }
  cout << "0. Editeaza tipul ambalajului\n"
       << "X. Iesire din modul editare\n\n";

  cout << "Alegeti optiunea: ";
  cin >> opt;

  switch(opt)
  {
  case '1':
    if (type == 1) {
      Medicine_setName(Pill);
    } else {
      Medicine_setName(Syrup);
    }
    break;
  case '2':
    if (type == 1) {
      Medicine_setGramaj(Pill);
    } else {
      Medicine_setGramaj(Syrup);
    }
    break;
  case '3':
    if (type == 1) {
      Medicine_setInterval(Pill);
    } else {
      Medicine_setInterval(Syrup);
    }
    break;
  case '4':
    if (type == 1) {
      Medicine_setPret(Pill);
    } else {
      Medicine_setPret(Syrup);
    }
    break;
  case '5':
    if (type == 1) {
      Medicine_setValabilitate(Pill);
    } else {
      Medicine_setValabilitate(Syrup);
    }
    break;
  case '6':
    if (type == 1) {
      Medicine_setTinta(Pill);
    } else {
      Medicine_setTinta(Syrup);
    }
    break;
  case '7':
    if (type == 1) {
      Medicine_setScop(Pill);
    } else {
      Medicine_setScop(Syrup);
    }
    break;
  case '8':
    if (type == 1) {
      Medicine_setCuloare(Pill);
    } else {
      Medicine_setCuloare(Syrup);
    }
    break;
  case '9':
    if (type == 1) {
      Pills_setNr(Pill);
    } else {
      Syrups_setCantitate(Syrup);
    }
    break;
  case '0':
    if (type == 1) {
      Pills_setTip(Pill);
    } else {
      Syrups_setTip(Syrup);
    }
    break;
  case 'x':
  case 'X':
  case 'exit':
    return;
  default:
    cout << "Comanda invalida!";
    getch();
    break;
  }

  return Medicine_editMedicament(Pharmacy, Pill, Syrup, type);
}
void Medicine_delete(Farmacie* Pharmacy, Pastile* Pill, Sirop* Syrup) {
  char remove;
  int type = Medicine_choose();

  if ((type == 1 && !Pill->isValidMedicament()) || (type == 2 && !Syrup->isValidMedicament())) {
    cout << "Creati un medicament sau validati-l inainte de a-l sterge." << endl;
    if (type == 1) {
      cout << "Pastila invalida!";
    } else {
      cout << "Sirop invalid!";
    }
    return;
  }

  if (type == 1) {
    cout << Pill->getMedicament() << endl;
  } else {
    cout << Syrup->getMedicament() << endl;
  }

  cout << "\nSunteti sigur ca doriti sa stergeti medicamentul? (y/N): ";
  cin >> remove;

  if (tolower(remove) == 'y') {
    if (type == 1) {
      *Pill = Pastile();
    } else {
      *Syrup = Sirop();
    }
  }
}

template <typename T>
void Medicine_setDefault(T* M) {
  Medicine_setName(M);
  Medicine_setGramaj(M);
  Medicine_setInterval(M);
  Medicine_setPret(M);
  Medicine_setValabilitate(M);
  Medicine_setTinta(M);
  Medicine_setScop(M);
  Medicine_setCuloare(M);
}
/**
 * Choose Medicine
 * 1 - Pill
 * 2 - Syrup
*/
int Medicine_choose() {
  int type;

  cout << "Introduceti tipul medicamentului [1 - Pastile | 2 - Sirop]: ";
  cin >> type;

  if (std::cin.fail() || (type != 1 && type != 2)) {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return Medicine_choose();
  }
  cout << endl;
  return type;
}

// Setters
template <typename T>
void Medicine_setName(T* M) {
  std::string name;

  cout << "Introduceti numele medicamentului: ";
  cin.ignore();
  getline(cin, name, '\n');

  M->setNume(name);
}
template <typename T>
void Medicine_setInterval(T* M) {
  unsigned int interval;

  cout << "Introduceti intervalul orar de administrare: ";
  cin >> interval;

  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return Medicine_setInterval(M);
  }

  M->setInterval(interval);
}
template <typename T>
void Medicine_setGramaj(T* M) {
  unsigned int gramaj;

  cout << "Introduceti gramajul: ";
  cin >> gramaj;

  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return Medicine_setGramaj(M);
  }

  M->setGramaj(gramaj);
}
template <typename T>
void Medicine_setPret(T* M) {
  double pret;

  cout << "Introduceti pretul: ";
  cin >> pret;

  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return Medicine_setPret(M);
  }

  M->setPret(pret);
}
template <typename T>
void Medicine_setValabilitate(T* M) {
  std::string exp;

  cout << "Introduceti termenul de valabilitate (Ex: 15-01-1970): ";
  cin.ignore();
  getline(cin, exp, '\n');

  M->setValabilitate(exp);
}
template <typename T>
void Medicine_setTinta(T* M) {
  std::string tinta;

  cout << "Introduceti tinta (Copii | Adulti): ";
  getline(cin, tinta, '\n');

  M->setTinta(tinta);
}
template <typename T>
void Medicine_setScop(T* M) {
  std::string scop;

  cout << "Introduceti scopul: ";
  getline(cin, scop, '\n');

  M->setScope(scop);
}
template <typename T>
void Medicine_setCuloare(T* M) {
  std::string culoare;

  cout << "Introduceti culoarea: ";
  getline(cin, culoare, '\n');

  M->setCuloare(culoare);
}
// Pills
void Pills_setNr(Pastile* P) {
  int nr;

  cout << "Introduceti numarul de pastile: ";
  cin >> nr;

  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return Pills_setNr(P);
  }

  P->setNr(nr);
}
void Pills_setTip(Pastile* P) {
  std::string type;

  cout << "Introduceti tipul (Tablete | Flacon): ";
  cin.ignore();
  getline(cin, type, '\n');

  P->setTip(type);
}
// Syrups
void Syrups_setCantitate(Sirop* S) {
  int cantitate;

  cout << "Introduceti cantitatea: ";
  cin >> cantitate;

  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    return Syrups_setCantitate(S);
  }

  S->setCantitate(cantitate);
}
void Syrups_setTip(Sirop* S) {
  std::string type;

  cout << "Introduceti tipul (Flacon | Pliculete): ";
  cin.ignore();
  getline(cin, type, '\n');

  S->setTip(type);
}

// Getters
string Medicine_print(Farmacie* Pharmacy, Pastile* Pill, Sirop* Syrup) {
  int type = Medicine_choose();

  if ((type == 1 && !Pill->isValidMedicament()) || (type == 2 && !Syrup->isValidMedicament())) {
    return "Creati un medicament inaite de a-l afisa.";
  }

  return type == 1 ? Pill->getMedicament() : Syrup->getMedicament();
}
