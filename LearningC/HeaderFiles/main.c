#include <stdio.h>
#include "math.h"

int main()
{
    int resultSum = sum(1, 2);
    int resultSub = sub(1, 2);
    int resultMultiply = multiply(23, 2);
    double resultDivide = divide(5,2);

    printf("resultSum: %d\n", resultSum);
    printf("resultSub: %d\n", resultSub);
    printf("resultMultiply: %d\n", resultMultiply);
    printf("resultDivide: %.1f\n", resultDivide);
    printf("----------------------\n");

    int myInt;
    float myFloat;
    double myDouble;
    char myChar;
    char myCharArr[] = "haiiii";

    printf("size of INT: %zu\n", sizeof(myInt));
    printf("size of FLOAT: %zu\n", sizeof(myFloat));
    printf("size of DOUBLE: %zu\n", sizeof(myDouble));
    printf("size of CHAR: %zu\n", sizeof(myChar));
    printf("size of CHAR_ARRAY: %zu\n", sizeof(myCharArr));
    
    return 0;
}