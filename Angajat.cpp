#include "Angajat.h"

// Constructors
Angajat::Angajat()
{
  uuid = 0;
  grad = "unknown";
  program = 0;
  salariu = 0;
  locatie = "unknown";
}
Angajat::Angajat(unsigned int _uuid, string _grad, string _locatie, int _program, double _salariu)
{
  uuid = isValidUuid(_uuid) ? _uuid : 0;
  grad = isValidGrad(_grad) ? _grad : "unknown";
  locatie = isValidLocatie(_locatie) ? _locatie : "unknown";
  program = isValidProgram(_program) ? _program : -1;
  salariu = isValidSalariu(_salariu) ? _salariu : -1;
}

// Setters
void Angajat::setUuid(unsigned int _uuid) { uuid = isValidUuid(_uuid) ? _uuid : 0; }
void Angajat::setSalariu(double _salariu) { salariu = isValidSalariu(_salariu) ? _salariu : 0; }
void Angajat::setProgram(int _program) { program = isValidProgram(_program) ? _program : 0; }
void Angajat::setLocatie(string _locatie) { locatie = isValidLocatie(_locatie) ? _locatie : "unknown"; }
void Angajat::setGrad(string _grad) { grad = isValidGrad(_grad) ? _grad : "unkown"; }

// Getters
unsigned int Angajat::getUuid() { return uuid; }
double Angajat::getSalariu() { return salariu; }
int Angajat::getProgram() { return program; }
string Angajat::getLocatie() { return locatie; }
string Angajat::getGrad() { return grad; }

// Print
string Angajat::getPersoana()
{
  return this->getInitPersoana() +
    "uuid:\t\t" + to_string(uuid) + "\n" +
    "grad:\t\t" + grad + "\n" +
    "program:\t" + to_string(program) + "\n" +
    "salariu:\t" + getPrecision(salariu) + "\n" +
    "locatie:\t" + locatie + "\n";
}
// Validations
bool Angajat::isValidPersoana() { return this->isValidInitPersoana() && isValidSalariu(salariu) && isValidLocatie(locatie) && isValidProgram(program); }
bool Angajat::isValidUuid(unsigned int _uuid) { return _uuid > 0; }
bool Angajat::isValidSalariu(double _salariu) { return _salariu > 0; }
bool Angajat::isValidProgram(int _program) { return _program >= 4 && _program <= 8; }
bool Angajat::isValidLocatie(string _locatie) { return _locatie != "unknown" && _locatie.length() > 0; }
bool Angajat::isValidGrad(string _grad) { return _grad != "unknown" && _grad.length() > 0; }

// Auto Validate
void Angajat::autoValidate() {
  // Person auto-validate
  if (!this->isValidNume(this->getNume())) {
    this->setNume(getValidNume());
  }
  if (!this->isValidNume(this->getPrenume())) {
    this->setPrenume(getValidPrenume());
  }
  if (!this->isValidCNP(this->getCNP())) {
    this->setCNP(getValidCNP());
  }
  // Employee auto-validate
  if (!this->isValidSalariu(this->getSalariu())) {
    this->setSalariu(getValidSalariu());
  }
  if (!this->isValidProgram(this->getProgram())) {
    this->setProgram(getValidProgram());
  }
  if (!this->isValidLocatie(this->getLocatie())) {
    this->setLocatie(getValidLocation());
  }
  if (!this->isValidGrad(this->getGrad())) {
    this->setGrad(getValidGrad());
  }
}

// Generic Data #PRIVATE
double Angajat::getValidSalariu() { return 2000; }
int Angajat::getValidProgram() { return  6; }
string Angajat::getValidLocation() { return "1234 Main Street"; }
string Angajat::getValidGrad() { return "Farmacist"; }

// Destructor
Angajat::~Angajat()
{
  //dtor
}
