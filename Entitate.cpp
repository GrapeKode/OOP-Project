#include "Entitate.h"

// Constructor
Entitate::Entitate()
{
  nume = "unknown";
  locatie = "unknown";
  uuid = -1;
}

Entitate::Entitate(int _uuid, string _nume, string _locatie)
{
  uuid = _uuid;
  nume = _nume;
  locatie = _locatie;
}

// Setters
void Entitate::setId(int _uuid) { uuid = _uuid; }
void Entitate::setNume(string _name) { nume = _name; }
void Entitate::setLocatie(string _locatie) { locatie = _locatie; }

// Getters
int Entitate::getId() { return uuid; }
string Entitate::getNume() { return nume; }
string Entitate::getLocatie() { return locatie; }
string Entitate::getInitEntitate()
{
  return "Id:\t\t" + to_string(this->uuid) + "\n" +
         "Nume:\t\t" + this->nume + "\n" +
         "Locatie:\t" + this->locatie + "\n";
}

// Validation
bool Entitate::isValidEntity() { return isValidId(uuid) && isValidNume(nume) && isValidLocatie(locatie); }
bool Entitate::isValidId(int _uuid) { return _uuid > -1; }
bool Entitate::isValidNume(string _nume) { return _nume != "unknown" && _nume.length() > 0; }
bool Entitate::isValidLocatie(string _locatie) { return _locatie != "unknown" && _locatie.length() > 0; }

// Generic Data $PROTECTED
int Entitate::getValidId() { return 9000; }
string Entitate::getValidNume() { return "Generic nume"; }
string Entitate::getValidLocatie() { return "Generic locatie"; }

// Destructor
Entitate::~Entitate()
{
  //dtor
}
