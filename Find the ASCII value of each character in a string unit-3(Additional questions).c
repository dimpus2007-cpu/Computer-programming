#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

int main() {
    char str[MAX_LEN];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    printf("\nCharacter\tASCII Value\n");
    printf("-----------------------------\n");

    for (size_t i = 0; i < len; i++) {
        printf("'%c'\t\t%d\n", str[i], (unsigned char)str[i]);
    }

    return 0;
}

