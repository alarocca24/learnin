#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int WORK_WEEK_MAX_HOURS=40;
const int MAX_NAME=25;

int overTimeHrs(float hoursWorked, float payRate) {
  float overtimeHrs;
  overtimeHrs = hoursWorked - WORK_WEEK_MAX_HOURS;
  return overtimeHrs;
}

int overtimePay(float hoursWorked, float payRate) {
  float otPay, otRate;
  otRate = 1.5 * payRate;
  otPay = overTimeHrs(hoursWorked, payRate) * otRate;
  return otPay;
}

int grossPay(float hoursWorked, float payRate) {
  float gross, otHrs, totalPay;
  otHrs = overTimeHrs(hoursWorked, payRate);

  if (hoursWorked <= WORK_WEEK_MAX_HOURS) {
    gross = hoursWorked * payRate;
  } else {
    gross = hoursWorked * payRate;
    gross += (otHrs * (1.5 * payRate));
  }
  totalPay = hoursWorked * payRate;
  return gross;
}

int basePay(float hoursWorked, float payRate) {
  float basePayTotal=0;
  if (hoursWorked <= WORK_WEEK_MAX_HOURS) {
    basePayTotal = grossPay(hoursWorked, payRate);
  } else {
    basePayTotal = grossPay(hoursWorked, payRate) - overtimePay(hoursWorked, payRate);
  }
  return basePayTotal;
}

int taxesPaid(float hoursWorked, float payRate) {
  float taxRate = 0.2;
  return grossPay(hoursWorked, payRate) * taxRate;
}

int netPay(float hoursWorked, float payRate) {
  return grossPay(hoursWorked, payRate) - taxesPaid(hoursWorked, payRate);
}

int main() {
  char name[MAX_NAME][5];
  float payRate[5];
  float hoursWorked[5];
  int maxLoop = 5;
  int i=0;

  for (i=0; i < maxLoop; i++) {

    printf("Enter name: ");
    scanf("%s", &name[0][i]);
    if (strcmp(name, "-1") == 0) {
      break;
    }
    printf("Enter hourly rate: ");
    scanf("%f", &payRate[i]);
    if (payRate[i] == -1) {
      break;
    }
    printf("Enter hours worked: ");
    scanf("%f", &hoursWorked[i]);
    printf("\n");
    if (hoursWorked[i] == -1) {
      break;
    }
  }

  for (i=0; i < maxLoop; i++) {
    float gross, ot, base, tax, net;

    gross = grossPay(hoursWorked[i], payRate[i]);
    ot = overtimePay(hoursWorked[i], payRate[i]);
    base = basePay(hoursWorked[i], payRate[i]);
    tax = taxesPaid(hoursWorked[i], payRate[i]);
    net = netPay(hoursWorked[i], payRate[i]);

    printf("\nPay To: %s\n", name[MAX_NAME][i]);
    printf("Hours Worked: %0.2f\n", hoursWorked[i]);
    printf("Hourly Rate: $%0.2f\n", payRate[i]);
    printf("Gross Pay: $%0.2f\n", gross);
    printf("Base Pay: $%0.2f\n", base);
    printf("Overtime Pay: $%0.2f\n", ot);
    printf("Taxes Paid: $%0.2f\n\n", tax);
    printf("--------------\n");
    printf("Net Pay: $%0.2f\n", net);
  }
}
