#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

//Loại đồ ăn
typedef enum {
    FOOD,
    DRINK
}Type;

//Đồ ăn
struct dish {
    string ID;
    int price;
    string name;
    Type type;
    dish(int, string, Type);
};

dish::dish(int price, string name, Type type) {
    this->name = name;
    this->price = price;
    this->type = type;
}

class table{
    private:
        int number_table;                  //số bàn
        bool status_table;                 //trạng thái bàn
        vector<table> Order;          //danh sách món ăn, trạng thái của bàn
    public:
        void setup_table(table);
        void show();
        table(int);
};

// void table::setup_table(int number_table) {
//     this->number_table = number_table;
// }

table::table(int number) {
    this->number_table = number;
    Order.push_back(number);
    Order[number].status_table = false;
}

void table::setup_table(table number) {
    if(Order[number.number_table].status_table == false) {  
        number.status_table = true;
    } else {
        cout << "Ban nay dang co nguoi";
    }
}

//Xem trạng thái từng bàn
void table::show() {
    // cout << "Ban: " << number_table << " ";
    // if(status_table) {
    //     cout << "Trang thai: O" << endl;
    //     this->number_table = number_table;
    // } else {
    //     cout << "Trang thai: X" << endl;
    // }
    for(int i = 0; i < Order.size(); i++) {
        cout << "Ban: " << Order[i].number_table << "\t";
        if(Order[i].status_table == true) {
            cout << "Trang thai: O" << endl;
        } else {
            cout << "Trang thai: X" << endl;
        }
    }
}

//Quản lý
class Manager{
    private:
        list<dish> menu;                //Danh sách món ăn(thêm, xóa, chỉnh sửa)
    public:
        void setup_table(table);
        void add_dish(dish&);
        void edit_dish(string);
        void delete_dish(string);
        void employee_manager();
        void print_menu();
};

//Set up bàn
void Manager::setup_table(table number) {
    
}

//Thêm món ăn
void Manager::add_dish(dish& new_dish) {
    static int ID_FOOD = 1;
    static int ID_DRINK = 1; 
    switch (new_dish.type){
        case FOOD:
            new_dish.ID = "FOOD" + to_string(ID_FOOD);
            menu.push_back(new_dish);
            ID_FOOD++;
            break;
        case DRINK:
            new_dish.ID = "DRINK" + to_string(ID_DRINK);
            menu.push_back(new_dish);
            ID_DRINK++;
            break;
        default:
            cout<<"Loai Do An khong hop le\n";
            break;
        }
}


void Manager::edit_dish(string ID) {
    for(auto& it : menu) {
        if(it.ID == ID) {
            int price;
            cout << "Vui long nhap gia moi: "; cin >> price;
            it.price = price;
        } 
    }
    cout << "Khong tim thay mon an voi ID " << ID << endl;
}

void Manager::delete_dish(string ID) {
    for (auto it = menu.begin(); it != menu.end(); ++it) {
        if (it->ID == ID) {
            menu.erase(it);
            break;
        }
    }
}

void Manager::print_menu() {
    cout << "Menu:\n";
    for (const auto& it : menu) {
        cout << "ID: " << it.ID << "\tName: " << it.name << "\tPrice: " << it.price << "\tType: " << (it.type == FOOD ? "Food" : "Drink") << endl;
    }
}

int main() {

    Manager manager;

    table table1(1);
    table table2(2);
    table1.setup_table(table1);
    table1.show();

    // dish dish1(3000, "Bun bo", FOOD);
    // dish dish2(4000, "Pho", FOOD);
    // dish dish3(1000, "Coca", DRINK);
    // manager.add_dish(dish1);
    // manager.add_dish(dish2);
    // manager.add_dish(dish3);
    // manager.print_menu();



    return 0;
}
