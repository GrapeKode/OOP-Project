#ifndef SIROP_H
#define SIROP_H

// Class
#include "Medicament.h"

class Sirop : public Medicament
{
public:
  // Constructor
  Sirop();
  Sirop(int, string);
  Sirop(int, string, string);
  
  // Setters
  void setCantitate(int);
  void setTip(string);
  void setCuloare(string);

  // Getters
  int getCantitate();
  string getTip();
  string getCuloare();
  string getMedicament();

  // Validations
  bool isValidMedicament();
  bool isValidCantitate(int);
  bool isValidTip(string);
  bool isValidCuloare(string);

  // Utils
  
  // Destructor
  virtual ~Sirop();

protected:

private:
  int cantitate;        // Ex.: 50 ml
  string tip;           // Flacon | Pliculete
  string culoare;       // ...
};

#endif // SIROP_H
