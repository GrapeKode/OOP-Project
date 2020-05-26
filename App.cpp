#include "App.h"

// Constructors
App::App() {
    setAutoSave(true);
    setAutoValidare(false);
    setCurrentComponent("Main");
}
App::App(bool _save, bool _autoValidare, string _component) {
    setAutoSave(_save);
    setCurrentComponent(_component);
    setAutoValidare(_autoValidare);
}

// Setters
void App::setAutoSave(bool _save) { autoSave = _save; }
void App::setAutoValidare(bool _autoValidare) { autoValidare = _autoValidare; }
void App::setCurrentComponent(string _component) {
    if (!isValidCurrentComponent(_component)) {
        cout << "Componenta selectata este incorecta.";
        return;
    }
    currentComponent = _component;
}

// Saves
template <typename T>
void App::saveMedicament(T*) {

}
template <typename T>
void App::savePersoana(T*) {}
template <typename T>
void App::saveEntitate(T*) {}

// Getters
bool App::getAutoValidare() { return autoValidare; }
bool App::getAutoSave() { return autoSave; }
string App::getCurrentComponent() { return currentComponent; }
string App::getHeader() {
    system("cls");
    // isValidCurrentComponent("Main");
    return "Aplicatia Farmacie\t\t" + getCurrentComponent() + "\n\n";
}
string App::getSettings() {
    return "Componenta selectata:\t" + this->getCurrentComponent() + "\n" +
           "Auto salvare:\t\t" + (this->getAutoSave() ? "TRUE" : "FALSE") + "\n" +
           "Auto validare:\t\t" + (this->getAutoValidare() ? "TRUE" : "FALSE") + "\n\n" +
           "INFO:\n" +
           "Auto salvare  - se salveaza automat intr-un fisier atunci cand se fac modificari.\n" +
           "Auto validare - se valideaza automat o entitate atunci cand se creaza sau se editeaza.\n\n";
}


// Validations
bool App::isValidCurrentComponent(string _component) {
    string k = customCap(_component, false);
    if (k == "main" || k == "entity" || k == "medicine" || k == "employee" || k == "client" || k == "info" || k == "exit") {
        return true;
    } else {
        return false;
    }
}

// Utils
string App::customCap(string _str, bool _type) {
    // Type = true => convert to uppercase
    std::string result = _str;
    if (_type) {
        transform(result.begin(), result.end(), result.begin(), ::toupper);
    } else {
        transform(result.begin(), result.end(), result.begin(), ::tolower);
    }
    return result;
}
// template <typename T>
string App::getPrecision(double value, int precision) {
  std::stringstream result;
  result << std::fixed << std::setprecision(precision) << value;

  return result.str();
}

void App::Info()
{
    // cout << "Aceasta aplicatie cuprinde 3 elemente de baza:\n"
    //     << "1. Entitate - ce reprezinta o firma, o companie; in cazul nostru avem ca entitate o Farmacie\n"
    //     << "\tAccesand aceasta categorie aplicatie se comporta din perspectiva unui angajator.\n\n"
    //     << "2. Angajat - ex. farmacist\n"
    //     << "\tCa si angajat atributele/sarcinile tale sunt de a colecta date despre posibili angajati si administrarea lor\n\n"
    //     << "3. Client - ex. client intr-o farmacie\n"
    //     << "\tCa si client tot ce poti face este sa ceri informatii sau faci anumite achizitii\n\n";
    cout << "Tema aleasa:\t Farmacie" << endl
         << "Numele:\t\t Ruben ILCIUC" << endl
         << "Grupa:\t\t 3124A" << endl
         << "Specializare:\t Calculatoare" << endl
         << "Anul:\t\t II" << endl << endl;
}

void App::Exit() {
    char quite;
    cout << "X. Aplicatia e pe care sa se inchida. Inchideti aplicatia? (y/N): ";
    cin >> quite;
    if (toupper(quite) == 'Y')
    {
        cout << "Aplicatia se inchide...\n";
        usleep(1000000); // Wait 1 seconds
        cout << "Procesul aplicatiei s-a incheiat.\n\n";
        exit(1);
    }
}

void App::Sleep(int ms) {
    usleep(ms * 1000);
}

// Destructor
App::~App()
{
    //dtor
}
