/*****************************
 * Marc Schaufelberger *
 * FHGR *
 * 22. SEP 2019 *
 * Ceasar chiffre *
******************************/

#include <stdio.h>

// given code block
// take every small letter and count in the ascii table plus your shift
void ceasarChiffreEncypt(const char * input, char * output, int shift){
    for (int i=0; i<30; i++){
        if(input[i]>='a' && input[i]<='z') {
            int tempAsciiCode = input[i];
            // in case we would count over z, we start by a again.
            output[i] = ((tempAsciiCode + shift - 97) % 26) + 97;

        // we ignore spaces
        }else if(input[i]>=' ') {
            output[i] = input[i];
        }
    }
}

int main() {
    const char input[30] = "hello world";
    char output[30];
    int shift = 13;

    ceasarChiffreEncypt(&input, &output, shift);

    printf("Clear text: \"%s\"\n", input);
    printf("Message:  \"%s\" ",output);
    return 0;
}