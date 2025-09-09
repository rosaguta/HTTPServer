#include <stdio.h>

int main(){
  char ObiWan[] = "Hello there";
  printf("Obi Wan in that one episode: %s\n", ObiWan);
  
  char incompleteGreetings[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
  printf("huh? %s\n", incompleteGreetings);

  /* 
  here follows an example of an unsafe sequence of chars
  that exposes the TOPSECRET message because
  there is no terminating byte (\0) in the string
  */
  char unsafe[] = {'H','i','!'};
  char secret[] = "TOPSECRET";

  printf("Unsafe string: %s\n", unsafe);

  return 0;
}