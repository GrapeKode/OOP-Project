#ifndef FARMACIE_H
#define FARMACIE_H

// Class
#include "Entitate.h"
#include "Medicament.h"
#include "Pastile.h"
#include "Sirop.h"
#include "Angajat.h"
#include "Client.h"

#define S_MAX 100
#define P_MAX 100
#define A_MAX 20
#define C_MAX 1000

class Farmacie : public Entitate
{
public:
  // Constructor
  Farmacie();
  Farmacie(Sirop, Pastile, int);
  Farmacie(Angajat, Client, int);
  Farmacie(Sirop, Pastile, Angajat, Client, int, int);

  // Setters
  void setSirop(Sirop);
  void setPastile(Pastile);
  void setAngajat(Angajat);
  void setClient(Client);
  void setDepozitSize(int);
  void setPersonalSize(int);
  void setRemove(bool);

  // Remove
  void removeSirop(Sirop*);
  void removePastile(Pastile*);
  void removeAngajat(Angajat*);
  void removeClient(Client*);

  // Getters
  Sirop* getSirop();
  Pastile* getPastile();
  Angajat* getAngajati();
  Client* getClienti();
  int getDepozitSize();
  int getPersonalSize();
  bool isRemovedEntity();
  // Get size
  template <typename T>
  int getLengthMedicament(T);
  template <typename T>
  int getLengthPersonal(T, bool isEmployee = false);
  //
  int getLengthPastile();
  int getLengthSiropuri();
  int getLengthAngajati();
  int getLengthClienti();
  
  // Find
  Pastile findPastile(string);
  Sirop findSirop(string);
  Angajat findAngajat(unsigned long long int);
  Client findClient(unsigned long long int);

  // Print
  string printEntitate();
  template <typename T>
  string printMedicamente(T);
  template <typename T>
  string printPersoane(T);
  // 
  string printPastile();
  string printSiropuri();
  string printAngajati();
  string printClienti();

  // Validations
  bool isValidFarmacie();
  template <typename T>
  bool isValidMedicament(T*);
  template <typename T>
  bool isEmpty(T*);

  bool isValidDSize(int);
  bool isValidPSize(int);

  // Utils

  // Destructor
  virtual ~Farmacie();

protected:

private:
  // Depozit
  Sirop* siropuri;
  Pastile* pastile;
  // Personal
  Angajat* angajati;
  Client* clienti;
  // Size
  int depozitSize;
  int personalSize;
  // Delete
  bool isRemoved;
};

#endif // FARMACIE_H
