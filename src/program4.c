#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int WORK_WEEK_MAX_HOURS = 40;

typedef struct
{
  char name[25];
  float hourlyWage;
  float hoursWorked;
}Employee;

Employee employees[5];

//input single employee function
//calling malloc so need to free memory before each return.
Employee* inputEmployee()
{
  Employee *em = malloc(sizeof(Employee));
  printf("Enter Employee Name: ");
  scanf("%s", em->name);
  if (strcmp(em->name, "-1") == 0)
  {
    free(em);
    return NULL;
  }
  printf("Enter hourly rate: ");
  scanf("%f", &(em->hourlyWage));
  if (em->hourlyWage == -1)
  {
    free(em);
    return NULL;
  }
  printf("Enter hours worked: ");
  scanf("%f", &(em->hoursWorked));
  printf("\n");
  if (em->hoursWorked == -1)
  {
    free(em);
    return NULL;
  }
  return em;
}


//calls inputEmployee() so that it can create entries for 5 employees instead of 1.
int createEmployees()
{
  int i;

  for (i=0; i < 5; i++)
  {
    Employee *em = inputEmployee();
    if(em == NULL)
    {
      return i;
    } else {
      employees[i] = *em;
    }
  }
  return i;
}

void modifyEmployee(int maxLoop)
{
  int employeeEdit;

  printf("----------------------------------\n");

  for(int i=0; i < maxLoop; i++)
  {
    printf("%d.%s\n", i, employees[i].name);
  }

  printf("----------------------------------\n");
  printf("Which Employee Data would you like to update?(-1 to return): ");

  scanf("%i", &employeeEdit);
  if(employeeEdit == -1)
  {
    return;
  }
  printf("Enter Information to replace Employee %d\n", employeeEdit);
  Employee *em = inputEmployee();
  if(em == NULL)
  {
    return;
  } else {
    employees[employeeEdit] = *em;
  }
}

//gross pay function
float gross(Employee *em)
{
  float grossPay;
  float overtimeHrs = 0;

  if (em->hoursWorked <= WORK_WEEK_MAX_HOURS)
  {
    grossPay = em->hourlyWage * em->hoursWorked;
  } else {
    overtimeHrs = em->hoursWorked - WORK_WEEK_MAX_HOURS;
    grossPay = (WORK_WEEK_MAX_HOURS * em->hourlyWage)
             + (overtimeHrs * (1.5 * em->hourlyWage));
  }
  return grossPay;
}

//taxes to employee
float tax(Employee *em)
{
  float tax;
  float taxRate = 0.2;

  tax = gross(em) * taxRate;
  return tax;
}

//overtime pay
float ot(Employee *em)
{
  float otPay, otRate;
  float otHours = 0;

  if (em->hoursWorked <= WORK_WEEK_MAX_HOURS) {
    otPay = 0;
  } else {
  otHours = em->hoursWorked - WORK_WEEK_MAX_HOURS;
  otRate = 1.5 * em->hourlyWage;
  otPay = otHours * otRate;
  }
  return otPay;
}


//base pay without counting the overtime
float base(Employee *em)
{
  float basePay;

  if (em->hoursWorked <= WORK_WEEK_MAX_HOURS) {
    basePay = em->hoursWorked * em->hourlyWage;
  } else {
    basePay = WORK_WEEK_MAX_HOURS * em->hourlyWage;
  }
  return basePay;
}

//net pay for employee after taxes has been removed and overtime has been calculated
float net(Employee *em) {
  float netPay;

  netPay = gross(em) - tax(em);
  return netPay;
}

//prints data for one or multiple employees
void prntData(int maxLoop)
{
  int employeePrint;

  printf("Which Employee would you like to print?(-1 to return)\n");
  printf("---------------------------------\n");

  for(int i=0; i < maxLoop; i++)
  {
    printf("%d.%s\n", i, employees[i].name);
  }
  printf("5.Print All Employees\n");
  printf("---------------------------------\n");

  scanf("%i", &employeePrint);
  if(employeePrint == -1)
  {
    return;
  }
  if(employeePrint == 5)
  {
    for(int i=0; i < maxLoop; i++)
    {
      printf("\nName: %s\nHourly: %0.2f\nHours Worked: %0.2f\n", employees[i].name,
                                                         employees[i].hourlyWage,
                                                       employees[i].hoursWorked);
      printf("Gross Pay: $%0.2f\n", gross(&employees[i]));
      printf("Base Pay: $%0.2f\n", base(&employees[i]));
      printf("Overtime Pay: $%0.2f\n", ot(&employees[i]));
      printf("Taxes Paid: $%0.2f\n", tax(&employees[i]));
      printf("--------------\n");
      printf("Net Pay: $%0.2f\n\n", net(&employees[i]));
    }
  }
  printf("\nName: %s\nHourly: %0.2f\nHours Worked: %0.2f\n", employees[employeePrint].name,
                                                       employees[employeePrint].hourlyWage,
                                                     employees[employeePrint].hoursWorked);

  printf("Gross Pay: $%0.2f\n", gross(&employees[employeePrint]));
  printf("Base Pay: $%0.2f\n", base(&employees[employeePrint]));
  printf("Overtime Pay: $%0.2f\n", ot(&employees[employeePrint]));
  printf("Taxes Paid: $%0.2f\n", tax(&employees[employeePrint]));
  printf("--------------\n");
  printf("Net Pay: $%0.2f\n\n", net(&employees[employeePrint]));
  }

//menu function so you can select different options
void Menu()
{
  int menu;
  int maxLoop;

  while (1)
  {
  printf("\n\n1] Create Records\n");
  printf("2] Print Records\n");
  printf("3] Edit Records\n");
  printf("4] Exit\n");

  printf("\nEnter your choice: \n");
  scanf("%d", &menu);

    switch (menu)
    {
    case 1:
      maxLoop = createEmployees();
      break;
    case 2:
      prntData(maxLoop);
      break;
    case 3:
      modifyEmployee(maxLoop);
      break;
    case 4:
    default:
      printf("Exiting the Program!!\n");
      exit(0);
    }
  }
}


int main()
{
  Menu();
}
