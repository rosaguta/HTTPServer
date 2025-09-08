#include <stdio.h>
#include <limits.h>
int main(){
    unsigned previousNumber = 0;
    unsigned currentNumber = 1;
    int maxLoop = 100;
    int currentloop = 0; 
    while(currentloop < maxLoop){
        if (previousNumber > UINT_MAX - currentNumber) {
            printf("Overflow would occur at iteration %d\n", currentloop + 1);
            break;
        }
        
        unsigned long long result = previousNumber + currentNumber;
        printf("fib: %llu\n", result);
        previousNumber = currentNumber;
        currentNumber = result;
        currentloop++;
    };
    return 0;
}