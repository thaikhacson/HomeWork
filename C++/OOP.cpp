#include <iostream>
#include <string>
using namespace std;

//---Class---
//Thuộc tính: attribute - tên tuổi, địa chỉ, ngày sinh
//Phương thức: method, behavior - đi lại, ăn uống
//object: Đối tượng

// ----Tính chất-----
//1> Encapsulation: Đóng gói
// - Access modifier: Phạm vi
// + Private: Thuộc tính
// + Public: Phương thức
// + Protected

//Constructor: Hàm khởi tạo -- cùng tên với class và không có kiểu trả về
//Destructor : Hàm hủy - hủy đi một đối tượng, không có kiểu trả về, 

//setter - getter: lấy ra các thuộc tính nhưng không truy cập trực tiếp các thuộc tính để đảm bảo tính chất đóng gói 

//static

//Friend function, friend class

//forward declaration
class Giaovien;
class Sinhvien;

class Giaovien{
    private:
        string khoa;
    public:
        void update(Sinhvien&);
};

void Giaovien::update(Sinhvien& x) {
    x.gpa = 3.2;
}

class Sinhvien{
    friend class Giaovien; //Tất cả phương thức, thuộc tính của class Giaovien có thể truy cập trực tiếp vào các phương thức, thuộc tính private của class Sinhvien
    private: 
        string id, ten, ns;
        double gpa;
        static int dem; //Không thể khởi tạo nó
    public:
        Sinhvien(); //Constructor
        Sinhvien(string, string, string, double); //Constructor có tham số
        void xinchao();
        void nhap();
        void in();

        double getGpa(); //getter
        string getName(); //getter
        void setGpa(double);

        void tangDem();
        int getDem();

        friend void inthongtin(Sinhvien); //Friend function: Hàm bạn

        ~Sinhvien(); //Được gọi khi đối tượng kết thúc, chạy hết chương trình
};

//Hàm bạn:Không phải làm member, không phải hàm của lớp hiện tại nhưng nó có thể truy cập các thuộc tính private hay phương thức private của Sinhvien
void inthongtin(Sinhvien a) {
    cout << a.id << " " << a.ten << endl;
}

int Sinhvien::dem = 1;

//Implementation

void Sinhvien::tangDem() {
    ++dem;
}

int Sinhvien::getDem() {
    return dem;
}

Sinhvien::Sinhvien(){
    cout << "Ham khoi tao duoc goi!";
    //Ở đây thường gán rỗng hoặc bằng 0
    this->id = this->ten = this->ns = "";
    this->gpa = 0;
}

//---this pointer---

// Sinhvien::Sinhvien(string ma, string name, string birth, double diem){
//     cout << "Ham khoi tao co tham so duoc goi" << endl;
//     id = ma;
//     ten = name;
//     ns = birth;
//     gpa = diem;
// }
Sinhvien::Sinhvien(string id, string ten, string ns, double gpa){
    cout << "Ham khoi tao co tham so duoc goi" << endl;
    this->id = id;
    this->ten = ten;
    this->ns = ns;
    this->gpa = gpa;
}

Sinhvien::~Sinhvien() {
    cout << "Doi tuong duoc huy tai day!" << endl;
}

void Sinhvien::xinchao() {
    cout << "Hello!" << endl;
}

void Sinhvien::nhap() {
    cout << "Nhap id: ";
    cin >> this->id;
    cin.ignore();
    cout << "Nhap ten: "; 
    getline(cin, this->ten);
    cout << "Nhap ngay sinh: ";
    cin >> this->ns;
    cout << "Nhap diem: "; 
    cin >> this->gpa;
}

void Sinhvien::in() {
    cout << this->id << " " << this->ten << " " << this->ns << " " << this->gpa << endl;
}

double Sinhvien::getGpa() {
    return this->gpa; //Muốn trả về thông tin nào thì viết getter trả về thuộc tính đó
}

void Sinhvien::setGpa(double gpa) {
    this->gpa = gpa; //Gán gpa đối tượng này bằng một tham số gpa mới
}

bool cmp (Sinhvien a, Sinhvien b) {
    return a.getGpa() > b.getGpa();
}

int main() {
    //Sinhvien x("123", "Nguyen Van A", "25/12/2002", 3.14); //Constructor có tham số
    
    Sinhvien x;
    x.setGpa(2.19); //Gán giá trị cho gpa

    x.tangDem(); //dem = 1
    x.tangDem(); //dem = 2
    Sinhvien y;
    cout << y.getDem() << endl; //dem = 2

    Giaovien y;
    y.update(x);

    int n; cin >> n;
    Sinhvien a[10]; 
    for(int i = 0; i < n; i++) {
        a[i].nhap();
    }

    for(int i = 0; i < n; i++) {
        a[i].in();
    }
    return 0;
}