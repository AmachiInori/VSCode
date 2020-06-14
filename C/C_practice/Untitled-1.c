#include <stdio.h>

char nextChar(char x) {
    char res = x + 1;
    if (res >= (char)'z') 
        res = 'a';
    return res;
}

int main() {
    int length;
    char firstChar;
    scanf("%d", &length);
    getchar();
    scanf("%c", &firstChar);
    for (int i = 0; i < length; i++) {
        printf("%c", firstChar);
        firstChar = nextChar(firstChar);
    }
    printf("\n");
    for (int i = 0; i < length - 2; i++) {
        for (int j = 0; j < length - 2 - i; j++)
            printf(" ");
        printf("%c\n", firstChar);
        firstChar = nextChar(firstChar);
    }
    for (int i = 0; i < length; i++) {
        printf("%c", firstChar);
        firstChar = nextChar(firstChar);
    }
    printf("\n");

    return 0;
}