#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_SIZE = 25;
const int WORK_WEEK_MAX_HOURS = 40;

int userData(char name[5][MAX_SIZE], float *wage, float *hoursWorked) {
  int i;

  for (i=0; i < 5; i++) {

    printf("Enter name: ");
    scanf("%s", name[i]);
    if (strcmp(name[i], "-1") == 0) {
      return i;
    }
    printf("Enter hourly rate: ");
    scanf("%f", &wage[i]);
    if (wage[i] == -1) {
      return i;
    }
    printf("Enter hours worked: ");
    scanf("%f", &hoursWorked[i]);
    printf("\n");
    if (hoursWorked[i] == -1) {
      return i;
    }
  }
  return i;
}

float overTimeHrs(float hoursWorked, float wage) {
  float overtimeHrs;
  overtimeHrs = hoursWorked - WORK_WEEK_MAX_HOURS;
  return overtimeHrs;
}

float overtimePay(float hoursWorked, float wage) {
  float otPay, otRate;
  otRate = 1.5 * wage;
  otPay = overTimeHrs(hoursWorked, wage) * otRate;
  if (hoursWorked <= WORK_WEEK_MAX_HOURS) {
    otPay = 0;
  }
  return otPay;
}

float grossPay(float hoursWorked, float wage) {
  float gross, otHrs;
  otHrs = overTimeHrs(hoursWorked, wage);
  gross = hoursWorked * wage;

  if (hoursWorked <= WORK_WEEK_MAX_HOURS) {
    return gross;
  } else {
    gross = (WORK_WEEK_MAX_HOURS * wage) + (otHrs * (1.5 * wage));
    return gross;
  }
  return gross;
}

float basePay(float hoursWorked, float wage) {
  float basePayTotal=0;
  if (hoursWorked <= WORK_WEEK_MAX_HOURS) {
    basePayTotal = grossPay(hoursWorked, wage);
  } else {
    basePayTotal = grossPay(hoursWorked, wage) - overtimePay(hoursWorked, wage);
  }
  return basePayTotal;
}

float taxesPaid(float hoursWorked, float wage) {
  float taxRate = 0.2;
  return grossPay(hoursWorked, wage) * taxRate;
}

float netPay(float hoursWorked, float wage) {
  return grossPay(hoursWorked, wage) - taxesPaid(hoursWorked, wage);
}

int main() {
  char name[5][MAX_SIZE];
  float wage[5];
  float hoursWorked[5];
  int i;
  int maxLoop;
  float totalAll;

  maxLoop = userData(name, wage, hoursWorked);
  for (i=0; i < maxLoop; i++) {
    float gross, ot, base, tax, net;

    gross = grossPay(hoursWorked[i], wage[i]);
    ot = overtimePay(hoursWorked[i], wage[i]);
    base = basePay(hoursWorked[i], wage[i]);
    tax = taxesPaid(hoursWorked[i], wage[i]);
    net = netPay(hoursWorked[i], wage[i]);
    totalAll += net;

    printf("\nName: %s\nHourly: %0.2f\nHours Worked: %0.2f\n", name[i], wage[i], hoursWorked[i]);
    printf("Gross Pay: $%0.2f\n", gross);
    printf("Base Pay: $%0.2f\n", base);
    printf("Overtime Pay: $%0.2f\n", ot);
    printf("Taxes Paid: $%0.2f\n", tax);
    printf("--------------\n");
    printf("Net Pay: $%0.2f\n\n", net);
  }

  printf("Total Paid to All Employees = $%0.2f\n", totalAll);

}

//OUTPUT::
// Alexs-macbook-pro:c-class alexlarocca$ ./program3
// Enter name: Alex
// Enter hourly rate: 20
// Enter hours worked: 40
//
// Enter name: Robert
// Enter hourly rate: 13
// Enter hours worked: 55
//
// Enter name: Ari
// Enter hourly rate: 13
// Enter hours worked: 30
//
// Enter name: Gina
// Enter hourly rate: 15
// Enter hours worked: 50
//
// Enter name: Yael
// Enter hourly rate: 10
// Enter hours worked: 60
//
//
// Name: Alex
// Hourly: 20.00
// Hours Worked: 40.00
// Gross Pay: $800.00
// Base Pay: $800.00
// Overtime Pay: $0.00
// Taxes Paid: $160.00
// --------------
// Net Pay: $640.00
//
//
// Name: Robert
// Hourly: 13.00
// Hours Worked: 55.00
// Gross Pay: $812.50
// Base Pay: $520.00
// Overtime Pay: $292.50
// Taxes Paid: $162.50
// --------------
// Net Pay: $650.00
//
//
// Name: Ari
// Hourly: 13.00
// Hours Worked: 30.00
// Gross Pay: $390.00
// Base Pay: $390.00
// Overtime Pay: $0.00
// Taxes Paid: $78.00
// --------------
// Net Pay: $312.00
//
//
// Name: Gina
// Hourly: 15.00
// Hours Worked: 50.00
// Gross Pay: $825.00
// Base Pay: $600.00
// Overtime Pay: $225.00
// Taxes Paid: $165.00
// --------------
// Net Pay: $660.00
//
//
// Name: Yael
// Hourly: 10.00
// Hours Worked: 60.00
// Gross Pay: $700.00
// Base Pay: $400.00
// Overtime Pay: $300.00
// Taxes Paid: $140.00
// --------------
// Net Pay: $560.00
//
// Total Paid to All Employees = $2822.00
