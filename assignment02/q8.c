#include <stdio.h>
#include <math.h>
#include <string.h>

long convertBinaryToDecimal(long binaryNumber) {
    long decimalNumber = 0;
    long bitPosition = 0;
    long currentBit;

    while (binaryNumber > 0) {
        currentBit = binaryNumber % 10;
        binaryNumber /= 10;
        if (currentBit == 1) {
            decimalNumber += pow(2, bitPosition);
        }
        bitPosition++;
    }

    return decimalNumber;
}

long convertDecimalToBinary(long decimalNumber) {
    char binaryString[1000000] = {'\0'};
    long power = decimalNumber;
    long index = 0;
    long significantBits = 0;

    while (power >= 0) {
        if (pow(2, power) <= decimalNumber) {
            decimalNumber -= pow(2, power);
            binaryString[index++] = '1';
            significantBits++;
        } else {
            binaryString[index++] = '0';
            if (significantBits != 0) {
                significantBits++;
            }
        }
        power--;
    }

    long binaryResult = 0;
    long multiplier = 1;
    for (long i = index - 1; i >= index - significantBits; i--) {
        if (binaryString[i] == '1') {
            binaryResult += 1 * multiplier;
        }
        multiplier *= 10;
    }
    return binaryResult;
}

long convertHexadecimalToBinary(char hexString[]) {
    long hexLength = strlen(hexString);
    char binaryString[1000000] = {'\0'};
    long decimalValue, i;
    char tempBinary[5];

    for (i = 0; i < hexLength; i++) {
        if (hexString[i] == 'A' || hexString[i] == 'a') {
            decimalValue = 10;
        } else if (hexString[i] == 'B' || hexString[i] == 'b') {
            decimalValue = 11;
        } else if (hexString[i] == 'C' || hexString[i] == 'c') {
            decimalValue = 12;
        } else if (hexString[i] == 'D' || hexString[i] == 'd') {
            decimalValue = 13;
        } else if (hexString[i] == 'E' || hexString[i] == 'e') {
            decimalValue = 14;
        } else if (hexString[i] == 'F' || hexString[i] == 'f') {
            decimalValue = 15;
        } else {
            decimalValue = hexString[i] - '0';
        }
        sprintf(tempBinary, "%04ld", convertDecimalToBinary(decimalValue));
        strcat(binaryString, tempBinary);
    }

    long binaryResult = 0;
    for (i = 0; i < strlen(binaryString); i++) {
        binaryResult = binaryResult * 10 + (binaryString[i] - '0');
    }

    return binaryResult;
}

long convertHexadecimalToDecimal(char hexString[]) {
    long binaryValue = convertHexadecimalToBinary(hexString);
    long decimalValue = convertBinaryToDecimal(binaryValue);
    return decimalValue;
}

void convertBinaryToHexadecimal(long binaryNumber) {
    long bitGroup;
    long binaryCopy = binaryNumber;
    char hexResult[1000000] = {'\0'};
    int index = 1000000 - 2;
    int hexDigit;

    while (binaryCopy > 0) {
        bitGroup = binaryCopy % 10000;
        binaryCopy /= 10000;
        hexDigit = 0;

        for (int i = 0; i < 4; i++) {
            if (bitGroup % 10 == 1) {
                hexDigit += pow(2, i);
            }
            bitGroup /= 10;
        }

        if (hexDigit < 10) {
            hexResult[index] = hexDigit + '0';
        } else {
            hexResult[index] = hexDigit - 10 + 'A';
        }
        index--;
    }

    for (int i = index + 1; i < 1000000 - 1; i++) {
        if (hexResult[i] != '\0') {
            printf("%c", hexResult[i]);
        }
    }
}

void convertDecimalToHexadecimal(long decimalNumber) {
    convertBinaryToHexadecimal(convertDecimalToBinary(decimalNumber));
}

int main() {
    long choice;
    printf("\tChoose the Conversion You Want to Perform\n");
    printf("1) Binary to Decimal\n");
    printf("2) Decimal to Binary\n");
    printf("3) Binary to Hexadecimal\n");
    printf("4) Decimal to Hexadecimal\n");
    printf("5) Hexadecimal to Binary\n");
    printf("6) Hexadecimal to Decimal\n");
    printf("Enter your choice: ");
    scanf("%ld", &choice);

    if (choice == 1) {
        long binaryInput;
        printf("Enter the Binary value: ");
        scanf("%ld", &binaryInput);
        printf("The Decimal equivalent of %ld is: %ld\n", binaryInput, convertBinaryToDecimal(binaryInput));
    } else if (choice == 2) {
        long decimalInput;
        printf("Enter the Decimal value: ");
        scanf("%ld", &decimalInput);
        printf("The Binary equivalent of %ld is: %ld\n", decimalInput, convertDecimalToBinary(decimalInput));
    } else if (choice == 3) {
        long binaryInput;
        printf("Enter the Binary value: ");
        scanf("%ld", &binaryInput);
        printf("The Hexadecimal equivalent of %ld is: ", binaryInput);
        convertBinaryToHexadecimal(binaryInput);
        printf("\n");
    } else if (choice == 4) {
        long decimalInput;
        printf("Enter the Decimal value: ");
        scanf("%ld", &decimalInput);
        printf("The Hexadecimal equivalent of %ld is: ", decimalInput);
        convertDecimalToHexadecimal(decimalInput);
        printf("\n");
    } else if (choice == 5) {
        char hexInput[100];
        printf("Enter the Hexadecimal value: ");
        scanf("%s", hexInput);
        printf("The Binary equivalent of %s is: %ld\n", hexInput, convertHexadecimalToBinary(hexInput));
    } else if (choice == 6) {
        char hexInput[100];
        printf("Enter the Hexadecimal value: ");
        scanf("%s", hexInput);
        printf("The Decimal equivalent of %s is: %ld\n", hexInput, convertHexadecimalToDecimal(hexInput));
    } else {
        printf("Invalid choice! Please enter a number between 1 and 6.\n");
    }

    return 0;
}