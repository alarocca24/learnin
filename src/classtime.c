#include<stdio.h>

int main(void) {

  unsigned int counter;
  int grade;
  int total;
  int avg;

  total = 0;
  counter = 1;

  while (counter <= 10) {

    printf("Enter grade: ");
    scanf("%d", &grade);
    total = total + grade;
    counter = counter + 1;

  }

  avg = total/10;

  printf("Class avg is %d\n", avg);

}
