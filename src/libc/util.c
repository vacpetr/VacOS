#include "util.h"

void int_to_string(u32 val, char* str){
    int index = 0;

    if(val < 0){
        str[0] = '-';
        index++;
    }

    while(val > 0){
        str[index++] = '0'+(val%10);
        val /= 10;
    }

    reverse_string(str);
}

void reverse_string(char* str){
    int c, i, j;

    for (i = 0, j = strlen(str)-1; i < j; i++, j--) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}

int strlen(char* str) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}