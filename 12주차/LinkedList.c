#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

void add(node* cursor, int ADR, int len) {
    node* newNode = malloc(sizeof(node));
    cursor->next = newNode;
    newNode->ADR = ADR;
    newNode->len = len;
    newNode->next = NULL;
}