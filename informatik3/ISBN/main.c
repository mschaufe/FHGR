/*****************************
 * Marc Schaufelberger *
 * FHGR*
 * 20. SEP 2019 *
 * Check ISBN
******************************/
#include <stdio.h>
#include <ctype.h>

int lengthIsOkay = 1;
int thereAreCharacters = 0;

void returnMessageToUser(int checksum){
    if (checksum == 1 && lengthIsOkay == 1 && thereAreCharacters == 0){
        printf("valid");
        exit(1);
    } else{
        printf("invalid");
        if (checksum ==1){
            printf(", checksum ok");
        }else{
            printf(", checksum not ok");
        }
        if (lengthIsOkay >1){
            printf(", too long");
        } else if (lengthIsOkay <1){
            printf(", too short");
        }
        if (thereAreCharacters !=0){
            printf(", characters included");
        }
        exit(1);
    }
}

/*Do a modulo 10 division on the result from step 2. (Don't know what a modulo 10 division is? It's easy.
 * It's just the remainder from a whole number division by 10. I bet you learned to do that in junior school,
 * before you even learned about decimal fractions.)*/
void checkDigit(int *ISBN,int result){
    int remainder = result % 10;
    if (remainder == 0 && ISBN[12] == 0){
        returnMessageToUser(1);
    }else if (10-remainder == ISBN[12] ){
        returnMessageToUser(1);
    }
    returnMessageToUser(0);
}


/* Multiply each number in turn, from left to right by a number.
 * The first digit is multiplied by 1, the second by 3, the third by 1 gain,
 * the fourth by 3 again, and so on to the eleventh which is multiplied by 1 and the twelfth by 3. */
void MultiplyAndAddResults(int *ISBN){
    int result = 0;
    /* Multiply by 1 */
    for (int i=0; i<=11; i=i+2){
        result = result+ ISBN[i];
    }
    /* Multiply by 3 */
    for (int i=1; i<=11; i=i+2){
        result = result+ (ISBN[i]*3);
    }
    checkDigit(ISBN,result);
}


void checkISBN(int *ISBN){
    /* 1. MultiplyAndAddResults and 2.checkDigit */
    MultiplyAndAddResults(ISBN);
}

void cleanUpISBN (char *input,int inputLength){
    int cleanedISBN[14];
    int counterForClenedISBN = 0;
    for (int i=0;i<inputLength; i++){
        if( (input[i]>='0' && input[i]<='9') || (input[i]<='-')) {
            if(input[i]>='0' && input[i]<='9'){
            cleanedISBN[counterForClenedISBN] = input[i]-48;
            counterForClenedISBN ++;
            }
        }
        else {

            thereAreCharacters = 1;
        }
    }
    if (counterForClenedISBN > 13){
        lengthIsOkay = 2;
    }else if(counterForClenedISBN < 13){
        lengthIsOkay = 0;
    }
    checkISBN(&cleanedISBN);
}

int measurelength(char *input){
    int charcount = 0;
    for(int m=0; input[m]; m++) {
        if(input[m] != ' ') {
            charcount ++;
        }
    }
    return charcount;
}

void checkInput(char *input){
    int inputLength = measurelength(input);
    cleanUpISBN(input,inputLength);
}


void getISBN(){
    char input[20];
    printf("Enter your ISBN-13 code: ");
    scanf("%20s", &input[0]);
    printf("\"%s\", ", input);
    checkInput(&input);
}

int main(){
    getISBN();
    return 0;
}