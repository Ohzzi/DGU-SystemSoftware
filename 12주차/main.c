#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "parse.h"
#include "LinkedList.h"

int main(int argc, char *argv[]) {
    char *memory[32759];
    char CODES[60];
    char *c;
    int startADR, size, len, location;
    node* head = malloc(sizeof(node));
    head->next = NULL;
    node* tail = head;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 32759; i++) {
        memory[i] = malloc(sizeof(char) * 2);
        // memory[i] = "00";
    }
    if (argv[1] == NULL) {
        printf("error: Command line argument is not entered.\n");
        return 0;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("error: Unvalid file path\n");
        return 0;
    }
    c = fgets(CODES, 16, fp);
    c = fgets(CODES, 5, fp);
    size = parseDecimal(CODES);
    size = 160;

    /* do {
        startADR = rand() % 32759;
    } while (startADR + size > 32758); */
    startADR = 2260;
    location = startADR;
    printf("start address: %d\n", startADR);

    while (!feof(fp)) {
        if (feof(fp)) break;
        char a = fgetc(fp);
        if (a == 'T') {
            int i = 0;
            while (i < 6) {
                a = fgetc(fp);
                i++;
            }
            c = fgets(CODES, 3, fp);
            len = parseDecimal(CODES) * 2;
            //printf("%d ", len);
            c = fgets(CODES, len + 1, fp);
            //printf("%s\n", CODES);
            for (int i = 0; i < sizeof(CODES); i += 2) {
                if (CODES[i] == 0) {
                    break;
                } else {
                    //printf("%c%c\n", CODES[i], CODES[i + 1]);
                    memory[location][0] = CODES[i];
                    memory[location][1] = CODES[i + 1];
                    location++;
                }
            }
        } else if (a == 'M') {
            c = fgets(CODES, 5, fp);
            int ADR = startADR + parseDecimal(CODES);
            c = fgets(CODES, 3, fp);
            ADR += parseDecimal(CODES);
            c = fgets(CODES, 3, fp);
            int modlen = parseDecimal(CODES);
            add(tail, ADR, modlen);
            tail = tail->next;
        }
    }
    /* for (int i = startADR; i < startADR + size; i++) {
        printf("%d: %s\n", i, memory[i]);
    } */
    node* tmp = head->next;
    while (tmp != NULL) {
        printf("%d %d\n", tmp->ADR, tmp->len);
        tmp = tmp->next;
    }
}