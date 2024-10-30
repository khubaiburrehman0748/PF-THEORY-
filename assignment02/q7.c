#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char letters[6][5];
    int id;
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            letters[i][j] = 'A' + rand() % 26;
        }
    }
    printf("Enter your ID: ");
    scanf("%d", &id);
    letters[5][0] = '0' + (id / 1000) % 10;
    letters[5][1] = '0' + (id / 100) % 10;
    letters[5][2] = '0' + (id / 10) % 10;
    letters[5][3] = '0' + id % 10;
    letters[5][4] = 'Q';
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c\t", letters[i][j]);
        }
        printf("\n");
    }
    int score=0;
    char search[99]="";
    while(1){
        printf("search =");
        scanf("%s", search);
        int total=strlen(search),flag=0,match1=0,match2=0;
        if (strcmp(search, "END") == 0) {
            break; 
        }
        //row wise search
        for(int i=0;i<6;i++){
            for(int j=0;j<5;j++){
                if(letters[i][j]==search[0]){
                    int m=j;
                    for(int k=0;k<total;k++){
                        if(search[k]==letters[i][m]){
                            m++;
                            if(m==5){
                                break;
                            }
                            flag=1;
                        }
                        else{
                            flag=0;
                            break;
                        }
                        
                    }if(flag==1){
                        match1=1;
                        score++;
                        printf("%s is present Score=%d\n",search,score);
                    }
                    flag=0;
                }
            }
        }
        if(match1!=1){
         //column wise search
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                if(letters[j][i]==search[0]){
                    int m=j;
                    for(int k=0;k<total;k++){
                        if(search[k]==letters[m][i]){
                            m++;
                            if(m==5){
                                break;
                            }
                            flag=1;
                        }
                        else{
                            flag=0;
                            break;
                        }
                        
                    }if(flag==1){
                        score++;
                        printf("%s is present Score=%d\n",search,score);
                        match2=1;
                    }
                    flag=0;
                }
            }
        }
        }
    if(match1==0 && match2==0){
        score--;
        printf("%s is not present Score=%d\n",search,score);
    }
    }
    return 0;
}
