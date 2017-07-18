#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char myChar(int* c, int* d);

int main() {
  int a;
  int b;
  char c = myChar(&a, &b);

  printf("\nFirst value: %i\nSecond Value: %i\n", a, b);
  printf("The char is: %c\n", c);
}

char myChar(int* c, int* d) {
  char character;

  printf("Give me an int: ");
  scanf("%i", c);
  printf("\nGive me second int: ");
  scanf("%i", d);
  printf("\nGive me an letter or char: ");
  scanf(" %c", &character);
  printf("\n");
  return character;
}
