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
void Farmacie::setSirop(Sirop S) {
  if (!this->isValidFarmacie()) {
    cout << "Farmacia este invalida sau nu exista.";
    return;
  }
  if (!S.isValidMedicament()) {
      cout << "Siropul introdus este invalid!";
      return;
  }
  Sirop exists = findSirop(S.getNume());

  if (exists.isValidMedicament()) {
    cout << "Exista deja un medicament cu numele: " << S.getNume() << endl;
    return;
  }

  int total = getLengthMedicament(pastile);
  int index = getLengthMedicament(siropuri) + total;

  if (index <= -1 || index > depozitSize) {
    cout << "Spatiu insuficient.";
    return;
  }

  siropuri[index] = S;

  cout << "Medicamentul a fost adaugat cu succes.";
}
void Farmacie::setPastile(Pastile P) {
  if (!this->isValidFarmacie()) {
    cout << "Farmacia este invalida sau nu exista.";
    return;
  }
  if (!P.isValidMedicament()) {
    cout << "Pastilele introduse sunt invalide!";
    return;
  }
  Pastile exists = findPastile(P.getNume());

  if (exists.isValidMedicament()) {
    cout << "Exista deja un medicament cu numele: " << P.getNume() << endl;
    return;
  }

  int total = getLengthMedicament(siropuri);
  int index = getLengthMedicament(pastile) + total;

  if (index <= -1 || index > depozitSize) {
    cout << "Spatiu insuficient.";
    return;
  }

  pastile[index] = P;

  cout << "Medicamentul a fost adaugat cu succes.";
}
void Farmacie::setAngajat(Angajat A) {
  if (!this->isValidFarmacie()) {
    cout << "Farmacia este invalida sau nu exista.";
    return;
  }
  if (!A.isValidPersoana()) {
    cout << "Angajatul introdus este invalid!";
    return;
  }
  Angajat exists = findAngajat(A.getCNP());

  if (exists.isValidPersoana()) {
    cout << "Exista deja un angajat cu CNP-ul: " << A.getCNP() << endl;
    return;
  }

  int index = getLengthPersonal(angajati, true);

  if (index == -1) {
    cout << "Spatiu insuficient.";
    return;
  }

  angajati[index] = A;

  cout << "Angajatul a fost adaugat cu succes.";
}
void Farmacie::setClient(Client C) {
  if (!this->isValidFarmacie()) {
    cout << "Farmacia este invalida sau nu exista.";
    return;
  }
  if (!C.isValidPersoana()) {
    cout << "Clientul introdus este invalid!";
    return;
  }
  Client exists = findClient(C.getCNP());

  if (exists.isValidPersoana()) {
    cout << "Exista deja un client cu CNP-ul: " << C.getCNP() << endl;
    return;
  }

  int index = getLengthPersonal(clienti);

  if (index == -1) {
    cout << "Spatiu insuficient.";
    return;
  }

  clienti[index] = C;

  cout << "Clientul a fost adaugat cu succes.";
}
void Farmacie::setDepozitSize(int _dSize) { depozitSize = isValidDSize(_dSize) ? _dSize : S_MAX + P_MAX; }
void Farmacie::setPersonalSize(int _pSize) { personalSize = isValidPSize(_pSize) ? _pSize : A_MAX; }
void Farmacie::setRemove(bool _remove) { isRemoved = _remove; }

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

// Find
Pastile Farmacie::findPastile(string _name) {
  for(int i = 0; i < depozitSize; i++) {
      if (!pastile[i].isValidMedicament()) {
        break;
      }

      if (this->customCap(_name) == this->customCap(pastile[i].getNume())) {
        return pastile[i];
      }
    }
    return Pastile(); // Not found
}
Sirop Farmacie::findSirop(string _name) {
  for(int i = 0; i < depozitSize; i++) {
    if (!siropuri[i].isValidMedicament()) {
      break;
    }

    if (this->customCap(_name) == this->customCap(siropuri[i].getNume())) {
      return siropuri[i];
    }
  }

  return Sirop(); // Not found
}
Angajat Farmacie::findAngajat(unsigned long long int _CNP) {
  for(int i = 0; i < personalSize; i++) {
    if (!angajati[i].isValidPersoana()) {
      break;
    }

    if (_CNP == angajati[i].getCNP()) {
      return angajati[i];
    }
  }
  return Angajat(); // Not found
}
Client Farmacie::findClient(unsigned long long int _CNP) {
  for(int i = 0; i < C_MAX; i++) {
    if (!clienti[i].isValidPersoana()) {
      break;
    }

    if (_CNP == clienti[i].getCNP()) {
      return clienti[i];
    }
  }
  return Client(); // Not found
}

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

// Utils

// Destructor
Farmacie::~Farmacie()
{
    //dtor
}
