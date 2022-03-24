#include <stdio.h>

int Out(void){
  printf("Hello from io.c\n");
  return 0;
}

int In(void){
  char name[20];
  printf("Hello. What's your name?\n");
  fgets(name,20,stdin);
  printf("Hi there, %s", name);
  return 0;
}
