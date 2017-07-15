#include<stdio.h>

int main() {
  int first;
  int second;

  do {
    printf("choose a digit:");
    scanf("%i", &first);
    printf("Choose another value:");
    scanf("%d", &second);
    printf("1st Digit:%d\n2nd Digit:%d\n", first, second);
  }
  while(second > first);
  printf("The second # was smaller, this ends the loop.\n");
}
