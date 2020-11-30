#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "parse.h"
#include "LinkedList.h"
#include <string.h>

void modify(char** memory, node* node, int startADR) {
    int ADR = node->ADR;
    int len = node->len;
    char* tmp = malloc(sizeof(char) * (len + 1));
    len = (len + 1) / 2;
    for (int i = 0; i < len; i++) {
        tmp[i*2] = memory[ADR+i][0];
        tmp[i*2+1] = memory[ADR+i][1];
    }
    int value = parseDecimal(tmp);
    value += startADR;
    tmp = parseHexadecimal(value);
    for(int i = 0; i < len; i++) {
        char* temp = malloc(sizeof(char) * 2);
        temp[0] = tmp[i*2];
        temp[1] = tmp[i*2+1];
        memory[ADR+i] = temp;
    }
    free(tmp);
    return;
}

void print(char** memory, node* node) {
    int ADR = node->ADR;
    int len = node->len;
    len = (len + 1) / 2;
    for (int i = 0; i < len; i++) {
        printf("%d: %s\n", ADR+i, memory[ADR+i]);
    }
    return;
}

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

    do {
        startADR = rand() % 32759;
    } while (startADR + size > 32758);

    printf("start address: %d\n", startADR);

    while (!feof(fp)) {
        if (feof(fp)) break;
        char a = fgetc(fp);
        if (a == 'T') {
            int i = 0;
            c = fgets(CODES, 7, fp);
            location = startADR + parseDecimal(CODES);
            c = fgets(CODES, 3, fp);
            len = parseDecimal(CODES) * 2;
            c = fgets(CODES, len + 1, fp);
            for (int i = 0; i < sizeof(CODES); i += 2) {
                if (CODES[i] == 0) {
                    break;
                } else {
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
    printf("Before modifycation\n");
    node* tmp = head->next;
    while (tmp != NULL) {
        print(memory, tmp);
        tmp = tmp->next;
    }
    tmp = head->next;
    printf("After modifycation\n");
    while (tmp != NULL) {
        modify(memory, tmp, startADR);
        print(memory, tmp);
        tmp = tmp->next;
    }
}