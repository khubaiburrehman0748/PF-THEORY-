#include <stdio.h>

int main() {
    int n;
    printf("numbers of star in odd=");
    scanf("%d",&n);
    if(n%2!=0){
    int l=1,m=(n+(n-2));
    for(int k=0;k<n-1;k++){
        for(int i=1;i<=m-k;i++){
         printf(" ");
        }
        printf("*");
        if(k!=0){
        for(int j=0;j<l;j++){
         printf(" ");
        }
        l=l+2;
        printf("*");
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        if(i!=n-1){
        printf("*");
        }
        else{
            printf("*");
        }
    }
    for(int i=0;i<l;i++){
     printf(" ");
    }
    for(int i=0;i<n;i++){
        printf("*");
    }
    printf("\n");
    l=l+2*(n-2);
    for(int k=1;k<n;k++){
        for(int m=0;m!=k;m++){
         printf(" ");
        }
        printf("*");
        for(int p=0;p<l;p++){
         printf(" ");
        }
        l=l-2;
        printf("*\n");
    }
    m=1;
    for(int k=0;k<n-1;k++){
        for(int p=0;p<(n-2)-k;p++){
             printf(" ");
        }
        printf("*");
        for(int p=0;p<(n-2)-k;p++){
             printf(" ");
        }
        if(k!=n-2){
        printf("*");
        }
        else{
            printf(" ");
        }
        for(int g=1;g<=m;g++){
            printf(" ");
        }
        if(k!=n-2){
        printf("*");
        }
        else{
            printf(" ");
        }
        if(k!=n-1){
            m=m+4;
        }
        else{
            m=m+6;
        }
        for(int p=0;p<(n-2)-k;p++){
             printf(" ");
        }
        printf("*\n");
    }
    }
    else 
    printf("not an odd number !");
    return 0;
}
