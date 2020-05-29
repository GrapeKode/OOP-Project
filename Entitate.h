#ifndef ENTITATE_H
#define ENTITATE_H

// Class
#include "App.h"

using namespace std;

class Entitate : public App
{
public:
  // Constructor
  Entitate();
  Entitate(int _uuid, string _nume, string _locatie);

  // Setters
  void setId(int _uuid);
  void setNume(string _name);
  void setLocatie(string _locatie);

  // Getters
  int getId();
  string getNume();
  string getLocatie();
  string getInitEntitate();
  string printEntitate() {}

  // Validation
  bool isValidEntity();
  bool isValidId(int);
  bool isValidNume(string);
  bool isValidLocatie(string);

  // Auto validate
  void autoValidate() {}

  // Destructor
  virtual ~Entitate();

protected:
  // Generic Data
  int getValidId();
  string getValidNume();
  string getValidLocatie();
private:
  string locatie;
  string nume;
  int uuid;
};

#endif // ENTITATE_H
