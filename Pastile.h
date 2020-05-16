#ifndef PASTILE_H
#define PASTILE_H

// Class
#include "Medicament.h"

class Pastile : public Medicament
{
public:
  // Constructor
  Pastile();
  Pastile(string, int, string);

  // Setters
  void setNr(int);
  void setTip(string);
  void setCuloare(string);
  
  // Getters
  int getNr();
  string getTip();
  string getCuloare();
  string getMedicament();

  // Validations
  bool isValidMedicament();
  bool isValidNr(int);
  bool isValidTip(string);
  bool isValidCuloare(string);
  
  // Destructor
  virtual ~Pastile();

protected:

private:
  int nr;           // 2x tablete (10x pastile)
  string tip;       // Tablete / Flacon
  string culoare;   // Albastru, rosu

};

#endif // PASTILE_H
