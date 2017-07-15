#include<stdio.h>

int myInt(int magicDigit) {
  int guess;

  printf("Guess the magic intiger: ");
  scanf("%i", &guess);

  if (guess < magicDigit) {
    return -1;
  }
  else if (guess == magicDigit) {
    return 0;
  } else {
    return 1;
  }
  //printf("%i", guess);
}


int main() {
  int magicDigit=45;

  int myret=myInt(magicDigit);
  printf("%d\n", myret);
  return myret;
  //printf("%d\n", myInt(magicDigit));
  //return 0;
  //printf("%i", myInt(magicDigit);
}
