#include "Farmacie.h"

// Constructor
Farmacie::Farmacie() {
  siropuri = new Sirop[S_MAX];
  pastile = new Pastile[P_MAX];
  angajati = new Angajat[A_MAX];
  clienti = new Client[C_MAX];
  depozitSize = S_MAX + P_MAX;
  personalSize = A_MAX;
  isRemoved = false;
}
Farmacie::Farmacie(Sirop S, Pastile P, int _dSize) {
  this->setSirop(S);
  this->setPastile(P);
  this->setDepozitSize(_dSize);
  this->setRemove(false);
}
Farmacie::Farmacie(Angajat A, Client C, int _pSize) {
  this->setAngajat(A);
  this->setClient(C);
  this->setPersonalSize(_pSize);
  this->setRemove(false);
}
Farmacie::Farmacie(Sirop S, Pastile P, Angajat A, Client C, int _dSize, int _pSize) {
  this->setSirop(S);
  this->setPastile(P);
  this->setDepozitSize(_dSize);

  this->setAngajat(A);
  this->setClient(C);
  this->setPersonalSize(_pSize);

  this->setRemove(false);
}

// Setters
void Farmacie::setSirop(Sirop S, int itemIndex) {
  if (!this->isValidFarmacie()) {
    cout << "Farmacia este invalida sau nu exista.";
    return;
  }
  if (!S.isValidMedicament()) {
      cout << "Siropul introdus este invalid!";
      return;
  }
  int exists = findIndexSirop(S.getNume());

  if (exists > -1 && itemIndex == -1) {
    cout << "Exista deja un medicament cu numele: " << S.getNume() << endl;
    return;
  }

  int total = getLengthMedicament(pastile);
  int index = getLengthMedicament(siropuri);

  // Set specific index
  if (itemIndex > -1) {
    index = itemIndex;
  }

  if (itemIndex == -1 && (index <= -1 || index + total >= depozitSize)) {
    cout << "Spatiu insuficient.";
    return;
  }

  siropuri[index] = S;

  if (itemIndex == -1) {
    cout << "Medicamentul a fost adaugat cu succes.";
  } else {
    cout << "Medicamentul a fost editat cu succes.";
  }
}
void Farmacie::setPastile(Pastile P, int itemIndex) {
  if (!this->isValidFarmacie()) {
    cout << "Farmacia este invalida sau nu exista.";
    return;
  }
  if (!P.isValidMedicament()) {
    cout << "Pastilele introduse sunt invalide!";
    return;
  }
  int exists = findIndexPastile(P.getNume());

  if (exists > -1 && itemIndex == -1) {
    cout << "Exista deja un medicament cu numele: " << P.getNume() << endl;
    return;
  }

  int total = getLengthMedicament(siropuri);
  int index = getLengthMedicament(pastile);

  // Set specific index
  if (itemIndex > -1) {
    index = itemIndex;
  }

  if (itemIndex == -1 && (index <= -1 || index + total >= depozitSize)) {
    cout << "Spatiu insuficient.";
    return;
  }

  pastile[index] = P;

  if (itemIndex == -1) {
    cout << "Medicamentul a fost adaugat cu succes.";
  } else {
    cout << "Medicamentul a fost editat cu succes.";
  }
}
void Farmacie::setAngajat(Angajat A, int itemIndex) {
  if (!this->isValidFarmacie()) {
    cout << "Farmacia este invalida sau nu exista.";
    return;
  }
  if (!A.isValidPersoana()) {
    cout << "Angajatul introdus este invalid!";
    return;
  }
  int exists = findIndexAngajat(A.getCNP());

  if (exists > -1 && itemIndex == -1) {
    cout << "Exista deja un angajat cu CNP-ul: " << A.getCNP() << endl;
    return;
  }

  int index = getLengthPersonal(angajati, true);

  // Set specific index
  if (itemIndex > -1) {
    index = itemIndex;
  }

  if (itemIndex == -1 && (index <= -1 || index > personalSize)) {
    cout << "Spatiu insuficient.";
    return;
  }

  angajati[index] = A;

  if (itemIndex == -1) {
    cout << "Angajatul a fost adaugat cu succes.";
  } else {
    cout << "Angajatul a fost editat cu succes.";
  }
}
void Farmacie::setClient(Client C, int itemIndex) {
  if (!this->isValidFarmacie()) {
    cout << "Farmacia este invalida sau nu exista.";
    return;
  }
  if (!C.isValidPersoana()) {
    cout << "Clientul introdus este invalid!";
    return;
  }
  int exists = findIndexClient(C.getCNP());

  if (exists > -1 && itemIndex == -1) {
    cout << "Exista deja un client cu CNP-ul: " << C.getCNP() << endl;
    return;
  }

  int index = getLengthPersonal(clienti);

  // Set specific index
  if (itemIndex > -1) {
    index = itemIndex;
  }

  if (index <= -1 && itemIndex == -1) {
    cout << "Spatiu insuficient.";
    return;
  }

  clienti[index] = C;

  if (itemIndex == -1) {
    cout << "Clientul a fost adaugat cu succes.";
  } else {
    cout << "Clientul a fost editat cu succes.";
  }
}
void Farmacie::setDepozitSize(int _dSize) { depozitSize = isValidDSize(_dSize) ? _dSize : S_MAX + P_MAX; }
void Farmacie::setPersonalSize(int _pSize) { personalSize = isValidPSize(_pSize) ? _pSize : A_MAX; }
void Farmacie::setRemove(bool _remove) { isRemoved = _remove; }
// Remove
void Farmacie::removeSirop(int _index) {
  for (int i = _index + 1; i < depozitSize; i++) {
    siropuri[i-1] = siropuri[i];
    siropuri[i] = Sirop();
  }
}
void Farmacie::removePastile(int _index) {
  bool stopExc = false;
  for (int i = _index + 1; i < depozitSize; i++) {
    if (stopExc) { break; }
    pastile[i-1] = pastile[i];
    if (!pastile[i].isValidMedicament()) { break; }
    // pastile[i] = Pastile();
  }
}
void Farmacie::removeAngajat(int _index) {
  for (int i = _index + 1; i < personalSize; i++) {
    angajati[i-1] = angajati[i];
    angajati[i] = Angajat();
  }
}
void Farmacie::removeClient(int _index) {
  for (int i = _index + 1; i < C_MAX; i++) {
    clienti[i-1] = clienti[i];
    clienti[i] = Client();
  }
}

