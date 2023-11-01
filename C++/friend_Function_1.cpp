/*
-------------------(Hàm tự do bạn của một lớp)------------------------

Một hàm bạn của một lớp được khai báo hằng bằng từ khóa friend khi khai báo khuôn mẫu hàm trong lớp tương ứng
    class <tên lớp> {
        ...     // Khai báo các thành phần lớp như thông thường
        // Khai báo hàm bạn
        friend <Kiểu trả về> <Tên hàm bạn> ( <Các tham số> );
    };

Khi đó, định nghĩa chi tiết hàm bạn được thực hiện như định nghĩa một hàm tự do thông thường
    <Kiểu trả về> <Tên hàm bạn> ( <Các tham số> ) {
        ...     // Có thể truy cập trực tiếp các thành phần private của lớp đã khai báo
    }

*(Lưu ý)*
1. Mặc dù hàm bạn được kahi báo khuôn mẫu hàm trong phạm vi lớp, nhưng hàm bạn tự do lại không phải
là một phương thức của lớp. Nó là hàm tự do, việc định nghĩa và sử dụng hàm này hoàn toàn tương tự 
như các hàm tự do khác.

2. Việc khai báo khuôn mẫu hàm bạn trong phạm vi lớp ở vị trí nào cũng được: hàm bạn không bị ảnh hưởng 
bởi các từ khóa private, protected hay public trong lớp.

3. Trong hàm bạn, có thể truy cập trực tiếp đến các thành phần private và protected của đối tượng
có kiểu lớp mà nó là hàm bạn (truy nhập thông qua đối tượng cụ thể).


*/


#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

class Car{
    private:
        int speed;
        char mark[20];
        float price;
    public:
        void init(int, char[], float);              //Khởi tạo thông tin về xe
        friend void moreExpensive(Car, Car);        //Khai báo hàm bạn của lớp
};

//Khai báo phương thức bên ngoài lớp
void Car::init(int SpeedIn, char markIn[], float priceIn) {
    speed = SpeedIn;
    strcpy(mark, markIn);
    price = priceIn;
    return;
}

//Định nghĩa hàm bạn tự do
void moreExpensive(Car car1, Car car2) {

    //Truy cập các thuộc tính private
    if(car1.price > car2.price) 
        cout << "Xe thu 1 dat hon" << endl;
    else if(car1.price < car2.price) 
        cout << "Xe thu 2 dat hon" << endl;
    else 
        cout << "Hai xe gia bang nhau" << endl;
    return;
}

int main () {    
    Car car1, car2;
    
    //Khởi tạo xe thứ nhất, thứ hai
    car1.init(100, "Ford", 3000);
    car2.init(150, "Mercedes", 4000);

    //So sánh giá hai xe
    moreExpensive(car1, car2);          //Sử dụng hàm bạn tự do
    return 0;
}