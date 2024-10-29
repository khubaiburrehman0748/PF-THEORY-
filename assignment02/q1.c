#include <stdio.h>
int main(){
    int num[99];
    int i,n;
    printf("input size =");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    printf("number %d =",i+1);
    scanf("%d",&num[i]);
    }
    int max=-1,max2=-1,min=1000,min2=1000;
    for(i=0;i<n;i++){
        if(num[i]>max){
            max2=max;
            max=num[i];
        }else if(max>num[i] && num[i]>max2){
            max2=num[i];
        }
        if(num[i]<min){
            min2=min;
            min=num[i];
        }else if(min<num[i] && num[i]<min2){
            min2=num[i];
    }
    }
    printf("Minimum Number = %d \n",min);
    printf("Maxmimum Number = %d \n",max);
    printf("second Minimum Number = %d \n",min2);
    printf("second Maxmimum Number = %d",max2);
    
  return 0;
}
