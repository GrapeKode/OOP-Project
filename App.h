#ifndef APP_H
#define APP_H

#include <windows.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <conio.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <unistd.h>
#include <sstream>

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
  string getCurrentDir();
  bool mkdir(string);

  // Validations
  bool isValidCurrentComponent(string _component);

  // Utils
  string customCap(string _str, bool _type = false);
  // template <typename T>
  string getPrecision(double, int = 2);

  // Auto validate
  template <typename T>
  void autoValidate(T*);

  // Destructor
  virtual ~App();

protected:
private:
  bool autoSave;
  bool autoValidare;
  string currentComponent;
};

#endif // APP_H
