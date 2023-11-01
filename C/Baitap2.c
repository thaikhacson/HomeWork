#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int main() {
    int arr[] = {1,2,3,2,3,4};
    // char target [5];
    // scanf("%s", &target);s

    //Tinh do dai cua arr
    int size = sizeof(arr) / sizeof(arr[0]);
    //Tinh do dai cua target
    // int target_len = 0;
    // while(target[target_len] != 0) {
    //     target_len++;
    // }

    
    for(int i = 0; i < size; i++) {
        //bool match = true;
        int count = 1;
        for(int j = i + 1; j <size; j++) {
            //  if(arr[i+j] != arr[j]) {
            //     match = false;
            //     break;
            if(arr[i] == arr[j]) {
                count++;
                swap(&arr[i+1], &arr[j]);
                i++;
            }
        }
        (count == 1)? printf("%d appears 1 time\n", arr[i]) : printf("%d appears %d times\n", arr[i], count);
    }
        // if(match) {
        //     count++;
        // }
    return 0;
}

