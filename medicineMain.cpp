// Classes
#include "Farmacie.h"
#include "Sirop.h"
#include "Pastile.h"

using namespace std;

// Main Functions
void Medicine_create(Farmacie*, Pastile*, Sirop*);
void Medicine_add(App*, Farmacie*, Pastile*, Sirop*);
void Medicine_edit(App*, Farmacie*, Pastile*, Sirop*);
void Medicine_editMedicament(App*, Farmacie*, Pastile*, Sirop*, int);
void Medicine_delete(Farmacie*, Pastile*, Sirop*);
// Farmacie
void Medicine_findD(App*, Farmacie*, Pastile*, Sirop*);
void Medicine_editD(App*, Farmacie*, Pastile*, Sirop*);
void Medicine_deleteD(App*, Farmacie*, Pastile*, Sirop*);

template <typename T>
void Medicine_setDefault(T*);
int Medicine_choose();
string Medicine_getName();

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
  // Initiate component
  Application->setCurrentComponent("Medicine");

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
         << "5. Adaugare in depozit\n"
         << "6. Cautare in depozit\n"
         << "7. Editare din depozit\n"
         << "8. Stergere din depozit\n"
         << "X. Meniul principal\n\n";

    cout << "Alegeti optiunea: ";
    cin >> opt;
    switch (toupper(opt))
    {
    case '1':
      cout << Application->getHeader();
      cout << "1. Creare medicament\n\n";
      Medicine_create(Pharmacy, Pill, Syrup);
      if (Application->getAutoValidare()) {
        Pill->autoValidate();
        Syrup->autoValidate();
      }
      getch();
      break;
    case '2':
      if (Application->getAutoValidare()) {
        Pill->autoValidate();
        Syrup->autoValidate();
      }
      Medicine_edit(Application, Pharmacy, Pill, Syrup);
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
      Medicine_add(Application, Pharmacy, Pill, Syrup);
      getch();
      break;
    case '6':
      cout << Application->getHeader();
      cout << "6. Cautare medicament in depozit\n\n";
      Medicine_findD(Application, Pharmacy, Pill, Syrup);
      getch();
      break;
    case '7':
      cout << Application->getHeader();
      cout << "7. Editare medicament din depozit\n\n";
      Medicine_editD(Application, Pharmacy, Pill, Syrup);
      if (Application->getAutoValidare()) {
        Pill->autoValidate();
        Syrup->autoValidate();
      }
      getch();
      break;
    case '8':
      cout << Application->getHeader();
      cout << "8. Stergere medicament din depozit\n\n";
      Medicine_deleteD(Application, Pharmacy, Pill, Syrup);
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

    if (!Pill->isValidMedicament()) {
      cout << "\nMedicamentul a fost creat, dar este invalid.";
    } else {
      cout << "\nMedicamentul a fost creat cu succes.";
    }
  } else {
    Medicine_setDefault(Syrup);
    Syrups_setCantitate(Syrup);
    Syrups_setTip(Syrup);

    if (!Syrup->isValidMedicament()) {
      cout << "\nMedicamentul a fost creat, dar este invalid.";
    } else {
      cout << "\nMedicamentul a fost creat cu succes.";
    }
  }

  // Save the changes
  // Pharmacy->
}
void Medicine_add(App* Application, Farmacie* Pharmacy, Pastile* Pill, Sirop* Syrup) {
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

  // Auto-save
  if (Application->getAutoSave()) {
    Pharmacy->saveEntity();
  }
}
void Medicine_edit(App* Application, Farmacie* Pharmacy, Pastile* Pill, Sirop* Syrup) {
  int type = Medicine_choose();

  Medicine_editMedicament(Application, Pharmacy, Pill, Syrup, type);
}
void Medicine_editMedicament(App* Application, Farmacie* Pharmacy, Pastile* Pill, Sirop* Syrup, int type) {
  char opt;

  cout << Application->getHeader();
  cout << "2. Editare medicament; tipul selectat: ";
  if (type == 1) {
    cout << "Pastile (" << Pill->getNume() << ")\n\n";
    cout << Pill->getMedicament() << "\n\n";
  } else {
    cout << "Sirop (" << Syrup->getNume() << ")\n\n";
    cout << Syrup->getMedicament() << "\n\n";
  }
  cout << "1. Editeaza numele\n"
       << "2. Editeaza gramajul\n"
       << "3. Editeaza tinta (Copii | Adulti)\n"
       << "4. Editeaza scopul\n"
       << "5. Editeaza pretul\n"
       << "6. Editeaza intervalul orar\n"
       << "7. Editeaza termenul de valabilitate\n";
  if (type == 1) {
    cout << "8. Editeaza numarul de pastile\n";
  } else {
    cout << "8. Editeaza cantitatea\n";
  }
  cout << "9. Editeaza tipul ambalajului\n"
       << "0. Editeaza culoarea\n"
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
      Medicine_setTinta(Pill);
    } else {
      Medicine_setTinta(Syrup);
    }
    break;
  case '4':
    if (type == 1) {
      Medicine_setScop(Pill);
    } else {
      Medicine_setScop(Syrup);
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
      Medicine_setInterval(Pill);
    } else {
      Medicine_setInterval(Syrup);
    }
    break;
  case '7':
    if (type == 1) {
      Medicine_setPret(Pill);
    } else {
      Medicine_setPret(Syrup);
    }
    break;
  case '8':
    if (type == 1) {
      Pills_setNr(Pill);
    } else {
      Syrups_setCantitate(Syrup);
    }
    break;
  case '9':
    if (type == 1) {
      Pills_setTip(Pill);
    } else {
      Syrups_setTip(Syrup);
    }
    break;
  case '0':
    if (type == 1) {
      Medicine_setCuloare(Pill);
    } else {
      Medicine_setCuloare(Syrup);
    }
    break;
  case 'x':
  case 'X':
    return;
  default:
    cout << "Comanda invalida!";
    getch();
    break;
  }

  return Medicine_editMedicament(Application, Pharmacy, Pill, Syrup, type);
}
void Medicine_delete(Farmacie* Pharmacy, Pastile* Pill, Sirop* Syrup) {
  std::string remove;
  std::string medicineName;
  int type = Medicine_choose();

  if (type == 1) {
    cout << "\n" << Pill->getMedicament();
    medicineName = Pill->getNume();
  } else {
    cout << "\n" << Syrup->getMedicament();
    medicineName = Syrup->getNume();
  }

  cout << "\n\n"
       << "Pentru a sterge introduceti numele medicamentului: ";
  cin >> remove;

  if (Pharmacy->customCap(remove) == Pharmacy->customCap(medicineName)) {
    if (type == 1) {
      *Pill = Pastile();
    } else {
      *Syrup = Sirop();
    }

    cout << "Clientul a fost sters cu succes.";
    return;
  }

  cout << "Numele introdus nu corespunde.";
}
// Farmacie
void Medicine_findD(App* Application, Farmacie* Pharmacy, Pastile* Pill, Sirop* Syrup) {
  char allow;

  if (!Pharmacy->isValidFarmacie()) {
    cout << "Farmacia este invalida sau nu exista.";
    return;
  }
  cout << "WARNING: Aceasta actiune va sterge medicamentul curent! Continuati? (y/N): ";
  cin >> allow;
  if (toupper(allow) == 'N') {
    return;
  }

  Pastile SecondPill;
  Sirop SecondSyrup;
  int type = Medicine_choose();
  int index;

  if (type == 1) {
    // Pills
    index = Pharmacy->findIndexPastile(Medicine_getName());
    SecondPill = Pharmacy->findPastile(index);

    if (!SecondPill.isValidMedicament()) {
      cout << "Medicamentul nu a fost gasit.";
      return;
    }

    cout << "\nMedicamentul gasit:\n\n" << SecondPill.getMedicament() << "\n\n";
    *Pill = SecondPill;
  } else {
    // Syropus
    index = Pharmacy->findIndexSirop(Medicine_getName());
    SecondSyrup = Pharmacy->findSirop(index);

    if (!SecondSyrup.isValidMedicament()) {
      cout << "Medicamentul nu a fost gasit.";
      return;
    }

    cout << "\nMedicamentul gasit:\n\n" << SecondSyrup.getMedicament() << "\n\n";
    *Syrup = SecondSyrup;
  }
}
void Medicine_editD(App* Application, Farmacie* Pharmacy, Pastile* Pill, Sirop* Syrup) {
  if (!Pharmacy->isValidFarmacie()) {
    cout << "Farmacia este invalida sau nu exista.";
    return;
  }

  Pastile SecondPill;
  Sirop SecondSyrup;
  int type = Medicine_choose();
  int index;

  if (type == 1) {
    // Pills
    index = Pharmacy->findIndexPastile(Medicine_getName());
    SecondPill = Pharmacy->findPastile(index);

    if (!SecondPill.isValidMedicament()) {
      cout << "Medicamentul nu a fost gasit.";
      return;
    }

    Medicine_editMedicament(Application, Pharmacy, &SecondPill, &SecondSyrup, type);
    Pharmacy->setPastile(SecondPill, index);
  } else {
    // Syropus
    index = Pharmacy->findIndexSirop(Medicine_getName());
    SecondSyrup = Pharmacy->findSirop(index);

    if (!SecondSyrup.isValidMedicament()) {
      cout << "Medicamentul nu a fost gasit.";
      return;
    }

    Medicine_editMedicament(Application, Pharmacy, &SecondPill, &SecondSyrup, type);
    Pharmacy->setSirop(SecondSyrup, index);
  }

  // Auto-save
  if (Application->getAutoSave()) {
    Pharmacy->saveEntity();
  }
}
void Medicine_deleteD(App* Application, Farmacie* Pharmacy, Pastile* Pill, Sirop* Syrup) {
  if (!Pharmacy->isValidFarmacie()) {
    cout << "Farmacia este invalida sau nu exista.";
    return;
  }

  Pastile SecondPill;
  Sirop SecondSyrup;
  int type = Medicine_choose();
  int removeIndex;
  char remove;

  if (type == 1) {
    // Pills
    removeIndex = Pharmacy->findIndexPastile(Medicine_getName());
    SecondPill = Pharmacy->findPastile(removeIndex);

    if (!SecondPill.isValidMedicament()) {
      cout << "Medicamentul nu a fost gasit.";
      return;
    }

    cout << "\nMedicamentul gasit:\n"
         << SecondPill.getMedicament() << "\n"
         << "Doriti sa-l stergeti? (y/N): ";
    cin >> remove;

    if (toupper(remove) == 'N') {
      return;
    }

    // Remove the item from deposit
    Pharmacy->removePastile(removeIndex);
  } else {
    // Syropus
    removeIndex = Pharmacy->findIndexPastile(Medicine_getName());
    SecondSyrup = Pharmacy->findSirop(removeIndex);

    if (!SecondSyrup.isValidMedicament()) {
      cout << "Medicamentul nu a fost gasit.";
      return;
    }

    cout << "\nMedicamentul gasit:\n"
         << SecondSyrup.getMedicament() << "\n"
         << "Doriti sa-l stergeti? (y/N): ";
    cin >> remove;

    if (toupper(remove) == 'N') {
      return;
    }

    // Remove the item from deposit
    Pharmacy->removeSirop(removeIndex);
  }
  cout << "Medicamentul a fost sters cu succes.";

  // Auto-save
  if (Application->getAutoSave()) {
    Pharmacy->saveEntity();
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
string Medicine_getName() {
  string name;

  cout << "Introduceti numele medicamentului: ";
  cin.clear();
  cin.ignore();
  getline(cin, name, '\n');

  return name;
}

// Setters
template <typename T>
void Medicine_setName(T* M) {
  std::string name;

  cout << "Introduceti numele medicamentului: ";
  cin.clear();
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
  cin.clear();
  cin.ignore();
  getline(cin, exp, '\n');

  M->setValabilitate(exp);
}
template <typename T>
void Medicine_setTinta(T* M) {
  std::string tinta;

  cout << "Introduceti tinta (Copii | Adulti): ";
  cin.clear();
  cin.ignore();
  getline(cin, tinta, '\n');

  M->setTinta(tinta);
}
template <typename T>
void Medicine_setScop(T* M) {
  std::string scop;

  cout << "Introduceti scopul: ";
  cin.clear();
  cin.ignore();
  getline(cin, scop, '\n');

  M->setScope(scop);
}
template <typename T>
void Medicine_setCuloare(T* M) {
  std::string culoare;

  cout << "Introduceti culoarea: ";
  cin.clear();
  // cin.ignore();
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
  cin.clear();
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
  cin.clear();
  cin.ignore();
  getline(cin, type, '\n');

  S->setTip(type);
}

// Getters
string Medicine_print(Farmacie* Pharmacy, Pastile* Pill, Sirop* Syrup) {
  return Medicine_choose() == 1 ? Pill->getMedicament() : Syrup->getMedicament();
}
