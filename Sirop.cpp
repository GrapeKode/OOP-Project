#include "Sirop.h"

// Constructor
Sirop::Sirop()
{
  cantitate = 0;
  tip = "unknown";
  culoare = "unknown";
}
Sirop::Sirop(int _cantitate, string _tip) {
  this->setCantitate(_cantitate);
  this->setTip(_tip);
}
Sirop::Sirop(int _cantitate, string _tip, string _culoare) {
  this->setCantitate(_cantitate);
  this->setTip(_tip);
  this->setCuloare(_culoare);
}

// Setters
void Sirop::setCantitate(int _cantitate) { cantitate = isValidCantitate(_cantitate) ? _cantitate : 0; }
void Sirop::setTip(string _tip) { tip = isValidTip(_tip) ? _tip : "unknown"; }
void Sirop::setCuloare(string _culoare) { culoare = isValidCuloare(_culoare) ? _culoare : "unknown"; }

// Getters
int Sirop::getCantitate() { return cantitate; }
string Sirop::getTip() { return tip; }
string Sirop::getCuloare() { return culoare; }
string Sirop::getMedicament() {
  return getInitMedicament() +
         "Cantitate:\t\t" + to_string(cantitate) + "\n" +
         "Tipul:\t\t\t" + getTip() + "\n" +
         "Culoare:\t\t" + getCuloare() + "\n";
}

// Validations
bool Sirop::isValidMedicament() { return this->isValidInitMedicament() && isValidCantitate(cantitate) && isValidTip(tip); }
bool Sirop::isValidCantitate(int _cantitate) { return _cantitate > 0; }
bool Sirop::isValidTip(string _tip) { return this->customCap(_tip) == "flacon" || this->customCap(_tip) == "pliculete"; }
bool Sirop::isValidCuloare(string _culoare) { return isValidString(_culoare); }

// Auto validate
void Sirop::autoValidate() {
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
  if (!this->isValidCantitate(this->getCantitate())) {
    this->setCantitate(getValidCantitate());
  }
  if (!this->isValidTip(this->getTip())) {
    this->setTip(getValidTip());
  }
  if (!this->isValidCuloare(this->getCuloare())) {
    this->setCuloare(getValidCuloare());
  }
}

// Utils

// Generic Data
int Sirop::getValidCantitate() { return 150; }
string Sirop::getValidTip() { return "Flacon"; }
string Sirop::getValidCuloare() { return "Incolor"; }

// Destructor
Sirop::~Sirop()
{
  //dtor
}
