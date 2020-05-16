#ifndef APP_H
#define APP_H

#include <iostream>
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
  App(bool _save, string _component);
  void Info();
  void Exit();
  void Sleep(int = 1000);

  // Setters
  void setAutoSave(bool _save);
  void setCurrentComponent(string _component);

  // Getters
  bool getAutoSave();
  string getCurrentComponent();
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
  bool autoComplete;
  string currentComponent;
};

#endif // APP_H
