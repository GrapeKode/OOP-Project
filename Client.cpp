#include "Client.h"

// Constructor
Client::Client()
{
  recomandare = "unknown";
  reteta = "unknown";
  client_fidel = false;
}
Client::Client(string _recomandare, string _reteta)
{
  this->setRecomandare(_recomandare);
  this->setReteta(_reteta);
}

// Setters
void Client::setRecomandare(string _recomandare) { recomandare = this->isValidRecomandare(_recomandare) ? _recomandare : "unknown"; }
void Client::setReteta(string _reteta) { reteta = this->isValidReteta(_reteta) ? _reteta : "unknown"; }
void Client::setClientFidel(bool _client_fidel) { client_fidel = _client_fidel; }

// Getters
string Client::getRecomandare() { return recomandare; }
string Client::getReteta() { return reteta; }
bool Client::isClientFidel() { return client_fidel; }

// Print
string Client::getPersoana() { return this->getInitPersoana() + "Client!"; }

// Validations
bool Client::isValidRecomandare(string _recomandare) { return _recomandare.length() > 0; }
bool Client::isValidReteta(string _reteta) { return _reteta.length() > 0; }

// Destructor
Client::~Client()
{
  //dtor
}
