#include <stdio.h>

int matchsticks_game(int n) {
    
    if (n % 5 == 0) {
        return -1; 
    } else {
        return n % 5; 
    }
}

int main() {
    int n;
    printf("Enter the number of matchsticks: ");
    scanf("%d", &n);

    int result = matchsticks_game(n);
    if (result == -1) {
        printf("A cannot guarantee a win.\n");
    } else {
        printf("A should pick %d matchstick(s) to guarantee a win.\n", result);
    }

    return 0;
}
