#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int mlength;
int hamparity;
int tempBit;
int num_Parity;
char *hamming_string = NULL;

void setup() {

        //Taking in inputs for length and parity
    scanf("%d", &mlength);
    printf("Enter Maximum Length: %d\n", mlength);


    scanf("%d", &hamparity);
    printf("Enter Parity (0 = even, 1 = odd): %d\n", hamparity);

    hamming_string = (char *) malloc(mlength * sizeof(char));

}

void check(){

//check to see if the code has parity
    int alength;
    int pcheck;
    int i;
    int j;
    int k;
    int errorbit = 0;

    scanf("%s", hamming_string);
    printf("Enter the Hamming Code: %s\n", hamming_string);


    alength = strlen(hamming_string);
    num_Parity = ceil (log(alength) / log(2));

    if(alength > mlength) {
        printf("\n***Invalid Entry - Exceeds Maximum Code Length of: %d\n", mlength);
    }
    else {
        for (i = 1; i < alength; i *= 2) {
            tempBit = i;
            pcheck = hamparity;
            for (j = i; j < alength; j += (i * 2)) {
                for (k = j; (k < j + i + 1) && (k <= alength); k++) {
                    pcheck ^= (hamming_string[alength - k] - '0');
                }
            }
            if (pcheck == 1)
                errorbit += tempBit;
        }
        if (errorbit == 0) {
            printf("\n\n***Hamming Code Correct\n");
            printf("***Correct Hamming Code: %s\n", hamming_string);

        } else {
            //error messages nested in
            printf("\n\n***Error in bit: %d\n", errorbit);
            if (hamming_string[alength - errorbit] == '0') {

                hamming_string[alength - errorbit] = '1';
            } else {
                hamming_string[alength - errorbit] = '0';

            }
            printf("***Correct Hamming Code: %s\n", hamming_string);

        }
    }
}

//startup display
void display() {
    printf("\Enter your selection\n"
           "--------------------------------\n"
           "1. Enter Parameters\n"
           "2. Enter Hamming Code\n"
           "3. Quit\n");
}


//printout that follows
int main(){
    int input;


//selection menu inputs
    while (1) {
        display();
        scanf("%d", &input);
        printf("\nEnter Selection: %d\n\n", input);
        if (input == 1) { //setup
            setup();
        }
        if (input == 2) { //read
            check();
        }
        if (input == 3) {//write
            if (hamming_string != NULL) {
                free(hamming_string);
            }
            printf("\n***Program Terminated Normally\n");
            return 0;
        }
    }
}
