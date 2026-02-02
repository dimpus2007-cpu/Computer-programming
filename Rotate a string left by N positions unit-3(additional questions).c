#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void leftRotateString(char *str, int n) {
    int len = strlen(str);


    if (len == 0) {
        return;
    }


    n = n % len;
    if (n == 0) {
        return;
    }


    char *temp = (char *)malloc(len + 1);
    if (!temp) {
        printf("Memory allocation failed.\n");
        exit(1);
    }


    strcpy(temp, str + n);


    strncat(temp, str, n);



    free(temp);
}

int main() {
    char str[1000];
    int n;

    printf("Enter a string: ");
    if (!fgets(str, sizeof(str), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }


    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    printf("Enter number of positions to rotate left: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    if (n < 0) {
        printf("Negative rotation not allowed. Use positive integers.\n");
        return 1;
    }

    leftRotateString(str, n);

    printf("Rotated string: %s\n", str);

    return 0;
}

