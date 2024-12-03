#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee {
    char employeeCode[50];
    char employeeName[50];
    char dateOfJoining[15];
};

void initializeEmployee(struct Employee *emp, const char *code, const char *name, const char *date) {
    strcpy(emp->employeeCode, code);
    strcpy(emp->employeeName, name);
    strcpy(emp->dateOfJoining, date);
}

void parseDate(const char *date, int *day, int *month, int *year) {
    sscanf(date, "%2d-%2d-%4d", day, month, year);
}

int hasTenureOverThreeYears(int currentDay, int currentMonth, int currentYear, int joinDay, int joinMonth, int joinYear) {
    int yearsDifference = currentYear - joinYear;
    int monthsDifference = currentMonth - joinMonth;
    int daysDifference = currentDay - joinDay;

    if (daysDifference < 0) {
        monthsDifference--;
        daysDifference += 30;
    }
    if (monthsDifference < 0) {
        yearsDifference--;
        monthsDifference += 12;
    }

    return yearsDifference > 3 || (yearsDifference == 3 && (monthsDifference > 0 || daysDifference > 0));
}

void displayEmployeesWithTenure(struct Employee employees[], int size) {
    char currentDate[15];
    printf("Enter the current date (FORMAT DD-MM-YYYY): ");
    scanf("%s", currentDate);

    int currentDay, currentMonth, currentYear;
    parseDate(currentDate, &currentDay, &currentMonth, &currentYear);

    printf("\nEmployees with Tenure > 3 Years:\n");
    int count = 0;

    for (int i = 0; i < size; i++) {
        int joinDay, joinMonth, joinYear;
        parseDate(employees[i].dateOfJoining, &joinDay, &joinMonth, &joinYear);

        if (hasTenureOverThreeYears(currentDay, currentMonth, currentYear, joinDay, joinMonth, joinYear)) {
            count++;
            printf("Employee Name: %s\n", employees[i].employeeName);
            printf("Employee Code: %s\n", employees[i].employeeCode);
            printf("Date of Joining: %s\n", employees[i].dateOfJoining);
            printf("-----------------------------\n");
        }
    }

    printf("Total Employees with Tenure > 3 Years: %d\n", count);
}

int main() {
    struct Employee employees[4];
    char tempCode[50], tempName[50], tempDate[15];

    for (int i = 0; i < 4; i++) {
        printf("Enter Employee %d's Code: ", i + 1);
        scanf("%s", tempCode);
        getchar();

        printf("Enter Employee %d's Name: ", i + 1);
        fgets(tempName, sizeof(tempName), stdin);
        tempName[strcspn(tempName, "\n")] = '\0';

        printf("Enter Employee %d's Date of Joining (FORMAT DD-MM-YYYY): ", i + 1);
        scanf("%s", tempDate);

        initializeEmployee(&employees[i], tempCode, tempName, tempDate);
    }

    displayEmployeesWithTenure(employees, 4);

    return 0;
}
