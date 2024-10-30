#include <stdio.h>
#include <string.h>
int main() {
    char arr[99][99],newarr[99][99];
    int total; 
    printf("number of scrambled words? =");
    scanf("%d",&total);
    for(int i=0;i<total;i++){
        printf("word %d =",i+1);
        scanf("%s",&arr[i]);
    }
    for(int i=0;i<total;i++){
    strcpy( newarr[i], arr[i]);
    }
    int till=0,flag=0;
    printf("[");
    for(int i=0;i<total;i++){
    if(flag==0){
        till=strlen(arr[i]);
        if(arr[i][0]!='\0'){
        printf("[");
        printf("%s",arr[i]);
        }
        for(int l=0;l<till;l++){
            for(int j=0;j<till-1;j++){
                for(int k=j+1;k<till;k++){
                    char temp=newarr[i][j];
                    newarr[i][j]=newarr[i][k];
                    newarr[i][k]=temp;
                    for(int m=i+1;m<total;m++){
                        int check=strcmp(newarr[i],arr[m]);
                        if(check==0){
                            printf(", %s",newarr[m]);
                            arr[m][0]='\0';
                        }
                        else{
                            flag=0;
                        }
                        }
                    }
                }    
            }        
        }
        if(arr[i][0]!='\0'){
        printf("]");
        }
    }
    printf("]");

    return 0;
}
