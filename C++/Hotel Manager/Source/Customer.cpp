#include "D:\Desktop\Embedded Interview\Home Work\HomeWork\C++\Hotel Manager\Header\Customer.hpp"


Customer::Customer(string customerName, string customrePhone, string customerAddress) {
    this->name = customerName;
    this->phoneNumber = customrePhone;
    this->address = customerAddress;
}

string Customer::getName() {
    return this->name;
}

string Customer::getPhone() {
    return this->phoneNumber;
}

string Customer::getAddress() {
    return this->address;
}

void Customer::setPhone(string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Customer::setAddress(string address) {
    this->address = address;
}

void Customer::addBookingHistory(bookingHistory bookingDetails) {

}

void Customer::displayBookingHistory() {

}

void CustomerManager::editCustomer(Customer customer) {
    for (auto& it : databaseCustomer) {
        if(it.getName() == customer.getName()) {
            it.setPhone("0984");
            it.setAddress("Thu Duc");
        }
    }
}

void CustomerManager::deleteCustomer(Customer customer) {
    for(auto& it : databaseCustomer) {
        if(it.getName() == customer.getName()) {
            databaseCustomer.erase(databaseCustomer.begin());
        }
    }
}

void CustomerManager::displayCustomerInfo() {
    cout << "Name\t\t" << "Phone\t\t" << "Address" << endl;
    for (auto it : databaseCustomer) {
        cout << it.getName() << "\t\t" << it.getPhone() << "\t\t" << it.getAddress() << endl;
    }
}
