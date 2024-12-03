#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Species {
    char **supplies;
    int supplyCount;
};

void initializeInventory(struct Species **inventory, int *speciesCount) {
    printf("Enter number of species: ");
    scanf("%d", speciesCount);
    getchar();

    *inventory = (struct Species*)malloc(*speciesCount * sizeof(struct Species));

    for (int i = 0; i < *speciesCount; i++) {
        printf("\nEnter name of species %d: ", i + 1);
        char speciesName[50];
        fgets(speciesName, sizeof(speciesName), stdin);
        speciesName[strcspn(speciesName, "\n")] = '\0';

        printf("Enter number of supplies for %s: ", speciesName);
        scanf("%d", &(*inventory)[i].supplyCount);
        getchar();

        (*inventory)[i].supplies = (char**)malloc((*inventory)[i].supplyCount * sizeof(char*));

        for (int j = 0; j < (*inventory)[i].supplyCount; j++) {
            printf("Enter supply %d for %s: ", j + 1, speciesName);
            char supply[50];
            fgets(supply, sizeof(supply), stdin);
            supply[strcspn(supply, "\n")] = '\0';

            (*inventory)[i].supplies[j] = (char*)malloc((strlen(supply) + 1) * sizeof(char));
            strcpy((*inventory)[i].supplies[j], supply);
        }
    }
}

void addSupplies(struct Species *species) {
    printf("Enter number of new supplies: ");
    int newSuppliesCount;
    scanf("%d", &newSuppliesCount);
    getchar();

    species->supplies = (char**)realloc(species->supplies, (species->supplyCount + newSuppliesCount) * sizeof(char*));

    for (int i = species->supplyCount; i < species->supplyCount + newSuppliesCount; i++) {
        printf("Enter new supply %d: ", i + 1);
        char supply[50];
        fgets(supply, sizeof(supply), stdin);
        supply[strcspn(supply, "\n")] = '\0';

        species->supplies[i] = (char*)malloc((strlen(supply) + 1) * sizeof(char));
        strcpy(species->supplies[i], supply);
    }

    species->supplyCount += newSuppliesCount;
}

void updateSupplies(struct Species *species) {
    printf("Enter supply number to update (1-%d): ", species->supplyCount);
    int supplyNumber;
    scanf("%d", &supplyNumber);
    getchar();

    if (supplyNumber < 1 || supplyNumber > species->supplyCount) {
        printf("Invalid supply number.\n");
        return;
    }

    printf("Enter new name for supply %d: ", supplyNumber);
    char newSupply[50];
    fgets(newSupply, sizeof(newSupply), stdin);
    newSupply[strcspn(newSupply, "\n")] = '\0';

    free(species->supplies[supplyNumber - 1]);
    species->supplies[supplyNumber - 1] = (char*)malloc((strlen(newSupply) + 1) * sizeof(char));
    strcpy(species->supplies[supplyNumber - 1], newSupply);
}

void removeSpecies(struct Species *inventory, int *speciesCount, int speciesIndex) {
    for (int i = 0; i < inventory[speciesIndex].supplyCount; i++) {
        free(inventory[speciesIndex].supplies[i]);
    }

    free(inventory[speciesIndex].supplies);

    for (int i = speciesIndex; i < *speciesCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    (*speciesCount)--;
    inventory = (struct Species*)realloc(inventory, (*speciesCount) * sizeof(struct Species));
}

void displayInventory(struct Species *inventory, int speciesCount) {
    for (int i = 0; i < speciesCount; i++) {
        printf("\nSpecies %d:\n", i + 1);
        printf("Supplies: \n");
        for (int j = 0; j < inventory[i].supplyCount; j++) {
            printf("%d. %s\n", j + 1, inventory[i].supplies[j]);
        }
    }
}

int main() {
    struct Species *inventory = NULL;
    int speciesCount = 0;

    initializeInventory(&inventory, &speciesCount);
    displayInventory(inventory, speciesCount);

    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Supplies\n");
        printf("2. Update Supplies\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                int speciesIndex;
                printf("Enter species number to add supplies: ");
                scanf("%d", &speciesIndex);
                getchar();
                if (speciesIndex < 1 || speciesIndex > speciesCount) {
                    printf("Invalid species number.\n");
                } else {
                    addSupplies(&inventory[speciesIndex - 1]);
                }
                break;
            }
            case 2: {
                int speciesIndex;
                printf("Enter species number to update supplies: ");
                scanf("%d", &speciesIndex);
                getchar();
                if (speciesIndex < 1 || speciesIndex > speciesCount) {
                    printf("Invalid species number.\n");
                } else {
                    updateSupplies(&inventory[speciesIndex - 1]);
                }
                break;
            }
            case 3: {
                int speciesIndex;
                printf("Enter species number to remove: ");
                scanf("%d", &speciesIndex);
                getchar();
                if (speciesIndex < 1 || speciesIndex > speciesCount) {
                    printf("Invalid species number.\n");
                } else {
                    removeSpecies(inventory, &speciesCount, speciesIndex - 1);
                }
                break;
            }
            case 4:
                displayInventory(inventory, speciesCount);
                break;
            case 5:
                for (int i = 0; i < speciesCount; i++) {
                    for (int j = 0; j < inventory[i].supplyCount; j++) {
                        free(inventory[i].supplies[j]);
                    }
                    free(inventory[i].supplies);
                }
                free(inventory);
                return 0;
        }
    }
}
