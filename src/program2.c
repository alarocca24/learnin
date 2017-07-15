#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int WORK_WEEK_MAX_HOURS=40;
const int MAX_NAME=25;

int overTime(float hoursWorked, float payRate) {
  float overtimeHrs, overtimePay;
  overtimeHrs = hoursWorked - WORK_WEEK_MAX_HOURS;
  overtimePay = overtimeHrs * (payRate * 1.5);
  return overtimePay;
}

int grossPay(float hoursWorked, float payRate) {
  float totalPay;
  totalPay = hoursWorked * payRate;

  if (hoursWorked > WORK_WEEK_MAX_HOURS) {
    totalPay += overTime(hoursWorked, payRate);
  }else {
    return totalPay;
  }
  return totalPay;
}


int basePay()  {
  float basePayTotal;
  basePayTotal = grossPay() - overTime();
  return basePayTotal;
}


int taxesPaid() {
  float taxRate = 0.2;
  return grossPay() * taxRate;
}

int netPay() {
  return grossPay() - taxesPaid();
}

int main() {
  char name[MAX_NAME][5];
  float payRate[5];
  float hoursWorked[5];
  int maxLoop = 5;
  int i=0;

  for (i=0; i < maxLoop; i++) {

    printf("Enter name: ");
    scanf("%s", &name[i]);
    if (strcmp(name[i], "-1") == 0) {
      break;
    }
    printf("\nEnter hourly rate: ");
    scanf("%f", &payRate[i]);
    if (payRate[i] == -1) {
      break;
    }
    printf("\nEnter hours worked: ");
    scanf("%f", &hoursWorked[i]);
    printf("\n");
    if (hoursWorked[i] == -1) {
      break;
    }
  }

  maxLoop = i;

  for (i=0; i < maxLoop; i++) {
      printf("Pay To: %s\n", name[i]);
      printf("Hours Worked: %0.2f\n", payRate[i]);
      printf("Hourly Rate: $%0.2f\n", hoursWorked[i]);
      printf("Gross Pay: $%0.2f\n", grossPay(hoursWorked[i], payRate[i]));
      printf("Base Pay: $%0.2f\n", basePay());
      printf("Overtime Pay: $%0.2f", overTime(hoursWorked[i], payRate[i]));
      printf("Taxes Paid: $%0.2f", taxesPaid());
      printf("Net Pay: $%0.2f", netPay());
  }
}
