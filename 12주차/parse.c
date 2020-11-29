#include <stdlib.h>
#include <string.h>
#include <math.h>

int parseDecimal(char *c) {
    int decimal = 0, pos = 0;
    for (int i = strlen(c) - 1; i >= 0; i--) {
        char ch = c[i];
        if (ch >= 48 && ch <= 57) {
            decimal += (ch - 48) * pow(16, pos);
        } else if (ch >= 65 && ch <= 70) {
            decimal += (ch - 55) * pow(16, pos);
        }
        pos++;
    }
    return decimal;
}

char *parseHexadecimal(int decimal) {
    char tmp[20];
    int pos = 0;
    while (1) {
        int mod = decimal % 16;
        if (mod < 10) {
            tmp[pos] = 48 + mod;
        } else {
            tmp[pos] = 65 + (mod - 10);
        }
        decimal = decimal / 16;
        pos++;
        if (decimal == 0)
            break;
    }
    char *hexadecimal = malloc(sizeof(tmp));
    for (int i = 0; i < pos; i++) {
        hexadecimal[i] = tmp[pos - 1 - i];
    }
    return hexadecimal;
}
