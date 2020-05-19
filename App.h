#ifndef APP_H
#define APP_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <conio.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <unistd.h>

using namespace std;

class App
{
public:
  // Constructors
  App();
  App(bool, bool, string);
  void Info();
  void Exit();
  void Sleep(int = 1000);

  // Setters
  void setAutoSave(bool _save);
  void setAutoValidare(bool);
  void setCurrentComponent(string _component);

  // Saves
  template <typename T>
  void saveMedicament(T*);
  template <typename T>
  void savePersoana(T*);
  template <typename T>
  void saveEntitate(T*);

  // Getters
  bool getAutoValidare();
  bool getAutoSave();
  string getCurrentComponent();
  string getSettings();
  string getHeader();

  // Validations
  bool isValidCurrentComponent(string _component);

  // Utils
  string customCap(string _str, bool _type = false);

  // Destructor
  virtual ~App();

protected:
private:
  bool autoSave;
  bool autoValidare;
  string currentComponent;
};

#endif // APP_H
