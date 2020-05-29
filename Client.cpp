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
string Client::getPersoana() {
  return this->getInitPersoana() +
    "Reteta:\t\t" + this->getReteta() + "\n" +
    "Recomandare:\t" + this->getRecomandare() + "\n" +
    "Clientul " + (this->isClientFidel() ? "" : "NU") +  " este fidel" + "\n\n";
}

// Validations
bool Client::isValidPersoana() { return this->isValidInitPersoana() && isValidReteta(reteta); }
bool Client::isValidRecomandare(string _recomandare) { return _recomandare != "unknown" && _recomandare.length() > 0; }
bool Client::isValidReteta(string _reteta) { return _reteta != "unknown" && _reteta.length() > 0; }

// Auto validate
void Client::autoValidate() {
  // Person auto-validate
  if (!this->isValidNume(this->getNume())) {
    this->setNume(getValidNume());
  }
  if (!this->isValidNume(this->getPrenume())) {
    this->setPrenume(getValidPrenume());
  }
  if (!this->isValidCNP(this->getCNP())) {
    this->setCNP(getValidCNP());
  }
  // Employee auto-validate
  if (!this->isValidRecomandare(this->getRecomandare())) {
    this->setRecomandare(getValidRecomandare());
  }
  if (!this->isValidReteta(this->getReteta())) {
    this->setReteta(getValidReteta());
  }
}

// Generic Data #PRIVATE
string Client::getValidRecomandare() { return "Aspirina, HIMALAYA"; }
string Client::getValidReteta() { return "Aspirina, HIMALAYA"; }

// Destructor
Client::~Client()
{
  //dtor
}
