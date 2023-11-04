#include <iostream>
#include <string>
#include <iterator>
#include <vector>
using namespace std;

class Student{
    private:
        string name;
        int age;
        int studentID;
        string course;
        string classSchedule;
    public:
        Student();
        Student(string, int, int, string, string);
        void addStudent();
        void editStudent(int);
        void deleteStudent(int);
        void showStudent();

        void setName(string name) {this->name = name;}
        void setInclass(string course) {this->course = course;}
};

vector<Student> listStudent;

Student::Student(string name, int age, int studentID, string course, string classSchedule) {
    this->name = name;
    this->age = age;
    this->studentID = studentID;
    this->course = course;
    this->classSchedule = classSchedule;
}

void Student::addStudent(){
    string name; int age; int studentID; string course; string classSchedule;
    cin.ignore();
    cout << "Nhap ten sinh vien: "; getline(cin, name);
    cout << "Nhap ma so sinh vien: "; cin >> studentID;
    cin.ignore(); // Loại bỏ dấu xuống dòng còn lại trong luồng đầu vào
    cout << "Nhap tuoi sinh vien: "; cin >> age;
    cin.ignore(); // Loại bỏ dấu xuống dòng còn lại trong luồng đầu vào
    cout << "Nhap khoa hoc: "; getline(cin, course);
    cout << "Nhap lich hoc: "; getline(cin, classSchedule);
    listStudent.push_back(Student(name, age, studentID, course, classSchedule));
}

void Student::deleteStudent(int ID){
    for (int i=0; i<listStudent.size(); i++)
    {
        if (listStudent[i].studentID == ID)
        {
            listStudent.erase(listStudent.begin() + i);
        }
    }
}

void Student::editStudent(int ID){
    for (int i=0; i<listStudent.size(); i++){
        if (listStudent[i].studentID == ID)
        {           
            string ten, lop;
            //cin.ignore();
            cout << "Nhap lai ten SV: "; getline(cin, ten);
            cout << "Nhap lai lop SV: "; getline(cin, lop);
            listStudent[i].setName(ten);
            listStudent[i].setInclass(lop);
        }
        else
            cout << "MSSV khong ton tai!" << endl;
    }
}

void Student::showStudent(){  
  for (int i = 0; i < listStudent.size(); i++){
    cout << "Ho ten: " << listStudent[i].name << endl;
    cout << "MSSV : " << listStudent[i].studentID << endl;
    cout << "Tuoi: " << listStudent[i].age << endl;
    cout << "Khoa hoc : " << listStudent[i].course << endl;
    cout << "Lich hoc : " << listStudent[i].classSchedule << endl;
    cout << "-----------" << endl;
  }
}

int main() {

    Student st("Name", 21, 00, "Course", "Day");

    int input, ID;
    while (true)
    {
        cout << "CHUONG TRINH QUAN LY SINH VIEN\n";
        cout << "CHUC NANG : \n";
        cout << "1. Them thong tin sinh vien.\n";
        cout << "2. Sua thong tin sinh vien.\n";
        cout << "3. Xoa thong tin sinh vien.\n";
        cout << "4. Dua ra thong tin sinh vien.\n";
        cout << "0. Thoat.\n";
        cout << "Ban chon : " ; 
        cin >> input;

        switch (input)
        {
        case 1:
            cout << "Ban da chon them thong tin sinh vien!\n";
            st.addStudent();
            break;
        case 2:
            cin.ignore(); // ignore roi xuong duoi khong ignore nua
            cout << "Ban da chon sua thong tin sinh vien!\n";
            cout << "Nhap id sinh vien : "; cin >> ID;
            st.editStudent(ID);
            break;
        case 3:
            cout << "Ban da chon xoa thong tin sinh vien!\n";
            cout << "Nhap id sinh vien : "; cin >> ID;
            st.deleteStudent(ID);
            break;
        case 4:
            cout << "Ban da chon dua ra thong tin sinh vien!\n";
            st.showStudent();
            break;
        case 0:
            return 0;
        }
    }
}