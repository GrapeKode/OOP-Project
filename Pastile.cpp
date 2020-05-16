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
bool Pastile::isValidCuloare(string _culoare) { return _culoare.length() > 0; }

// Utils

// Destructor
Pastile::~Pastile()
{
    //dtor
}
