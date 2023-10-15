#include <stdio.h>
#include <stdbool.h>

int Size(char string[]) {
    int count = 0;
    while(string[count] != '\0') {
        count++;
    }
    return count;
}

//Yêu cầu 1: In hoa chuỗi sau dấu '.'
void Request1(char str[], int length) {
    int i = 0;
    while(str[i] != '.') {
        printf("%c", str[i]);
        i++;
        if(str[i] == '.') {printf(".");}
    }
    while(str[i] != '\0') {
        if(str[i] != ' ') {
            printf("%c", str[i] - 32);
            if(str[i] == '!') {printf("!");}
        } else {
            printf(" ");    
        }
        i++;
    }
}

//Yêu cầu 2:
void Request2(char str[], char target[]) {
    bool val = false;
    for(int i = 0; i < Size(str); i++) {
        int count = 0;
        for(int j = 0; j < Size(target); j++) {
            if(target[j] == str[i + j]) {
                count++;
            }
        }
        if(count == Size(target)) {
            if(!val) {
                val = true;
                printf("Trung o vi tri: ");
            }
            printf("%d ", i);
        }
    }
    if(!val) { 
        printf("Khong tim thay!");
    }
}

//Yêu cầu 3:
void Request3(char str[], char Find[], char Replace[]) {
    int i = 0;
    int j = 0;
    while(str[i] != '\0') {
        if(str[i] == Find[j]) {
            j++;
            if(Find[j] == '\0') {
                break;
            }
        } else if(j > 0) {
            j = 0;  
        }
        i++;
    }
    
    int location_Fist = i - j + 1;
    int location_Final = i;
    int length_Update = Size(str) - Size(Find) + Size(Replace);

    while(*Replace != '\0') {
        str[location_Fist] = *Replace;
        location_Fist++;
        Replace++;
    }
    location_Final++;
    while(location_Fist < length_Update) {
        str[location_Fist] = str[location_Final];
        location_Fist++;
        location_Final++;
    }
    str[length_Update] = '\0';
    printf("%s", str);
}

//Yêu cầu 4:
void Request4(char str[], char Find[], char Replace[]) {
    int i = 0;
    int j = 0;
    while(str[i] != '\0') {
        if(str[i] == Find[j]) {
            j++;
            if(Find[j] == '\0') {
                break;
            }
        } else if(j > 0) {
            j = 0;   
        }
        i++;
    }
    int location_Fist = i - j + 1;
    int location_Final = i;
    int length_Update = Size(str) - Size(Find) + Size(Replace);
    int location = Size(str) - 1;

    if(length_Update > Size(str)) {
        str[length_Update] = '\0';
        length_Update--;
        while(length_Update > location_Fist + Size(Replace) - 1) {
            str[length_Update] = str[location];
            length_Update--;
            location--;
        }
        while(*Replace != '\0') {
        str[location_Fist] = *Replace;
        location_Fist++;
        Replace++;
    }
    }
    printf("%s", str);
}


int main() {
    char str[]= "to learn around the world learn how to do anything. today we learn ab that!";
    int lengStr = Size(str);

    //Yêu cầu 1
    //Request1(string, str);

    //Yêu cầu 2
    char target[] = "learn";
    //Request2(str, target);

    //Yêu cầu 3
    char Replace1[] = "to";
    char Find1[] = "world learn";
    //Request3(str, Find1, Replace1);

    //Yêu cầu 4
    char Replace2[] = "anything";
    char Find2[] = "the";
    Request4(str, Find2, Replace2);
    
}