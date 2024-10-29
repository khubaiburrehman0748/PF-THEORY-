#include<stdio.h>

void correct(char arr[],int count){
    int i;
    for(i=0;i<count;i++){
        if(arr[i]!=arr[i+1]){
            printf("%c",arr[i]);
        }
    }
}
int main(){
    char word[99];
    printf("input  word:");
    fgets(word,99,stdin);
    int count=0;
    while(word[count]!='\0'){
        count++;
    }
    count=count-1;
    correct(word,count);
    return 0;
}
