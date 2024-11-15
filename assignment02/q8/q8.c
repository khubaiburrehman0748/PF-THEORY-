#include <stdio.h>
#include <math.h>
#include <string.h> 
long convertBinaryToDecimal(long bin){
    long newbin=0,dec=0,powtwo=1,i=1;
    for(bin;bin!=0;bin=bin/10){
        newbin=bin%10;
        dec=dec+newbin*(powtwo);
        powtwo=pow(2,i);
        i++;
    }
    return dec;
}
long convertDecimalToBinary(long dec){
    long i=1,bin=0,newdec=0;
    for(dec;(dec!=0);dec=dec/2){
        newdec=dec%2;
        bin=bin+(newdec*i);
        i*=10;
    }
    return bin;
}
long convertBinaryToHexadecimal(long bin){
    long dec=convertBinaryToDecimal(bin),i=0,newdec=0;
    char save[99];
    for(dec;dec!=0;dec=dec/16){
        newdec=dec%16;
        if(newdec<10){
            save[i]=newdec+'0';
        }
        else{
            save[i]=(char)(newdec+55);
        }
        i++;
    }
    for(i--;i>=0;i--){
        printf("%c",save[i]);
    }
    char* x=save;
    return *x;
}
long convertHexadecimalToDecimal(char hex[]){
    long limit = strlen(hex),sixteenpow=1,k=1,sum=0;
    for(int i=limit-1;i>=0;i--){
        if(hex[i]>=49 && hex[i]<=57){
            sum+=((hex[i]-48)*sixteenpow);
        }
        else if(hex[i]>=65 && hex[i]<=70){
            sum+=((hex[i]-55)*sixteenpow);
        }
        else if(hex[i]>=97 && hex[i]<=102){
            sum+=((hex[i]-87)*sixteenpow);
        }
        else {
            sum=0;
            break;
        }
        sixteenpow*=16;
    }
    return sum;
}
long convertDecimalToHexadecimal(long dec){
    long bin=convertDecimalToBinary(dec);
    char hex=convertBinaryToHexadecimal(bin);
    return hex;
}
long convertHexadecimalToBinary(char hex[]){
    long decimal=convertHexadecimalToDecimal(hex);
    long bin=convertDecimalToBinary(decimal);
    return bin;
}
int binvalid(int bin){
    int temp=0;
    for(bin;bin!=0;bin=bin/10){
            int newbin=bin%10;
            if(newbin!=0 && newbin!=1){
                 temp=1;
                 break;
            }
        }
    return temp;    
}
int decvalid(int dec){
    int temp=0;
    for(dec;dec!=0;dec=dec/10){
        int newdec=dec%10;
        if(newdec<0 && newdec>9){
            temp=1;
            break;
        }
    }
    return temp;
}
int main() {
    long conversionChoice;  
    printf("\tChoose the Conversion You Want to Perform\n");
    printf("1) Binary to Decimal\n");
    printf("2) Decimal to Binary\n");
    printf("3) Binary to Hexadecimal\n");
    printf("4) Decimal to Hexadecimal\n");
    printf("5) Hexadecimal to Binary\n");
    printf("6) Hexadecimal to Decimal\n");
    printf("Enter your choice: ");
    scanf("%ld", &conversionChoice);

    if (conversionChoice == 1) {
        long binaryInputValue,temp=0; 
        printf("Enter the Binary value: ");
        scanf("%ld", &binaryInputValue);
        temp=binvalid(binaryInputValue);
        if(temp==0){
        printf("The Decimal equivalent of %ld is: %ld\n", binaryInputValue, convertBinaryToDecimal(binaryInputValue));
        }
        else{ printf("not a binary number");}
        
    } else if (conversionChoice == 2) {
        long decimalInputValue; 
        printf("Enter the Decimal value: ");
        scanf("%ld", &decimalInputValue);
        int temp=decvalid(decimalInputValue);
        if(temp==0){
        printf("The Binary equivalent of %ld is: %ld\n", decimalInputValue, convertDecimalToBinary(decimalInputValue));
        }
        else{ printf("not a decimal number");}
        
    } else if (conversionChoice == 3) {
        long binaryInputValue; 
        printf("Enter the Binary value: ");
        scanf("%ld", &binaryInputValue);
        int temp=binvalid(binaryInputValue);
        if(temp==0){
        printf("The Hexadecimal equivalent of %ld is: ", binaryInputValue);
        convertBinaryToHexadecimal(binaryInputValue);
        printf("\n");
        }
        else { printf("not a binary number");}
        
    } else if (conversionChoice == 4) {
        long decimalInputValue;
        printf("Enter the Decimal value: ");
        scanf("%ld", &decimalInputValue);
        int temp=decvalid(decimalInputValue);
        if(temp==0){
        printf("The Hexadecimal equivalent of %ld is: ", decimalInputValue);
        convertDecimalToHexadecimal(decimalInputValue);
        printf("\n");
        }
        else {printf("not a decimal number");}
    } else if (conversionChoice == 5) {
        char hexadecimalInputValue[100];
        printf("Enter the Hexadecimal value: ");
        scanf("%s", hexadecimalInputValue);
        int temp=convertHexadecimalToBinary(hexadecimalInputValue);
        if(temp!=0){
        printf("The Binary equivalent of %s is: %ld\n", hexadecimalInputValue, convertHexadecimalToBinary(hexadecimalInputValue));
        }
        else {printf("not a hexadecimal number ");}
    } else if (conversionChoice == 6) {
        char hexadecimalInputValue[100];
        printf("Enter the Hexadecimal value: ");
        scanf("%s", hexadecimalInputValue);
        int temp= convertHexadecimalToDecimal(hexadecimalInputValue);
        if(temp!=0){
        printf("The Decimal equivalent of %s is: %ld\n", hexadecimalInputValue, convertHexadecimalToDecimal(hexadecimalInputValue));
        }
        else {printf("not a hexadecimal number ");}
    } else {
        printf("Invalid choice! Please enter a number between 1 and 6.\n");
    }

    return 0;
}
