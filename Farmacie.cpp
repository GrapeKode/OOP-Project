#include "Farmacie.h"

// Constructor
Farmacie::Farmacie() {
  siropuri = new Sirop[S_MAX];
  pastile = new Pastile[P_MAX];
  angajati = new Angajat[A_MAX];
  clienti = new Client[C_MAX];
  depozitSize = S_MAX + P_MAX;
  personalSize = A_MAX + C_MAX;
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
  if (!S.isValidMedicament()) {
      cout << "Siropul introdus este invalid!";
      return;
  }

  int index = getLengthMedicament(siropuri);

  if (index == -1) {
    cout << "Spatiu insuficient.";
    return;
  }

  siropuri[index] = S;
}
void Farmacie::setPastile(Pastile P) {
  if (!P.isValidMedicament()) {
    cout << "Pastilele introduse sunt invalide!";
    return;
  }

  int index = getLengthMedicament(pastile);

  if (index == -1) {
    cout << "Spatiu insuficient.";
    return;
  }

  pastile[index] = P;
}
void Farmacie::setAngajat(Angajat A) {
  if (!A.isValidPersoana()) {
    cout << "Angajatul introdus este invalid!";
    return;
  }

  int index = getLengthPersonal(angajati);

  if (index == -1) {
    cout << "Spatiu insuficient.";
    return;
  }

  angajati[index] = A;
}
void Farmacie::setClient(Client C) {
  if (!C.isValidPersoana()) {
    cout << "Clientul introdus este invalid!";
    return;
  }

  int index = getLengthPersonal(clienti);

  if (index == -1) {
    cout << "Spatiu insuficient.";
    return;
  }

  clienti[index] = C;
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
int Farmacie::getLengthPersonal(T P) {
  for (int i = 0; i < personalSize + C_MAX; i++) {
    if (!P[i].isValidPersoana()) {
      return i;
    }
  }

  return -1; // Personal full
}

// Print
string Farmacie::getEntitate() {
  if (!isValidFarmacie()) {
    return "Creati o entitate inainte.";
  }

  string result = this->getInitEntitate() +
    "Numarul de medicamente:\t\t" + to_string(getLengthMedicament(siropuri) + getLengthMedicament(pastile)) + " / " + to_string(depozitSize) + "\n" +
    "Numarul de angajati:\t\t" + to_string(getLengthPersonal(angajati)) + " / " + to_string(personalSize) + "\n" +
    "Numarul de cienti inregistrati:\t" + to_string(getLengthPersonal(clienti)) + "\n\n" +
    "\n-------------------------------------- Siropuri -------------------------------------" +
    "\n\n" + printMedicamente(siropuri) + "\n" +
    "\n-------------------------------------- Pastile --------------------------------------" +
    "\n\n" + printMedicamente(pastile) + "\n\n" +
    "\n-------------------------------------- Angajati -------------------------------------" +
    "\n\n" + printPersoane(angajati) + "\n" +
    "\n-------------------------------------- Clienti --------------------------------------" +
    "\n\n" + printPersoane(clienti) + "\n";

  return result;
}
template <typename T>
string Farmacie::printMedicamente(T M) {
  int length = getLengthMedicament(M);
  string result;

  if (length == 0) {
    return "Nu exista medicamente";
  }

  for (int i = 0; i < length; i++) {
    result += "Medicamentul Nr. " + to_string(i + 1) + "\n";
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

// Validations
bool Farmacie::isValidFarmacie() { return !isRemoved && this->isValidEntity(); }
bool Farmacie::isValidDSize(int _dSize) { return _dSize > 0; }
bool Farmacie::isValidPSize(int _pSize) { return _pSize > 0; }

//template <typename T>
//bool Farmacie::isEmpty(T* M) { return getLe }

// Utils

// Destructor
Farmacie::~Farmacie()
{
    //dtor
}
