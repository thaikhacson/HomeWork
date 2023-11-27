#include <iostream>
#include <vector>

using namespace std;

const int NUMBER_ROOM = 5;

class Room{
    private:
        int roomNumber;
        bool isBooked;
        bool isCleaning;
    public:
        Room(int number) {
            roomNumber = number;
            isBooked = false;
            isCleaning = true;
        }
        int getRoomNumber() {
            return this->roomNumber;
        }
        bool isAvailble() {
            return !isBooked && isCleaning;
        }
        void bookRoom() {
            isBooked = true;
        }
        void checkIn() {
            isCleaning = false;
            isBooked = true;
        }
        void checkOut() {
            isCleaning = true;
            isBooked = false;
        }
};

vector<Room> databaseRoom;

class HotelManager {
    // private:
    //     vector<Room> databaseRoom;
    public:
        //vector<Room> databaseRoom;
        void displayAvailbleRooms();
        void bookRoom(int roomNumber);
        void checkIn(int roomNumber);
        void checkOut(int roomNumber);
        void updateRoom();
};

void HotelManager::displayAvailbleRooms() {
    cout << "Room\t" << "Status" << endl;
    cout << "-------------------------" << endl;
    for(auto &it : databaseRoom) {
        if(it.isAvailble()) {
            cout << it.getRoomNumber() << "\tVacant and ready!" << endl;
        } else {
            cout << it.getRoomNumber() << "\tOccupied!" << endl;
        }
    }
}

void HotelManager::bookRoom(int roomNumber) {
    for(auto &it : databaseRoom) {
        if(it.getRoomNumber() == roomNumber && it.isAvailble() == true) {
            it.bookRoom();
            cout << "Room " << roomNumber << " Booked successfully!" << endl;
        } else if(it.getRoomNumber() == roomNumber && it.isAvailble() == false) {
            cout << "Room " << roomNumber << " is occupied and cannot be booked" << endl;
        }
    }
}

void HotelManager::checkIn(int roomNumber) {
    for(auto &it : databaseRoom) {
        if(it.getRoomNumber() == roomNumber && it.isAvailble() == false) {
            it.checkIn();
            cout << "Room " << roomNumber << " Checked in successfully!" << endl;
        } else if(it.getRoomNumber() == roomNumber && it.isAvailble() == false) {
            cout << "Room " << roomNumber << " Cannot be checked in " << endl;
        }
    }
}

void HotelManager::checkOut(int roomNumber) {
    for(auto &it : databaseRoom) {
        if(it.getRoomNumber() == roomNumber && it.isAvailble() == true) {
            it.checkOut();
            cout << "Room " << roomNumber << " Checked out successfully!" << endl;
        } else if(it.getRoomNumber() == roomNumber && it.isAvailble() == false) {
            cout << "Room " << roomNumber << " Cannot be checked out " << endl;
        }
    }    
}

void HotelManager::updateRoom() {
    int ID = 101;
    for(int i = 0; i < NUMBER_ROOM; i++) {
        Room room(ID);
        databaseRoom.push_back(room);
        ID++;
    }
}

int main() {
    HotelManager hotel;
    
    hotel.updateRoom();
    hotel.displayAvailbleRooms();
    cout << "\n";
    hotel.bookRoom(102);
    hotel.checkIn(102);
    cout << "\n";
    hotel.displayAvailbleRooms();
    return 0;
}