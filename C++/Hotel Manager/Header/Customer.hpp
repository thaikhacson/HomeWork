#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <iostream>
#include <vector>

using namespace std;

typedef enum{
    IN,
    OUT
}typeStatus;

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

typedef struct {
    typeTime time;
    typeDate date;
    typeStatus status;
}bookingHistory;

class Customer{
    private:
        int idRoom;
        string name;
        string phoneNumber;
        string address;
        vector<bookingHistory> bookingHistorys;
    public:
        Customer(string customerName, string customrePhone, string customerAddress);
        string getName();
        string getPhone();
        string getAddress();
        void setPhone(string phoneNumber);
        void setAddress(string address);
        void addBookingHistory(bookingHistory bookingDetails);
        void displayBookingHistory();
};

vector<Customer> databaseCustomer;

class CustomerManager{
    // private:
    //     vector<Customer> databaseCustomer;
    public:
        void addCustomer(Customer customer);
        void editCustomer(Customer customer);
        void deleteCustomer(Customer customer);
        void displayCustomerInfo();
};
#endif