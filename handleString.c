#include <stdio.h>
#include <stdbool.h>

int Size(char string[]) {
    int count = 0;
    while(string[count] != '\0') {
        count++;
    }
    return count;
}

//Yêu cầu 2: In hoa chuỗi sau dấu '.'
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

void Request2(char str[], int lengStr, char target[], int lengTar) {
    bool val = true;
    for(int i = 0; i < lengStr; i++) {
        int count = 0;
        for(int j = 0; j < lengTar; j++) {
            if(target[j] == str[i + j]) {
                count++;
            }
        }
        if(count == lengTar) {
            if(val) {
                printf("Trung o vi tri: ");
                val = false;
            }
            printf("%d ", i);
            if(i > i + 1) {
                printf("%d ", i);
            }
        }
    }
}

int main() {
    char string[]= "to learn around the world learn how to do anything. today we learn ab that!";
    int lengStr = Size(string);

    //Yêu cầu 1
    //Request1(string, lengStr);

    //Yêu cầu 2
    char target[] = "to";
    int lengTar = Size(target);
    Request2(string, lengStr, target, lengTar);

}