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
  void setSirop(Sirop, int = -1);
  void setPastile(Pastile, int = -1);
  void setAngajat(Angajat, int = -1);
  void setClient(Client, int = -1);
  void setDepozitSize(int);
  void setPersonalSize(int);
  void setRemove(bool);

  // Remove
  void removeSirop(int);
  void removePastile(int);
  void removeAngajat(int);
  void removeClient(int);

  // Getters
  Sirop* getSirop();
  Pastile* getPastile();
  Angajat* getAngajati();
  Client* getClienti();
  int getDepozitSize();
  int getPersonalSize();
  bool isRemovedEntity();
  // Get length
  template <typename T>
  int getLengthMedicament(T);
  template <typename T>
  int getLengthPersonal(T, bool isEmployee = false);
  //
  int getLengthPastile();
  int getLengthSiropuri();
  int getLengthAngajati();
  int getLengthClienti();
  
  // Index
  int findIndexPastile(string);
  int findIndexSirop(string);
  int findIndexAngajat(unsigned long long int);
  int findIndexClient(unsigned long long int);
  // Get Item
  Pastile findPastile(int);
  Sirop findSirop(int);
  Angajat findAngajat(int);
  Client findClient(int);

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

  // Auto validate
  void autoValidate();
  // Auto salvare
  void autoSave();

  // Save & Load
  bool saveEntity(bool = false);
  bool importEntity();

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
