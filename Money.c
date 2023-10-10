#include <stdio.h>
#include <stdint.h>

#define TRAM 0
#define CHUC 2
#define DONVI 1

int Size_length(char money[]) {
    int i = 0;
    while(money[i] != '\0') {
        i++;
    }
    return i;
}

void Print(char money[], int index, int unit ) {

    switch (money[index])
    {
    case '0':
        if(unit == TRAM) {printf("Khong ");}
        else if(unit == CHUC && money[index + 1] != '0') {printf("Le ");}
        break;
    case '1':
        if(unit == TRAM) {printf("Mot ");} //Một
        else if(unit == CHUC) {printf("Muoi ");} //Mươi
        else if(unit == DONVI && money[index - 1] != '0' && money[index - 1] != '1' && index > 0) {printf("Mot ");} //Mốt
        //else if(unit == DONVI && money[index - 1] == '0' || money[index - 1] == '1' && index > 0) {printf("Mot ");} //Một
        else {printf("Mot ");}
        break;
    case '2':
        printf("Hai "); 
        break;
    case '3':
        printf("Ba ");
        break;
    case '4':
        printf("Bon ");
        break;
    case '5':
        if(unit == DONVI && money[index - 1] != '0') {printf("Lam ");}
        else {printf("Nam ");}
        break;
    case '6':
        printf("Sau ");
        break;
    case '7':
        printf("Bay ");
        break;
    case '8':
        printf("Tam ");
        break;
    case '9':
        printf("Chin ");
        break;
    }
}

int main() {
    char money[] = "1245863986"; 
    int Size = Size_length(money);
    uint8_t location;
    for(int index = 0; index < Size; index++) {
        int unit = ((Size- index) % 3);
        Print(money, index, unit);
        switch (unit)
        {
        case TRAM:
            printf("Tram ");
            break;
        case CHUC:
            if(money[index] != '0' && money[index] != '1') {printf("Muoi ");} //Mươi
            break;
        case DONVI:
            location = Size - index;
            if(location == 10) {printf("Ty ");}
            if(location == 7) {printf("Trieu ");}
            if(location == 4) {printf("Nghin ");}
            if(location == 1) {printf("Dong\n");}
            break;
         }
    }
    return 0;
}