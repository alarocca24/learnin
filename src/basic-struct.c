#include<stdio.h>

  struct coolBeans {
    float firstDigit;
    float secondDigit;
    float thirdDigit;
    float avg;
  };

int main() {
  struct coolBeans c;

  printf("First Digit: ");
  scanf("%f", &c.firstDigit);
  printf("Second Digit: ");
  scanf("%f", &c.secondDigit);
  printf("Third Digit: ");
  scanf("%f", &c.thirdDigit);

  c.avg = (c.firstDigit + c.secondDigit + c.thirdDigit) / 3;

  printf("%6.2f\n", c.avg);
}
