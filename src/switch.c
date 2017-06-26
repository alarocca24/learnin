#include<stdio.h>
#include<stdlib.h>

int main() {

  char c=0;

  printf("Choose your car!...oops I mean char\n");
  scanf("%c", &c);

  switch(c)
  {

    case 'y': case 'Y':
      printf("Sometimes\n");
      break;

    case 'a': case 'e': case 'i': case 'o': case 'u':
    case 'A': case 'E': case 'I': case 'O': case 'U':
      printf("Vowel\n");
      break;

    default:
      printf("Consonant\n");
      break;

  }

  printf("Ah, %c, classy choice\n", c);

}
