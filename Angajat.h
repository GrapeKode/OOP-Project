#ifndef ANGAJAT_H
#define ANGAJAT_H

// Class
#include "Persoana.h"

using namespace std;

class Angajat : public Persoana
{
public:
  Angajat();
  Angajat(unsigned int _uuid, string _grad, string _locatie, int _program, double _salariu);
  // Setters
  void setUuid(unsigned int _uuid);
  void setSalariu(double _salariu);
  void setProgram(int _program);
  void setLocatie(string _locatie);
  void setGrad(string _grad);
  // Getters
  unsigned int getUuid();
  double getSalariu();
  int getProgram();
  string getLocatie();
  string getGrad();
  // Print
  string getPersoana();
  // Validations
  bool isValidUuid(unsigned int _uuid);
  bool isValidSalariu(double _salariu);
  bool isValidProgram(int _program);
  bool isValidLocatie(string _locatie);
  bool isValidGrad(string _grad);
  // Destructor
  virtual ~Angajat();

protected:
private:
  unsigned int uuid;
  double salariu;
  int program;
  string locatie;
  string grad;
};

#endif // ANGAJAT_H
