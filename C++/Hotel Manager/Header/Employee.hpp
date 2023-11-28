#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

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

class User{
    private:
        string username;
        string password;
    public:
        User(string username, string password);
        string getUsername();
        bool authenticate(string inputPassword);
};

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
        void getAuthenticate(string inputPassword);
        string getName();
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

#endif