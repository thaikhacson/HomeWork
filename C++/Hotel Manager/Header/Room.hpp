#ifndef _ROOM_H
#define _ROOM_H   

#include <iostream>
#include <vector>

using namespace std;

class Room{
    private:
        int roomNumber;
        bool isBooked;
        bool isCleaning;
    public:
        Room(int number);
        int getRoomNumber();
        bool isAvailble();
        void bookRoom();
        void checkIn();
        void checkOut();
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

#endif