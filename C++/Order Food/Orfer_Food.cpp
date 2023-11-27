#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;
class Menu;
class Table;

const int NUMBER_TABLE = 5;


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
    void show();
};

dish::dish(int price, string name, Type type) {
    this->name = name;
    this->price = price;
    this->type = type;
}

void dish::show() {
    cout << this->ID << " " << this->name << " " << this->price << " " << ((this->type == 1) ? "DRINK" : "FOOD") << endl;
}

class Table{
    public:
        int id;                  //số bàn
        bool status;                 //trạng thái bàn
        vector<dish> list_dish;          //danh sách món ăn
        Table(): id(-1), status(false) {};
        Table(int id, vector<dish> dishes) : id(id), status(false), list_dish(dishes) {};
        void setup_table(vector<dish> dishes);
        void show();
};



void Table::setup_table(vector<dish> dishes) {
    this->list_dish = dishes;
    this->status = true;
}

//Xem trạng thái từng bàn
void Table::show() {
    printf("Ban %d\n", this->id);
    cout << "Trang thai: " << this->status << '\n';
    cout << "Thuc don: \n";
    for (dish d : this->list_dish) {
        d.show();
    }
}

  
//Quản lý
class Manager{
    private:
        int id;
        string name;
    public:
        Manager() : id(-1), name("ADMIN") {};
        void setup_table(int id, vector<dish> dishes);
        void add_dish(dish&);
        void edit_dish(string);
        void delete_dish(string);
        void employee_manager();
        void print_menu();
};

class Menu {
    private:
        list<dish> list_dish;
    public:
        Menu() {
            list_dish.clear();
        };
        void addDish(dish d) {
            this->list_dish.push_back(d);
        }
        void removeDish(int id);
        void print() {
            for (auto it = list_dish.begin(); it != list_dish.end(); it++) {
                (*it).show();
            }
        }
        int getNumberDish() {
            return this->list_dish.size();
        }
        int getNumberFood() {
            int res = 0;
            for (auto it = this->list_dish.begin(); it != this->list_dish.begin(); it++) {
                if ((*it).type == FOOD) res++;
            }
            return res;
        }
        int getNumberDrink() {
            int res = 0;
            for (auto it = this->list_dish.begin(); it != this->list_dish.begin(); it++) {
                if ((*it).type == DRINK) res++;
            }
            return res;
        }
        // changeDish(int id);
};
//Set up bàn
Menu menu;
Table list_table[NUMBER_TABLE];
void updateTableID() {
    for (int i = 0; i < NUMBER_TABLE; i++) {
        list_table[i].id = i;
    }
}


void Manager::setup_table(int id_, vector<dish> dishes) {
    for (Table &t : list_table) {
        if (t.id == id_) {
            t.setup_table(dishes);
        }
    }
}

//Thêm món ăn
void Manager::add_dish(dish& new_dish) {
    switch (new_dish.type){
        case FOOD:
            new_dish.ID = "FOOD" + to_string(menu.getNumberFood() + 1);
            menu.addDish(new_dish);
            break;
        case DRINK:
            new_dish.ID = "DRINK" + to_string(menu.getNumberDrink() + 1);
            menu.addDish(new_dish);
            break;
        default:
            cout<<"Loai Do An khong hop le\n";
            break;
    }
}


// void Manager::edit_dish(string ID) {
//     for(auto& it : menu) {
//         if(it.ID == ID) {
//             int price;
//             cout << "Vui long nhap gia moi: "; cin >> price;
//             it.price = price;
//         } 
//     }
//     cout << "Khong tim thay mon an voi ID " << ID << endl;
// }

// void Manager::delete_dish(string ID) {
//     for (auto it = menu.begin(); it != menu.end(); ++it) {
//         if (it->ID == ID) {
//             menu.erase(it);
//             break;
//         }
//     }
// }

void Manager::print_menu() {
    cout << "Menu:\n";
    menu.print();
}

void show_all_table_info() {
    for (int i = 0; i < NUMBER_TABLE; i++) {
        list_table[i].show();
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    updateTableID();
    menu.print();

    Manager manager = Manager();
    dish d1(10, "Pho", FOOD);
    manager.add_dish(d1);

    cout << "Table: \n";
    show_all_table_info();
    manager.setup_table(0, {d1});
    manager.setup_table(4, {d1});
    cout << "Table: \n";
    show_all_table_info();

    cout << "------\n";
    menu.print();
    return 0;
}
