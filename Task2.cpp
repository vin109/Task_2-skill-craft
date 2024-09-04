#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool hasLowerCase(const string &password) {
    for (char c : password) {
        if (islower(c)) return true;
    }
    return false;
}

bool hasUpperCase(const string &password) {
    for (char c : password) {
        if (isupper(c)) return true;
    }
    return false;
}

bool hasDigit(const string &password) {
    for (char c : password) {
        if (isdigit(c)) return true;
    }
    return false;
}

bool hasSpecialChar(const string &password) {
    const string specialChars = "!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~";
    for (char c : password) {
        if (specialChars.find(c) != string::npos) return true;
    }
    return false;
}

string assessPasswordStrength(const string &password) {
    int criteriaMet = 0;

    if (password.length() >= 8) criteriaMet++;
    if (hasLowerCase(password)) criteriaMet++;
    if (hasUpperCase(password)) criteriaMet++;
    if (hasDigit(password)) criteriaMet++;
    if (hasSpecialChar(password)) criteriaMet++;

    if (criteriaMet == 5) {
        return "Strong";
    } else if (criteriaMet >= 3) {
        return "Moderate";
    } else {
        return "Weak";
    }
}

int main() {
    string password;

    cout << "Enter a password to assess its strength: ";
    cin >> password;

    string strength = assessPasswordStrength(password);

    cout << "Password strength: " << strength << endl;

    return 0;
}
