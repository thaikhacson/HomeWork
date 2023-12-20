#include <iostream>
#include "D:\Desktop\Embedded Interview\Home Work\HomeWork\C++\Hotel Manager\Header\Customer.hpp"
#include "D:\Desktop\Embedded Interview\Home Work\HomeWork\C++\Hotel Manager\Header\Employee.hpp"
#include "D:\Desktop\Embedded Interview\Home Work\HomeWork\C++\Hotel Manager\Header\Room.hpp"

using namespace std;

int main() {
    HotelManager h1;
    h1.updateRoom();
    h1.displayAvailbleRooms();
    h1.bookRoom(102);
    h1.displayAvailbleRooms();
}