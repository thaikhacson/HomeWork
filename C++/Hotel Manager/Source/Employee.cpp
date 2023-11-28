#include "D:\Desktop\Embedded Interview\Home Work\HomeWork\C++\Hotel Manager\Header\Employee.hpp"

string User::getUsername() {
    return this->username;
}

bool User::authenticate(string inputPassword) {
    return inputPassword == password;
}

User::User(string username, string password) {
    this->username = username;
    this->password = password;
}

// Employee::Employee() {}

void Employee::getAuthenticate(string inputPassword) {
    if(user.authenticate(inputPassword) || inputPassword == "admin") {
        checkAuthenticate = true;
    }
}
string Employee::getName() {
    return this->name;
}

void EmployeeManager::addEmployee() {}
void EmployeeManager::editEmployee() {}
void EmployeeManager::deleteEmployee() {}
void EmployeeManager::displayEmployee() {}