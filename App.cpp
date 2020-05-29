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
void App::saveMedicament(T* Medicine) {

}
template <typename T>
void App::savePersoana(T* Person) {}
template <typename T>
void App::saveEntitate(T* Entity) {}

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
string App::getCurrentDir() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}
bool App::mkdir(string fileName) {
    if (CreateDirectory(fileName.c_str(), NULL) || ERROR_ALREADY_EXISTS == GetLastError()) {
        return true;
    } else {
        cout << "false";
        return false;
    }
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

// Auto validate
template <typename T>
void App::autoValidate(T* Entity) {
    string currentComponent = getCurrentComponent();

    if (!isValidCurrentComponent(currentComponent)) {
        cout << "\nINFO: Auto-validarea nu functioneaza pentru componenta curenta: " << currentComponent << "\n\n";
        return;
    }

    Entity.autoValidate();
}

// Destructor
App::~App()
{
    //dtor
}
