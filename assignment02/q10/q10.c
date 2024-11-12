#include <stdio.h>

int main() {
    int n;
    // Prompting the user to enter an odd number of stars
    printf("numbers of star in odd=");
    scanf("%d", &n);
    
    // Check if the input number is odd
    if(n % 2 != 0){
        int l = 1;             // Initial space between stars in upper part
        int m = (n + (n - 2)); // Used for initial spacing on the left side in the upper triangle part
        
        // Loop for upper triangle part
        for(int k = 0; k < n - 1; k++){
            // Left spacing for triangle shape
            for(int i = 1; i <= m - k; i++){
                printf(" ");
            }
            printf("*");
            
            // Space between stars if it's not the first row
            if(k != 0){
                for(int j = 0; j < l; j++){
                    printf(" ");
                }
                l = l + 2;    // Increase space between stars for next row
                printf("*");
            }
            printf("\n");
        }
        
        // Print middle row of stars
        for(int i = 0; i < n; i++){
            printf("*");
        }
        
        // Print spaces between two parts of middle row
        for(int i = 0; i < l; i++){
            printf(" ");
        }
        
        // Print stars on the right side of middle row
        for(int i = 0; i < n; i++){
            printf("*");
        }
        printf("\n");
        
        // Adjust space for lower triangle part
        l = l + 2 * (n - 2);
        
        // Loop for lower triangle part
        for(int k = 1; k < n; k++){
            // Left spacing for inverted triangle shape
            for(int m = 0; m != k; m++){
                printf(" ");
            }
            printf("*");
            
            // Space between stars in each row of inverted triangle
            for(int p = 0; p < l; p++){
                printf(" ");
            }
            l = l - 2;       // Decrease space for next row
            printf("*\n");
        }
        
        m = 1; // Reset `m` for diamond pattern

        // Loop for creating diamond pattern at the bottom
        for(int k = 0; k < n - 1; k++){
            // Left spacing for diamond pattern
            for(int p = 0; p < (n - 2) - k; p++){
                printf(" ");
            }
            printf("*");
            
            // Additional spacing to shape the diamond pattern
            for(int p = 0; p < (n - 2) - k; p++){
                printf(" ");
            }
            if(k != n - 2){
                printf("*");
            } else {
                printf(" ");
            }
            
            // Middle spaces of the diamond pattern
            for(int g = 1; g <= m; g++){
                printf(" ");
            }
            if(k != n - 2){
                printf("*");
            } else {
                printf(" ");
            }
            
            // Increase middle space for the next row
            if(k != n - 1){
                m = m + 4;
            } else {
                m = m + 6;
            }
            
            // Right spacing for diamond pattern
            for(int p = 0; p < (n - 2) - k; p++){
                printf(" ");
            }
            printf("*\n");
        }
    } else {
        // Message if the input is not an odd number
        printf("not an odd number !");
    }
    return 0;
}
