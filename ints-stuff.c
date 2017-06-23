#include<stdio.h>
#include<stdlib.h>

int main() {

  printf("Pick 3 numbers \n");
  float first = 0, second = 0, third = 0;
  float sum = 0;
  float avg = 0;
  scanf("%f %f %f", &first, &second, &third);
  sum = first + second + third;
  avg = sum / 3;
  printf("sum = %f and average = %f\n", sum, avg);

  system("read -n 1 -s -p\"Press any key to continue...\"");

}
