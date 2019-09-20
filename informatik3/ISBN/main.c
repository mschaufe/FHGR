/*****************************
 * Marc Schaufelberger *
 * FHGR*
 * 20. SEP 2019 *
 * Check ISBN
******************************/
#include <stdio.h>

// ISPN Nummer
int ISBN[]= {9,7,8,1,8,6,1,9,7,2,7,1,2};

/* Multiply each number in turn, from left to right by a number.
 * The first digit is multiplied by 1, the second by 3, the third by 1 gain,
 * the fourth by 3 again, and so on to the eleventh which is multiplied by 1 and the twelfth by 3. */
int MultiplyAndAddResults(int ISBN[]){
    int result = 0;
    /* Multiply by 1 */
    for (int i=0; i<=11; i=i+2){
        result = result+ ISBN[i];
    }
    /* Multiply by 3 */
    for (int i=1; i<=11; i=i+2){
        result = result+ (ISBN[i]*3);
    }
    return result;
}

/*Do a modulo 10 division on the result from step 2. (Don't know what a modulo 10 division is? It's easy.
 * It's just the remainder from a whole number division by 10. I bet you learned to do that in junior school,
 * before you even learned about decimal fractions.)*/
int checkDigit(int result){
    int remainder = result % 10;
    if (remainder == 0 && ISBN[12] == 0){
        return 1;
    }else if (10-remainder == ISBN[12] ){
        return 1;
    }
    return 0;
}
int checkISBN(int ISBN[]){
    /* 1. MultiplyAndAddResults and 2.checkDigit */
    int valid = checkDigit(MultiplyAndAddResults(ISBN));
    return valid;
}

int main(){

    if (checkISBN(ISBN) == 1){
        printf("This is a valid ISPN number!");
    } else{
        printf("Try again!");
    }

    return 0;
}