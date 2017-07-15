#include<stdio.h>
const int WORK_WEEK_MAX_HOURS=40;
const int MAX_NAME=20;

float addOT(float workedHours, float hourly) {
  float overtimeHrs, overtimeRate, overtimePaid;

  overtimeHrs = workedHours - WORK_WEEK_MAX_HOURS;
  overtimeRate = (hourly * 1.5);
  overtimePaid = overtimeRate * overtimeHrs;
  return overtimePaid;
}

int main() {
  char name[MAX_NAME];
  float hourly, workedHours, amountPaid, taxesPaid, takeHome, biweekly, monthly, taxes=0.2;
  unsigned int i;

  for(i=1; i <= 5; i++) {
    printf("\nEnter name: ");
    scanf("%s", &name[0]);
    printf("Enter hourly rate: ");
    scanf("%f", &hourly);
    printf("Enter hours worked this week: ");
    scanf("%f", &workedHours);
    printf("\n");

    if (workedHours > WORK_WEEK_MAX_HOURS) {
      amountPaid = hourly * WORK_WEEK_MAX_HOURS;
      amountPaid += addOT(workedHours, hourly);
    } else {
      amountPaid = hourly * workedHours;
    }
    taxesPaid = amountPaid * taxes;
    takeHome = amountPaid - taxesPaid;
    biweekly = takeHome * 2;
    monthly = biweekly * 2;

    printf("Pay to: %s\n", name);
    printf("Hourly Rate: %.2f\n", hourly);
    printf("Hours Worked: %.2f\n", workedHours);
    printf("Amount Paid: $%.2f\n", amountPaid);
    printf("Taxes Paid: $%.2f\n", taxesPaid);
    printf("Take Home Weekly: $%.2f\n", takeHome);
    printf("Take Home Bi-Weekly: $%.2f\n", biweekly);
    printf("Take Home Monthly: $%.2f\n\n", monthly);
  }
}

//output:
//-----------------
// Alexs-macbook-pro:c-class alexlarocca$ ./program1
//
// Enter name: Alex
// Enter hourly rate: 10
// Enter hours worked this week: 40
//
// Pay to: Alex
// Hourly Rate: 10.00
// Hours Worked: 40.00
// Amount Paid: $400.00
// Taxes Paid: $80.00
// Take Home Weekly: $320.00
//
// Enter name: Bob
// Enter hourly rate: 10
// Enter hours worked this week: 50
//
// Pay to: Bob
// Hourly Rate: 10.00
// Hours Worked: 50.00
// Amount Paid: $550.00
// Taxes Paid: $110.00
// Take Home Weekly: $440.00
//
// Enter name: Dario
// Enter hourly rate: 20
// Enter hours worked this week: 45
//
// Pay to: Dario
// Hourly Rate: 20.00
// Hours Worked: 45.00
// Amount Paid: $950.00
// Taxes Paid: $190.00
// Take Home Weekly: $760.00
//
// Enter name: Ari
// Enter hourly rate: 14
// Enter hours worked this week: 23
//
// Pay to: Ari
// Hourly Rate: 14.00
// Hours Worked: 23.00
// Amount Paid: $322.00
// Taxes Paid: $64.40
// Take Home Weekly: $257.60
//
// Enter name: Joanna
// Enter hourly rate: 20
// Enter hours worked this week: 60
//
// Pay to: Joanna
// Hourly Rate: 20.00
// Hours Worked: 60.00
// Amount Paid: $1400.00
// Taxes Paid: $280.00
// Take Home Weekly: $1120.00
//
