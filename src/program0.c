#include<stdio.h>

int main() {

  int x=0, y=0;
  int sum = 0;
  int sub = 0;
  float divi = 0.0;
  int mult = 0;

  printf("\n");
  printf("My name is Alex Larocca, I'm in course #60375. I've taken:\n");

  printf("-Intro to Programming Online\n");
  printf("-Currently working in the field & learning on the job :D\n");
  printf("\n");

  printf("Pick first value:");
  scanf("%i", &x);
  printf("Pick second value:");
  scanf("%i", &y);

  sum = x + y;
  sub = x - y;
  divi = (float)x / y;
  mult = x * y;

  printf("\n");
  printf("The sum is:%i\n", sum);
  printf("The difference is:%i\n", sub);
  printf("The quotient is:%f\n", divi);
  printf("The product is:%i\n", mult);

}
