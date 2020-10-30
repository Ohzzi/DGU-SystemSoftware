#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void showBytes(unsigned char* data, size_t size) {
    unsigned char* p = data;
    for(int i = 0; i<size; i++) {
        printf("%.2x ", *(p+i));
    }
}

void showIntBytes(int* data, size_t size) {
    unsigned char* p = (unsigned char*) data;
    for(int i = 0; i<size; i++) {
        printf("%.2x ", *(p+i));
    }
}

int main() {
    printf("Enter the path for an input file: ");
    char path[100];
    int d = scanf("%s", path);
    FILE *fp = fopen(path, "r");
    char name[50];
    int goals;
    printf("Name                            Goals\n");
    while(feof(fp) == 0) {
    d = fscanf(fp, "%s %d", name, &goals);
    showBytes(name, strlen(name));
    printf("            ");
    showIntBytes(&goals, sizeof(int));
    printf("\n");
    }
}