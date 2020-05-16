#include "Angajat.h"

// Constructors
Angajat::Angajat()
{
  uuid = 0;
  grad = "undefined";
  program = 0;
  salariu = 0;
  locatie = "undefined";
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
    "uuid:\t" + to_string(uuid) + "\ngrad:\t" + grad + "\nprogram:\t" + to_string(program) +
    "\nsalariu:\t" + to_string(salariu) + "\nlocatie:\t" + locatie;
}
// Validations
bool Angajat::isValidUuid(unsigned int _uuid) { return _uuid > 0; }
bool Angajat::isValidSalariu(double _salariu) { return _salariu > 0; }
bool Angajat::isValidProgram(int _program) { return _program == 4 || _program == 6 || _program == 8; }
bool Angajat::isValidLocatie(string _locatie) { return _locatie.length() > 0; }
bool Angajat::isValidGrad(string _grad) { return _grad == "intern" || _grad == "sef" || _grad == "farmacist"; } // To work on it

// Destructor
Angajat::~Angajat()
{
  //dtor
}
