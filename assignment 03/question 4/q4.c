#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int *ratings;
    int totalScore;
};

void inputRatings(struct Employee *emp, int numPeriods) {
    emp->ratings = (int*)malloc(numPeriods * sizeof(int));
    int rating;

    for (int i = 0; i < numPeriods; i++) {
        do {
            printf("Enter rating for Period %d (1-10): ", i + 1);
            scanf("%d", &rating);
            if (rating < 1 || rating > 10) {
                printf("Invalid rating. Please enter a value between 1 and 10.\n");
            }
        } while (rating < 1 || rating > 10);

        emp->ratings[i] = rating;
        emp->totalScore += rating;
    }
}

void displayEmployeeRatings(struct Employee *emp, int numPeriods) {
    printf("Performance Ratings: ");
    for (int i = 0; i < numPeriods; i++) {
        printf("%d ", emp->ratings[i]);
    }
    printf("\n");
}

int findEmployeeOfTheYear(struct Employee *employees, int numEmployees, int numPeriods) {
    int maxAvg = 0, employeeIndex = -1;

    for (int i = 0; i < numEmployees; i++) {
        int avg = employees[i].totalScore / numPeriods;
        if (avg > maxAvg) {
            maxAvg = avg;
            employeeIndex = i;
        }
    }
    return employeeIndex;
}

int findHighestRatedPeriod(struct Employee *employees, int numEmployees, int numPeriods) {
    int maxAvg = 0, periodIndex = -1;

    for (int i = 0; i < numPeriods; i++) {
        int totalScore = 0;
        for (int j = 0; j < numEmployees; j++) {
            totalScore += employees[j].ratings[i];
        }
        int avg = totalScore / numEmployees;
        if (avg > maxAvg) {
            maxAvg = avg;
            periodIndex = i;
        }
    }
    return periodIndex;
}

int findWorstPerformingEmployee(struct Employee *employees, int numEmployees, int numPeriods) {
    int minAvg = 10, employeeIndex = -1;

    for (int i = 0; i < numEmployees; i++) {
        int avg = employees[i].totalScore / numPeriods;
        if (avg < minAvg) {
            minAvg = avg;
            employeeIndex = i;
        }
    }
    return employeeIndex;
}

int main() {
    int numEmployees, numPeriods;

    printf("Enter number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter number of evaluation periods: ");
    scanf("%d", &numPeriods);

    struct Employee *employees = (struct Employee*)malloc(numEmployees * sizeof(struct Employee));

    for (int i = 0; i < numEmployees; i++) {
        employees[i].totalScore = 0;
        printf("\nEmployee %d\n", i + 1);
        inputRatings(&employees[i], numPeriods);
    }

    printf("\nEmployee Ratings:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d: ", i + 1);
        displayEmployeeRatings(&employees[i], numPeriods);
    }

    int employeeOfTheYear = findEmployeeOfTheYear(employees, numEmployees, numPeriods);
    printf("\nEmployee of the Year: Employee %d\n", employeeOfTheYear + 1);

    int highestRatedPeriod = findHighestRatedPeriod(employees, numEmployees, numPeriods);
    printf("\nHighest Rated Evaluation Period: Period %d\n", highestRatedPeriod + 1);

    int worstPerformingEmployee = findWorstPerformingEmployee(employees, numEmployees, numPeriods);
    printf("\nWorst Performing Employee: Employee %d\n", worstPerformingEmployee + 1);

    for (int i = 0; i < numEmployees; i++) {
        free(employees[i].ratings);
    }

    free(employees);

    return 0;
}
