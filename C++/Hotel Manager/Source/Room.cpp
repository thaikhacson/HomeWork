#include "D:\Desktop\Embedded Interview\Home Work\HomeWork\C++\Hotel Manager\Header\Room.hpp"

const int NUMBER_ROOM = 5;

Room::Room(int number) {
    roomNumber = number;
    isBooked = false;
    isCleaning = true;
}
int Room::getRoomNumber() {
    return this->roomNumber;
}
bool Room::isAvailble() {
    return !isBooked && isCleaning;
}
void Room::bookRoom() {
    isBooked = true;
}
void Room::checkIn() {
    isCleaning = false;
    isBooked = true;
}
void Room::checkOut() {
    isCleaning = true;
    isBooked = false;
}

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

//Create ID Room - 5 ROOM
void HotelManager::updateRoom() {
    int ID = 101;
    for(int i = 0; i < NUMBER_ROOM; i++) {
        Room room(ID);
        databaseRoom.push_back(room);
        ID++;
    }
}