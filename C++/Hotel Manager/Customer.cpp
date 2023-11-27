#include <iostream>
#include <vector>

using namespace std;

typedef enum{
    IN,
    OUT
}typeStatus;


typedef struct {
    int time;
    int date;
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
        Customer(string customerName, string customrePhone, string customerAddress) {
            this->name = customerName;
            this->phoneNumber = customrePhone;
            this->address = customerAddress;
        }

        string getName() {
            return this->name;
        }

        string getPhone() {
            return this->phoneNumber;
        }

        string getAddress() {
            return this->address;
        }

        void setPhone(string phoneNumber) {
            this->phoneNumber = phoneNumber;
        }

        void setAddress(string address) {
            this->address = address;
        }

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

void CustomerManager::addCustomer(Customer customer) {
    databaseCustomer.push_back(customer);
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

int main() {

    Customer newCustomer1("Tuan", "12345", "123 Street");
    Customer newCustomer2("Hoang", "12735", "1234 Street");

    CustomerManager customerManager;
    customerManager.addCustomer(newCustomer1);
    customerManager.addCustomer(newCustomer2);
    customerManager.displayCustomerInfo();
    cout << "-------------(After Edit)-------------" << endl;
    customerManager.editCustomer(newCustomer1);
    customerManager.displayCustomerInfo();
    cout << "------------(After Delete)------------" << endl;
    customerManager.deleteCustomer(newCustomer1);
    customerManager.displayCustomerInfo();

    return 0;
}