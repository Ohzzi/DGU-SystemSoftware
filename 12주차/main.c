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
    char* memory[32759];
    char CODES[60];
    char *c;
    int startADR, size, len, location;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 32759; i++) {
        memory[i] = malloc(sizeof(char)*2);
        // memory[i] = "00";
    }
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
    size = parseInt(c);
    size = 160;

    /* do {
        startADR = rand() % 32759;
    } while (startADR + size > 32758); */
    startADR = 2260;
    location = startADR;
    printf("start address: %d\n", startADR);

    while(!feof(fp)) {
        if (feof(fp)) break;
        char a = fgetc(fp);
        if (a == 'T') {
            int i = 0;
            while (i < 6) {
                a = fgetc(fp);
                i++;
            }
            c = fgets(CODES, 3, fp);
            len = parseInt(c) * 2;
            printf("%d ", len);
            c = fgets(CODES, len+1, fp);
            printf("%s\n", CODES);
            for (int i = 0; i < sizeof(CODES); i+=2) {
                if(CODES[i] == 0) {
                    break;
                }
                else { 
                    printf("%c%c\n", CODES[i], CODES[i+1]);
                    memory[location][0] = CODES[i];
                    memory[location][1] = CODES[i+1];
                    location++;
                }
            }
        }
    }
    for (int i = startADR; i < startADR + size; i++) {
        printf("%d: %s\n", i, memory[i]);
    }
}