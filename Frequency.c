#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    char* ptr;
    uint8_t length;
    uint8_t frequency;
    bool status;
}Word;

int sizeStr(char str[]) {
    int count = 0;
    while(str[count] != '\0') {
        count++;
    }
    return count;
}

Word* splitString (char str[], uint8_t size, Word array[]) {
    uint8_t count = 0;
    uint8_t index = 0;
    //Word* array = (Word*)malloc(size * sizeof(Word));
    array[index].ptr = str;

    while(*str != '\0') {
        if(*str == ' ') {
            array[index].length = count;
            count = 0;
            index++;
            str++;
            array[index].ptr = str;
        } else {
            count++;
            str++;
        }
    }

    array[index].length = count;
    array[index + 1].ptr = '\0';
    return array;
}

void print(Word array[], uint8_t size) {
    for(uint8_t i = 0; i < size; i++) {
        for(uint8_t j = 0; j < array[i].length; j++) {
            printf("%c", array[i].ptr[j]);
        }
        printf(" ");
    }
}


int main () {
    char str[] = "Nam Hoang Bao Nam Hoang Yen Anh Son";
    uint8_t size = sizeStr(str);
    Word array[size];
    splitString (str, size, array);
    print(array, size);

}