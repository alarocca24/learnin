#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
  FILE *fPntr;
  char filename[30];
  char c[3000];

  printf("Enter file name: \n");
  scanf("%29s", filename);

  fPntr = fopen(filename, "a+");

  if(fPntr == NULL) {
    printf("File does not exist\n");
    return 0;
  }

  while(fgets(c, sizeof(c), stdin)) {
    fprintf(fPntr, "%s", c);
  }

  fclose(fPntr);

  return 0;
}
