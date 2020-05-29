#ifndef PERSOANA_H
#define PERSOANA_H

// Class
#include "App.h"

using namespace std;

class Persoana : public App
{
public:
  // Constructor
  Persoana();
  Persoana(string _nume, string _prenume, unsigned long long int _CNP);
  
  // Setters
  void setNume(string _nume);
  void setPrenume(string _prenume);
  void setCNP(unsigned long long int _CNP);
  
  // Getters
  string getNume();
  string getPrenume();
  unsigned long long int getCNP();
  
  // Print
  string getInitPersoana();
  string getPersoana() {}

  // Validations
  bool isValidNume(string _nume);
  bool isValidCNP(unsigned long long int _CNP);
  bool isValidInitPersoana();
  bool isValidPersoana() {}

  // Auto validate
  void autoValidate() {};

  // Destructor
  virtual ~Persoana();

protected:
  // Generic Data
  string getValidNume();
  string getValidPrenume();
  unsigned long long int getValidCNP();
private:
  string nume;
  string prenume;
  unsigned long long int CNP;
};

#endif // PERSOANA_H
