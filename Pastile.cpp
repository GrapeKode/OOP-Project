#include "Pastile.h"

// Constructor
Pastile::Pastile() {
  nr = 0;
  tip = "unknown";
  culoare = "unknown";
}
Pastile::Pastile(string _tip, int _nr, string _culoare) {
  this->setNr(_nr);
  this->setTip(_tip);
  this->setCuloare(_culoare);
}

// Setters
void Pastile::setNr(int _nr) { nr = isValidNr(_nr) ? _nr : nr; }
void Pastile::setTip(string _tip) { tip = isValidTip(_tip) ? _tip : "unknown"; }
void Pastile::setCuloare(string _culoare) { culoare = isValidCuloare(_culoare) ? _culoare : "unknown"; }

// Getters
int Pastile::getNr() { return nr; }
string Pastile::getTip() { return tip; }
string Pastile::getCuloare() { return culoare; }
string Pastile::getMedicament() {
  return this->getInitMedicament() +
         "Nr. de pastile:\t\t" + to_string(nr) + "\n" +
         "Tipul:\t\t\t" + getTip() + "\n" +
         "Culoare:\t\t" + getCuloare() + "\n";
}

// Validations
bool Pastile::isValidMedicament() { return this->isValidInitMedicament() && isValidNr(nr) && isValidTip(tip); }
bool Pastile::isValidNr(int _nr) { return _nr > 0 && _nr < 100; }
bool Pastile::isValidTip(string _tip) { return _tip.length() > 0 && (this->customCap(_tip) == "tablete" || this->customCap(_tip) == "flacon"); }
bool Pastile::isValidCuloare(string _culoare) { return isValidString(_culoare); }

// Utils

// Auto validate
void Pastile::autoValidate() {
  // Medicine auto-validate
  if (!this->isValidInterval(this->getInterval())) {
    this->setInterval(getValidInterval());
  }
  if (!this->isValidGramaj(this->getGramaj())) {
    this->setGramaj(getValidGramaj());
  }
  if (!this->isValidPret(this->getPret())) {
    this->setPret(getValidPret());
  }
  if (!this->isValidString(this->getNume())) {
    this->setNume(getValidNume());
  }
  if (!this->isValidValabilitate(this->getValabilitate())) {
    this->setValabilitate(getValidValabilitate());
  }
  if (!this->isValidTinta(this->getTinta())) {
    this->setTinta(getValidTinta());
  }
  if (!this->isValidScop(this->getScop())) {
    this->setScope(getValidScop());
  }
  // Pill auto-validate
  if (!this->isValidNr(this->getNr())) {
    this->setNr(getValidNr());
  }
  if (!this->isValidTip(this->getTip())) {
    this->setTip(getValidTip());
  }
  if (!this->isValidCuloare(this->getCuloare())) {
    this->setCuloare(getValidCuloare());
  }
}

// Generic Data
int Pastile::getValidNr() { return 20; }
string Pastile::getValidTip() { return "Tablete"; }
string Pastile::getValidCuloare() { return "Rosu"; }

// Destructor
Pastile::~Pastile()
{
    //dtor
}
