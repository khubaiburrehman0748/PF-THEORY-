#include <stdio.h>
#include <string.h>

#define MAX_WORDS 99
#define MAX_LENGTH 99
void sortString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    int wordCount;
    char transactions[MAX_WORDS][MAX_LENGTH];
    char sortedTransactions[MAX_WORDS][MAX_LENGTH];
    int grouped[MAX_WORDS] = {0}; 
    printf("Enter the number of transactions: ");
    scanf("%d", &wordCount);

    for (int i = 0; i < wordCount; i++) {
        printf("Transaction %d: ", i + 1);
        scanf("%s", transactions[i]);

        strcpy(sortedTransactions[i], transactions[i]);
        sortString(sortedTransactions[i]);
    }

    for (int i = 0; i < wordCount; i++) {
        if (grouped[i]) continue; 

        printf("[");
        printf("%s", transactions[i]);
        grouped[i] = 1;

        for (int j = i + 1; j < wordCount; j++) {
            if (strcmp(sortedTransactions[i], sortedTransactions[j]) == 0) {
                printf(", %s", transactions[j]);
                grouped[j] = 1;
            }
        }
        printf("]\n");
    }

    return 0;
}
