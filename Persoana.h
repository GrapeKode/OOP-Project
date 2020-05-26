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
  string getCNP();
  // Print
  string getInitPersoana();
  string getPersoana() {}
  // Validations
  bool isValidNume(string _nume);
  bool isValidCNP(unsigned long long int _CNP);
  bool isValidInitPersoana();
  bool isValidPersoana() {}

  virtual ~Persoana();

protected:
  string nume;
  string prenume;
  unsigned long long int CNP;

private:
};

#endif // PERSOANA_H
