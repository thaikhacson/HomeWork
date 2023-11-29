#include "D:\Desktop\Embedded Interview\Home Work\HomeWork\C++\Hotel Manager\Header\Customer.hpp"


Customer::Customer(string customerName, string customrePhone, string customerAddress) {
    this->name = customerName;
    this->phoneNumber = customrePhone;
    this->address = customerAddress;
}

int Customer::getIDroom() {
    return this->idRoom;
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

void Customer::setIDroom(int i_ID) {
    this->idRoom = i_ID;
}

void Customer::setName(string s_Name) {
    this->name = s_Name;
}

void Customer::setPhone(string phone) {
    this->phoneNumber = phone;
}

void Customer::setAddress(string add) {
    this->address = add;
}

void Customer::addBookingHistory(bookingHistory bookingDetails) {

}

void Customer::displayBookingHistory() {

}

void CustomerManager::addCustomer(Customer customer) {
    int s_iInput;
    do {
        int s_iRoom;
        string s_sName, s_sPhone, s_sAddress;
        cout << "Enter Room Number: ";
        cin >> s_iRoom;

        //Check is the room is occupied
        for(auto it : databaseCustomer) {
            if(it.getIDroom() == s_iRoom) {
                cout << "Reservation failed. The room is occupied!" << endl;
                break;
            } 
        }
        cin.ignore();
        cout << "Name of Customer: ";
        getline(cin, s_sName);
        cout << "Phone of Customer: ";
        getline(cin, s_sPhone);
        cout << "Address of Customer: ";
        getline(cin, s_sAddress);
        Customer customer(s_sName, s_sPhone, s_sAddress);
        databaseCustomer.push_back(customer);
        cout << "Added Customer successfully" << endl;
        cout << "1. Add more Customers" << endl;
        cout << "2. Exit" << endl;
        cout << "Your choose: ";
        cin >> s_iInput;
    } while (s_iInput == 1);
    
}

void CustomerManager::editCustomer(int s_iRoom) {
    int s_iInput, s_iChangeRoom;
    string s_sName, s_sPhone, s_sAddress;
    do {
        cout << "Enter Room Number: ";
        cin >> s_iRoom;

        //Check is room
        for (auto it : databaseCustomer) {
            if(it.getIDroom() == s_iRoom) {
                cout << "1. Change to another room" << endl;
                cout << "2. Change name" << endl;
                cout << "3. Change phone" <<endl;
                cout << "4. Change address" << endl;
                cout << "Your choose: ";
                cin >> s_iInput;

                switch (s_iInput)
                {
                case 1:
                    cout << "Enter the room you want to change: ";
                    cin >> s_iChangeRoom;
                    it.setIDroom(s_iChangeRoom);
                    cout << "Room change successful" << endl;
                    break;
                case 2:
                    cout << "Enter the name you want to change: ";
                    cin >> s_sName;
                    it.setName(s_sName);
                    cout << "Name change successful" << endl;
                    break;
                case 3:
                    cout << "Enter the phone you want to change: ";
                    cin >> s_sPhone;
                    it.setPhone(s_sPhone);
                    cout << "Phone change successful" << endl;
                    break;
                case 4:
                    cout << "Enter the address you want to change: ";
                    cin >> s_sAddress;
                    it.setAddress(s_sAddress);
                    cout << "Address change successful" << endl;
                    break;
                
                default:
                    break;
                }
            }
        }
        cout << "1. Edit again" << endl;
        cout << "2. Exit" << endl;
        cout << "Your choose: ";
        cin >> s_iInput;

    } while(s_iInput == 1);
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