// Getters
Sirop* Farmacie::getSirop() { return siropuri; }
Pastile* Farmacie::getPastile() { return pastile; }
Angajat* Farmacie::getAngajati() { return angajati; }
Client* Farmacie::getClienti() { return clienti; }
int Farmacie::getDepozitSize() { return depozitSize; }
int Farmacie::getPersonalSize() { return personalSize; }
bool Farmacie::isRemovedEntity() { return isRemoved; }
// Get size
template <typename T>
int Farmacie::getLengthMedicament(T M) {
  for (int i = 0; i < depozitSize; i++) {
    if (!M[i].isValidMedicament()) {
      return i;
    }
  }

  return -1; // Depozit full
}
template <typename T>
int Farmacie::getLengthPersonal(T P, bool employee) {
  for (int i = 0; i < (employee ? personalSize : C_MAX); i++) {
    if (!P[i].isValidPersoana()) {
      return i;
    }
  }

  return -1; // Personal full
}
//
int Farmacie::getLengthPastile() {
  int index = getLengthMedicament(pastile);

  if (index <= -1 || index > depozitSize) {
    return depozitSize;
  }

  return index;
}
int Farmacie::getLengthSiropuri() {
  int index = getLengthMedicament(siropuri);

  if (index <= -1 || index > depozitSize) {
    return depozitSize;
  }

  return index;
}
int Farmacie::getLengthAngajati() {
  int index = getLengthPersonal(angajati, true);

  if (index == -1 || index > personalSize) {
    return personalSize;
  }

  return index;
}
int Farmacie::getLengthClienti() {
  int index = getLengthPersonal(clienti);

  return index;
}

// Index
int Farmacie::findIndexPastile(string _name) {
  for(int i = 0; i < depozitSize; i++) {
    if (!pastile[i].isValidMedicament()) {
      break;
    }

    if (this->customCap(_name) == this->customCap(pastile[i].getNume())) {
      return i;
    }
  }
  return -1; // Not found
}
int Farmacie::findIndexSirop(string _name) {
  for(int i = 0; i < depozitSize; i++) {
    if (!siropuri[i].isValidMedicament()) {
      break;
    }

    if (this->customCap(_name) == this->customCap(siropuri[i].getNume())) {
      return i;
    }
  }

  return -1; // Not found
}
int Farmacie::findIndexAngajat(unsigned long long int _CNP) {
  for(int i = 0; i < personalSize; i++) {
    if (!angajati[i].isValidPersoana()) {
      break;
    }

    if (_CNP == angajati[i].getCNP()) {
      return i;
    }
  }
  return -1; // Not found
}
int Farmacie::findIndexClient(unsigned long long int _CNP) {
  for(int i = 0; i < C_MAX; i++) {
    if (!clienti[i].isValidPersoana()) {
      break;
    }

    if (_CNP == clienti[i].getCNP()) {
      return i;
    }
  }
  return -1; // Not found
}
// Get Item
Pastile Farmacie::findPastile(int _index) { return pastile[_index]; }
Sirop Farmacie::findSirop(int _index) { return siropuri[_index]; }
Angajat Farmacie::findAngajat(int _index) { return angajati[_index]; }
Client Farmacie::findClient(int _index) { return clienti[_index]; }

