#include <iostream>
#include <string>
using namespace std;

string* splitStr (string str, int& count) {
    string* arr = new string[1000];
    string word = "";
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] != ' ') {
            word += str[i];
        } else {
            arr[count] = word;
            word = "";
            count++;
        }
        if(str[i + 1] == 0) {
            arr[count] = word;
            count++;
        }
    }
    return arr;
}

struct word {
    string name;
    int quantity;
};

bool is_equal(string str1, string str2) {
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) return false;
    }
    return true;
}

int main() {

    string str_q = "mot hai ba mot";
    word results[1000];
    int res_size = 0;
    int words_count = 0;
    string* splitted = splitStr(str_q, words_count);

    for (int i = 0; i < words_count; i++) {
        bool found = false;
        for (int j = 0; j < res_size; j++) {
            if (is_equal(results[j].name, splitted[i])) {
                results[j].quantity++;
                found = true;
            }
        }

        if (!found) {
            results[res_size].name = splitted[i];
            results[res_size].quantity = 1;
            res_size++;
        }
    }
    
    for (int i = 0; i < res_size; i++) {
        cout << results[i].name << " xuat hien " << results[i].quantity << " lan!\n";
    }

    //*****************************************************************************
    // for (int i = 0; i < words_count; i++) {
    //     my_map[splitted[i]]++;
    // }
    
    // for (auto w : my_map) {
    //     cout << w.first << " xuat hien " << w.second << " lan!\n";
    // }
    //*****************************************************************************
    return 0; 
}
