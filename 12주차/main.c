#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int parseInt(char* c) {
    int decimal = 0, pos = 0;
    for (int i = strlen(c) - 1; i>=0 ; i--) {
        char ch = c[i];
        if (ch >= 48 && ch <= 57) {
            decimal += (ch-48) * pow(16, pos);
        } else if (ch >= 65 && ch <= 70) {
            decimal += (ch - 55) * pow(16, pos);
        }
        pos++;
    }
    return decimal;
}

int main(int argc, char* argv[]) {
    char CODES[60];
    char *c;
    int startADR, len;
    srand((unsigned int)time(NULL));
    if (argv[1] == NULL) {
        printf("error: Command line argument is not entered.\n");
        return 0;
    }

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("error: Unvalid file path\n");
        return 0;
    }
    c = fgets(CODES, 16, fp);
    c = fgets(CODES, 5, fp);
    len = parseInt(c);

    do {
        startADR = rand() % 32759;
    } while (startADR + len > 32758);

    printf("start address: %d\n", startADR);
}