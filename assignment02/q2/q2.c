#include <stdio.h>
int main(){
    char slogan[99];
    printf("slogans =");
    fgets(slogan,99,stdin);
    int i=0,n,f=2,count=1;
    while(slogan[i]!='\0'){
    i++;
    }
    for(n=0;n<i-1;n++){
        for(f=n+1;f<i;f++){ 
            if(slogan[n]==slogan[f] && i!=f){
                count++;
                slogan[f]=' ';
            }
        }
        if(slogan[n]!=' '){
        printf("%c = %d,\t",slogan[n],count);
        }
        count=1;
    }
  return 0;
}
