#include "Medicament.h"

// Constructor
Medicament::Medicament()
{
  interval = 0;
  gramaj = 0;
  pret = 0;
  valabilitate = "15-01-1970";
  tinta = "unknown";
  scop = "unknown";
  nume = "unknown";
}
Medicament::Medicament(unsigned int _interval, unsigned int _gramaj, double _pret, string _nume, string _valabilitate, string _tinta, string _scop)
{
  this->setNume(_nume);
  this->setInterval(_interval);
  this->setGramaj(_gramaj);
  this->setPret(_pret);
  this->setValabilitate(_valabilitate);
  this->setTinta(_tinta);
}

// Setters
void Medicament::setInterval(unsigned int _interval) { interval = this->isValidInterval(_interval) ? _interval : 0; }
void Medicament::setGramaj(unsigned int _gramaj) { gramaj = this->isValidGramaj(_gramaj) ? _gramaj : 0; }
void Medicament::setPret(double _pret) { pret = this->isValidPret(_pret) ? _pret : 0; }
void Medicament::setNume(string _nume) { nume = this->isValidString(_nume) ? _nume : "unknown"; };
void Medicament::setValabilitate(string _valabilitate) { valabilitate = this->isValidValabilitate(_valabilitate) ? _valabilitate : "15-01-1970"; }
void Medicament::setTinta(string _tinta) { tinta = this->isValidTinta(_tinta) ? _tinta : "Tinta necunoscuta"; }
void Medicament::setScope(string _scop) { scop = this->isValidScop(_scop) ? _scop : "unknown"; }

// Getters
unsigned int Medicament::getInterval() { return interval; }
unsigned int Medicament::getGramaj() { return gramaj; }
double Medicament::getPret() { return pret; }
string Medicament::getNume() { return nume; }
string Medicament::getValabilitate() { return valabilitate; }
string Medicament::getTinta() { return tinta; }
string Medicament::getScop() { return scop; }

// Validations
bool Medicament::isValidInterval(unsigned int _interval) { return _interval > 0 && _interval < 24; }
bool Medicament::isValidGramaj(unsigned int _gramaj) { return _gramaj > 0; }
bool Medicament::isValidPret(double _pret) { return _pret > 0; }
bool Medicament::isValidString(string _str) { return _str != "unknown" && _str.length() > 0; };
bool Medicament::isValidValabilitate(string _valabilitate) { return isValidString(_valabilitate) && _valabilitate != "15-01-1970"; } // Split the string and get the data
bool Medicament::isValidTinta(string _tinta) { return isValidString(_tinta) && (this->customCap(_tinta) == "copii" || this->customCap(_tinta) == "adulti"); }
bool Medicament::isValidScop(string _scop) { return isValidString(_scop); }
bool Medicament::isValidInitMedicament() {
  return isValidInterval(interval) && isValidGramaj(gramaj) && isValidPret(pret) && isValidString(nume) &&
         isValidValabilitate(valabilitate) && isValidTinta(tinta) && isValidScop(scop);
}

// Print
string Medicament::getInitMedicament() {
  return "Numele:\t\t\t" + getNume() + "\n" +
         "Gramaj:\t\t\t" + to_string(gramaj) + "\n" +
         "Tinta:\t\t\t" + getTinta() + "\n" +
         "Scop:\t\t\t" + getScop() + "\n" +
         "Pret:\t\t\t" + this->getPrecision(pret) + "\n" +
         "Interval orar:\t\t" + to_string(interval) + "\n" +
         "Valabilitate:\t\t" + getValabilitate() + "\n";
}

// Generic Data #PROTECTED
unsigned int Medicament::getValidInterval() { return 6; }
unsigned int Medicament::getValidGramaj() { return 400; }
double Medicament::getValidPret() { return 149.28; }
string Medicament::getValidNume() { return "Generic Medicament"; }
string Medicament::getValidValabilitate() { return "15-01-2020"; }
string Medicament::getValidTinta() { return "Adulti"; }
string Medicament::getValidScop() { return "Generic Scop"; }

// Destructor
Medicament::~Medicament()
{
  //dtor
}
