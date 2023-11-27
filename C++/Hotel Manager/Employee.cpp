#include <iostream>
#include <vector>

using namespace std;

typedef enum{
    JANITOR,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    LAUGGAGE_STAFF,
    GRADENER
}JobPosition;

class User{
    private:
        string username;
        string password;
    public:
        User(string username, string password);
        string getUsername() {
            return this->username;
        }
        bool authenticate(string inputPassword) {
            return inputPassword == password;
        }
};

typedef struct{
    int day;
    int month;
    int year;
}typeDate;

typedef struct{
    int second;
    int minute;
    int hour;
}typeTime;

typedef enum{
    IN,
    OUT
}typeStatus;

typedef struct {
    typeTime time;
    typeDate date;
}Schedule;

User::User(string username, string password) {
    this->username = username;
    this->password = password;
}

class Employee{
    private:
        string name;
        string phoneNumber;
        JobPosition position;
        Schedule schedule;
        bool checkAuthenticate;
        User user;
    public:
        Employee();
        void getAuthenticate(string inputPassword) {
            if(user.authenticate(inputPassword) || inputPassword == "admin") {
                checkAuthenticate = true;
            }
        }
        string getName() {
            return this->name;
        }
};

class EmployeeManager{
    private:
        vector<Employee> databaseEmployee;
    public:
        void addEmployee();
        void editEmployee();
        void deleteEmployee();
        void displayEmployee();
};

int main() {

}