// Print
string Farmacie::printEntitate() {
  return this->getInitEntitate() +
    "Medicamente:\t" + to_string(getLengthPastile() + getLengthSiropuri()) + " / " + to_string(depozitSize) + "\n" +
    "Angajati:\t" + to_string(getLengthAngajati()) + " / " + to_string(personalSize) + "\n" +
    "Cienti:\t\t" + to_string(getLengthClienti()) + "\n\n";
}
template <typename T>
string Farmacie::printMedicamente(T M) {
  int length = getLengthMedicament(M);
  string result;

  if (length == 0) {
    return "Nu exista medicamente";
  }

  for (int i = 0; i < length; i++) {
    result += "Medicamentul [ " + to_string(i + 1) + " ]\n";
    result += M[i].getMedicament() + "\n";
  }

  return result;
}
template <typename T>
string Farmacie::printPersoane(T P) {
  int length = getLengthPersonal(P);
  string result;

  if (length == 0) {
    return "Nu exista persoane inregistrate";
  }

  for (int i = 0; i < length; i++) {
    result += "Persoana Nr. " + to_string(i + 1) + "\n";
    result += P[i].getPersoana() + "\n";
  }

  return result;
}
//
string Farmacie::printPastile() { return this->printMedicamente(pastile); }
string Farmacie::printSiropuri() { return this->printMedicamente(siropuri); }
string Farmacie::printAngajati() { return this->printPersoane(angajati); }
string Farmacie::printClienti() { return this->printPersoane(clienti); }

// Validations
bool Farmacie::isValidFarmacie() { return !isRemoved && this->isValidEntity(); }
bool Farmacie::isValidDSize(int _dSize) { return _dSize > 0; }
bool Farmacie::isValidPSize(int _pSize) { return _pSize > 0; }

// Auto validate
void Farmacie::autoValidate() {
  if (!this->isValidId(this->getId())) {
    this->setId(getValidId());
  }
  if (!this->isValidNume(this->getNume())) {
    this->setNume(getValidNume());
  }
  if (!this->isValidLocatie(this->getLocatie())) {
    this->setLocatie(getValidLocatie());
  }
}
// Auto salvare
void Farmacie::autoSave() {}

// Save & Load
bool Farmacie::saveEntity(bool sleep) {
  if (!this->mkdir(getNume())) {
    cout << "\n\nWARNING: Nu s-a putut crea folder-ul `" << getNume() << "`. Asigurati-va ca programul are permisiunea de a crea.";
    return false;
  }
  string path = getNume() + "\\";
  ofstream entityFile, medicineFile, employeeFile, clientFile;

  // Entity
  entityFile.open(path + "entitate.txt");
  entityFile << printEntitate();
  entityFile.close();

  // Medicines
  medicineFile.open(path + "medicamente.txt");
  medicineFile << printMedicamente(pastile) + "\n" + printMedicamente(siropuri);
  medicineFile.close();

  // Employees
  employeeFile.open(path + "angajati.txt");
  employeeFile << printAngajati();
  employeeFile.close();

  // Clients
  clientFile.open(path + "clienti.txt");
  clientFile << printClienti();
  clientFile.close();

  if (sleep) {
    cout << "\nINFO: Se salveaza datele...";
    this->Sleep(500);
    cout << "\nINFO: Datele au fost salvate in folder-ul `" << getNume() << "`.";
  } else {
    cout << "\nINFO: Salvata automat.";
  }

  return true;
}
bool Farmacie::importEntity() {
  cout << "WARNING: Functionalitatea importatii unei entitati nu a fost creata."
       << " Pentru mai multe detalii contactati persoana responsabila.\n"
       << "INFO: Datele despre persoana responsabila le gasiti in meniul principal la sectiunea `Info`."
       << "\n\n";
}

// Utils

// Destructor
Farmacie::~Farmacie()
{
    //dtor
}
