/*
------------------(Phương thức lớp là bạn của một lớp khác)----------------------

1. Khai báo khuôn mẫu lớp A, để làm tham số cho hàm f của lớp B
    class A;

2. Khai báo lớp B với hàm f như khai báo các lớp thông thường
    class B {
        ...     // Khhai báo các thành phần khác của lớp B
        void f(A);
    };

3. Khai báo chi tiết lớp A với hàm f của lớp B là bạn
    class A {
        ...     // Khai báo các thành phần khác của lớp A
        friend void B::f(A);
    };

4. Địnhh nghĩa chi tiết hàm f của lớp B
    void B::f(A) {
        ...     // Định nghĩa chi tiết hàm f
    }

*(Lưu ý)*
1. Trong trường hợp này, hàm f chỉ được định nghĩa chi tiết một khi lớp A đã được định nghĩa chi tiết.
Do vậy chỉ có thể định nghĩa chi tiết hàm f ở trong lớp A (ở bước 3) hoặc sau khi định nghĩa lớp A (ở bước 4)
Mà không thể định chi tiết hàm f ngay trong lớp B (ở bước 2).

2. Hàm f có thể truy nhập đên các thhafnh phần private và protected của cả hai lớp A và B.
Tuy nhiên, muốn f truy nhập đến các thành phần của lớp A thì phải thông qua một đối tượng cụ thể có kiểu lớp A.

*/

#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

class Car;

class Person {
    private: 
        int age;
        char name[25];
    public:
        void init(int, char[]);
        int permission(Car);
};

class Car {
    private: 
        int speed;
        char mark[20];
        float price;
    public:
        void init(int, char[], float);   
        friend int Person::permission(Car);
};

void Person::init(int ageIn, char nameIn[]) {
    age = ageIn;
    strcpy(name, nameIn);
    return;
}

void Car::init(int speedIn, char markIn[], float priceIn) {
    speed = speedIn;
    strcpy(mark, markIn);
    price = priceIn;
    return;
}

int Person::permission(Car car) {
    if(age < 18) 
        return 0;
    if((age < 21) && (car.speed > 150))
        return 0;
    return 1;
}

int main() {
    Car car;
    Person person;

    car.init(100, "Ford", 3000);
    person.init(20, "Son");

    if(person.permission(car)) 
        cout << "Co quyen dieu khien" << endl;
    else 
        cout << "Khong co quyen dieu khien" << endl;

    return 0;
}

