#include <stdio.h>
// from https://www.geeksforgeeks.org/c/applications-of-pointers-in-c-cpp/

// function to print an array by passing reference to array
// because a pointer gets used to access the array
// a copy of the array will not get created because 
// it has the memory address of that array
void printArray(int *arr, int n)
{
  // here array elements are passed by reference
  for (int i = 0; i < n; i++)
  {
    printf("%d\n", arr[i]);
  }
}

int main()
{
  int myAge = 22;
  printf("memory address of myAge: %p\n", &myAge);


  // from https://www.geeksforgeeks.org/c/applications-of-pointers-in-c-cpp/
  int arr[5] = {1, 2, 3, 4, 5};
  printArray(arr, 5);
  return 0;
}