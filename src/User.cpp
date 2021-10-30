//
// Created by nycuro on 10/30/21.
//

#include "../includes/User.h"
#include <fstream>
#include "../includes/Utils.h"

// Implementarea constructorului de initializare
User::User(const std::string &email, const std::string &password, const std::string &firstname, const std::string &lastname,
           const int &cnp, const std::string &sex, const long &birthdayDate, Profile* &userProfile) {
    std::cout << "[DEBUG] Apelare constructor User.h" << std::endl;
    this->email = email;
    this->password = password;
    this->firstname = firstname;
    this->lastname = lastname;
    this->cnp = cnp;
    this->sex = sex;
    this->birthdayDate = birthdayDate;
    this->userProfile = userProfile;
}

// Implementarea destructorului
User::~User() {
    std::cout << "[DEBUG] Apelare destructor User.h" << std::endl;
}

// Implementarea constructorului de copiere
User::User(const User &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere User.h" << std::endl;
    this->email = copie.email;
    this->password = copie.password;
    this->firstname = copie.firstname;
    this->lastname = copie.lastname;
    this->cnp = copie.cnp;
    this->sex = copie.sex;
    this->birthdayDate = copie.birthdayDate;
    this->userProfile = copie.userProfile;
}

// Implementarea operatorului =
User &User::operator=(const User &copie) {
    std::cout << "[DEBUG] Apelare constructor de copiere User.h" << std::endl;
    this->email = copie.email;
    this->password = copie.password;
    this->firstname = copie.firstname;
    this->lastname = copie.lastname;
    this->cnp = copie.cnp;
    this->sex = copie.sex;
    this->birthdayDate = copie.birthdayDate;
    this->userProfile = copie.userProfile;
    return *this;
}

// Getter pentru campul "email"
std::string& User::getEmail() {
    return this->email;
}

// Setter pentru campul "email"
void User::setEmail(std::string &userEmail) {
    this->email = userEmail;
}

// Implementarea de la userAvailability (verific daca user-ul exista)
bool User::checkUserAvailability(const User &user) {
    std::ifstream file;
    std::string data;

    file.open("accounts.txt");

    while (std::getline(file, data)) {
        std::vector<std::string> wordsExploded = Utils::explodeString(data);
        for (const auto &word : wordsExploded) {
            if (user.email == word) {
                file.close();
                return true;
            }
        }
    }

    file.close();

    return false;
}
