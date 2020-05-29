#ifndef MEDICAMENT_H
#define MEDICAMENT_H

// Class
#include "App.h"

using namespace std;

class Medicament : public App
{
public:
  // Constructor
  Medicament();
  Medicament(unsigned int _interval, unsigned int _gramaj, double _pret, string _nume, string _valabilitate, string _tinta, string _scop);

  // Setters
  void setInterval(unsigned int _interval);
  void setGramaj(unsigned int _gramaj);
  void setPret(double _pret);
  void setNume(string);
  void setValabilitate(string _valabilitate);
  void setTinta(string _tinta);
  void setScope(string _scop);

  // Getters
  unsigned int getInterval();
  unsigned int getGramaj();
  double getPret();
  string getNume();
  string getValabilitate();
  string getTinta();
  string getScop();

  // Print
  string getInitMedicament();
  string getMedicament() {};

  // Validations
  bool isValidInterval(unsigned int _interval);
  bool isValidGramaj(unsigned int _gramaj);
  bool isValidPret(double _pret);
  bool isValidString(string _str);
  bool isValidValabilitate(string _valabilitate);
  bool isValidTinta(string _tinta);
  bool isValidScop(string _scop);
  bool isValidInitMedicament();
  virtual bool isValidMedicament() {};

  // Auto validate
  void autoValidate() {};

  // Destructor
  virtual ~Medicament();

protected:
  // Generic Data
  unsigned int getValidInterval();
  unsigned int getValidGramaj();
  double getValidPret();
  string getValidNume();
  string getValidValabilitate();
  string getValidTinta();
  string getValidScop();
private:
  unsigned int interval; // Intervalul orar de administrare
  unsigned int gramaj;   // Gramaj medicament
  double pret;           // Valoarea medicamentului
  string nume;           // Denumirea medicamentului
  string valabilitate;   // Data expirarii
  string tinta;          // Copii, Adulti
  string scop;           // Dureri de gat, spate etc...
};

#endif // MEDICAMENT_H
