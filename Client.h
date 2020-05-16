#ifndef CLIENT_H
#define CLIENT_H

// Class
#include "Persoana.h"

using namespace std;

class Client : public Persoana
{
public:
  // Constructor
  Client();
  Client(string _recomandare, string _reteta);
  // Setters
  void setRecomandare(string _recomandare);
  void setReteta(string _reteta);
  void setClientFidel(bool _client_fidel);
  // Getters
  string getRecomandare();
  string getReteta();
  bool isClientFidel();
  // Print
  string getPersoana();
  // Validations
  bool isValidRecomandare(string _recomandare);
  bool isValidReteta(string _reteta);
  // Destructor
  virtual ~Client();

protected:
private:
  // unsigned int card;
  bool client_fidel;
  int len_reteta;
  string recomandare;
  string reteta;
};

#endif // CLIENT_H
