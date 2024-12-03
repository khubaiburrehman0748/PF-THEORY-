#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Cricketer {
    char name[100];
    int ballRuns[12];
    int totalRuns;
};

bool isValidRun(int run) {
    return run >= 0 && run <= 6;
}

void inputRuns(struct Cricketer *player) {
    int score;
    player->totalRuns = 0;

    for (int i = 0; i < 12; i++) {
        printf("Enter runs for delivery %d: ", i + 1);
        scanf("%d", &score);
        if (isValidRun(score)) {
            player->ballRuns[i] = score;
            player->totalRuns += score;
        } else {
            player->ballRuns[i] = 0;
        }
    }
}

struct Cricketer findMatchWinner(struct Cricketer playerA, struct Cricketer playerB) {
    return (playerA.totalRuns > playerB.totalRuns) ? playerA : playerB;
}

void showMatchDetails(struct Cricketer playerA, struct Cricketer playerB) {
    printf("\n--- Cricket Match Details ---\n");

    printf("\nPlayer: %s\n", playerA.name);
    printf("Runs per ball: ");
    for (int i = 0; i < 12; i++) {
        printf("%d ", playerA.ballRuns[i]);
    }
    printf("\nTotal Runs: %d", playerA.totalRuns);
    printf("\nAverage Runs: %.2f\n", playerA.totalRuns / 12.0);

    printf("\nPlayer: %s\n", playerB.name);
    printf("Runs per ball: ");
    for (int i = 0; i < 12; i++) {
        printf("%d ", playerB.ballRuns[i]);
    }
    printf("\nTotal Runs: %d", playerB.totalRuns);
    printf("\nAverage Runs: %.2f\n", playerB.totalRuns / 12.0);
}

int main() {
    struct Cricketer playerX, playerY;

    printf("Enter the name of Player X: ");
    fgets(playerX.name, sizeof(playerX.name), stdin);
    playerX.name[strcspn(playerX.name, "\n")] = '\0';
    inputRuns(&playerX);

    getchar();

    printf("Enter the name of Player Y: ");
    fgets(playerY.name, sizeof(playerY.name), stdin);
    playerY.name[strcspn(playerY.name, "\n")] = '\0';
    inputRuns(&playerY);

    showMatchDetails(playerX, playerY);

    struct Cricketer winner = findMatchWinner(playerX, playerY);
    printf("\nTHE WINNER IS: %s\n", winner.name);

    return 0;
}
