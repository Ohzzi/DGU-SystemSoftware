#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// linked list
typedef struct List {
    struct Node* head;
} list;

// linked list를 구성하는 node
typedef struct Node {
    char data;
    struct Node* next;
} node;

// list에 node 추가
void add(list* list, char data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
    }
    else {
        node* tmp = list->head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
}

// list의 모든 node를 출력
void printList(list* list) {
    node* tmp = list->head;
    while (tmp != NULL) {
        if (tmp->data == '\n') {
            printf("\n");
        }
        else if (isalpha(tmp->data)) {
            printf("%d ", tmp->data - 'A' + 10);
        } else {
            printf("%c ", tmp->data);
        }
        tmp = tmp->next;
    }
}

int main(int argc, char* argv[]) {
    list* nodeList = (list*)malloc(sizeof(list));
    nodeList->head = NULL;
    char CODES[52];
    if (argv[1] != NULL) {
        printf("Input file name: %s\n", argv[1]);
    } else {
        printf("error: Command line argument is not entered.\n");
        return 0;
    }
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("error: Unvalid file path\n");
        return 0;
    }
    printf("\nCodes:\n");
    char* c = fgets(CODES, 21, fp);
    int cnt = 0;
    while (!feof(fp)) {
        if (feof(fp)) break;
        int a = fgetc(fp);
        if (a == 'T') {
            int i = 0;
            while (i < 8) {
                a = fgetc(fp);
                i++;
            }
            c = fgets(CODES, 52, fp);
            printf("%s", CODES);
            for (int i = 0; i < sizeof(CODES); i++) {
                if(CODES[i] == '\n') {
                    break;
                }
                add(nodeList, CODES[i]);
                if(i == sizeof(CODES)-1 && CODES[i] != '\n') {
                    printf("\n");
                }
            }
            add(nodeList,'\n');
        }
    }
    printf("\n\n");
    printList(nodeList);
    fclose(fp);
}