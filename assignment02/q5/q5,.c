#include <stdio.h>

#include <stdio.h>
void histogram(int arr[],int count){
    printf("HORIZONTAL HISTOGRAM");
    printf("\n");
    printf("\n");
    int i,line;
    for(i=0;i<count;i++){
        printf("value %d:  ",arr[i]);
        for(line=arr[i];line!=0;line--){
            printf("*  ");
        }
        printf("\n");
    }
    printf("\n");
    printf("VERTICAL HISTOGRAM");
    printf("\n");
    int max=-1,j,n,horz,vert;
    int newarr[99];
        for(i=0;i<count;i++){
            newarr[i]=arr[i];
        }
        for(j=0;j<count-1;j++){
            for(n=0;n<count-1;n++){
                if(arr[n+1]>arr[n]){
                    int temp=arr[n+1];
                    arr[n+1]=arr[n];
                    arr[n]=temp;
                }
            }
        }
    n=0;
    i=1;
    printf("\n");
    for(horz=0;horz<arr[0];horz++){
        for(vert=0;vert<count;vert++){
            if(newarr[vert]>=arr[n]){
                printf("*");
                printf("\t");
            }
            else{
                printf("\t");
            }
        }
        printf("\n");
        if(arr[n+1]==(arr[n]-i)){
            n++;
            i=0;
        }
            i++;
    }
    for(i=0;i<count;i++){
        printf("%d",newarr[i]);
        printf("\t");
    }
}

int main() {
    int arr[] = {3,5,1,4};
    int count = sizeof(arr[0]);
    histogram(arr,count);
  return 0;
}
