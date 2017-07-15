#include<stdio.h>
#include<math.h>

int main(void) {

  double principal, rate, amount;
  unsigned int years;

  principal=1000.0;
  rate=0.05;

  for(years=1; years <= 10; ++years) {

    amount = principal * pow(1.0+rate, years);
    printf("Year:%i %.2f\n", years, amount);
  }
}
