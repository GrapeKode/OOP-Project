#include "Persoana.h"

// Constructors
Persoana::Persoana()
{
  nume = "unknown";
  prenume = "unknown";
  CNP = 0;
}
Persoana::Persoana(string _nume, string _prenume, unsigned long long int _CNP)
{
  nume = isValidNume(_nume) ? _nume : "unknown";
  prenume = isValidNume(_prenume) ? _prenume : "unknown";
  CNP = isValidCNP(_CNP) ? _CNP : 0;
}

// Setters
void Persoana::setNume(string _nume) { nume = isValidNume(_nume) ? _nume : "unknown"; }
void Persoana::setPrenume(string _prenume) { prenume = isValidNume(_prenume) ? _prenume : "unknown"; }
void Persoana::setCNP(unsigned long long int _CNP) { CNP = isValidCNP(_CNP) ? _CNP : 0; }

// Getters
string Persoana::getNume() { return nume; }
string Persoana::getPrenume() { return prenume; }
unsigned long long int Persoana::getCNP() { return CNP; }

// Print
string Persoana::getInitPersoana() { return "Nume:\t\t" + prenume + " " + nume + "\nCNP:\t\t" + to_string(CNP) + "\n"; }

// Validations
bool Persoana::isValidNume(string _nume) { return _nume.length() > 0; }
bool Persoana::isValidCNP(unsigned long long int _CNP) { return to_string(_CNP).length() == 13; }
bool Persoana::isValidInitPersoana() { return isValidNume(nume) && isValidNume(prenume) && isValidCNP(CNP); }

// Destructor
Persoana::~Persoana()
{
  //dtor
}
