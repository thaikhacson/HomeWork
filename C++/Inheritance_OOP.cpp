#include <iostream>
#include <string.h>
using namespace std;

class Car{
        int speed;
        char mark[20];
        float price;
    public:
        Car();
        Car(int, char[], float);
};

Car::Car() {
    speed = 0;
    strcpy(mark, "");
    price = 0;
}

Car::Car(int speedIn, char markIn[], float priceIn) {
    speed = speedIn;
    strcpy(mark, markIn);
    price = priceIn;
}

//Định nghĩa lớp Bus kế thừa từ lớp Car
class Bus: public Car{
        int label;
    public:
        Bus();
        Bus(int, char[], float, int);
};

Bus::Bus():Car(){
    label = 0;
}

Bus::Bus(int sIn, char mIn[], float pIn, int lIn) : Car(sIn, mIn, pIn){
    label = lIn;
}

int main() {

}