#include <stdio.h>

int main() {
    int ages[] = {20, 22, 18, 35, 48, 26, 87, 70};
    // To get the length of the array, divide the total size of the array in bytes
    // (sizeof(numbers)) by the size of a single element (sizeof(numbers[0])).
    // This works regardless of the element type or its size on the platform.
    int lengthOfArray = sizeof(ages) / sizeof(ages[0]); 

    printf("length of array = %d\n", lengthOfArray);
    
    int lowestAge = ages[0];
    for (int i = 0; i < lengthOfArray; i++){
        if(lowestAge > ages[i]){
            lowestAge = ages[i];
        }
    }
    printf("lowest age in the array is %d\n", lowestAge);


    return 0;
}
