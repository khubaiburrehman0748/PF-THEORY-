#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email) {
    int atCount = 0, dotCount = 0;
    int i = 0;

    if (email[0] == '\0') {
        return 0;
    }

    while (email[i] != '\0') {
        if (email[i] == '@') {
            atCount++;
        }
        if (email[i] == '.' && atCount == 1) {
            dotCount++;
        }
        i++;
    }

    if (atCount == 1 && dotCount >= 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char *emailInput;
    char temp[100];

    printf("Enter email address: ");
    scanf("%s", temp);

    int length = strlen(temp) + 1;
    emailInput = (char*)malloc(length * sizeof(char));
    
    if (emailInput == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    strcpy(emailInput, temp);

    if (validateEmail(emailInput)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }

    free(emailInput);
    
    return 0;
}
