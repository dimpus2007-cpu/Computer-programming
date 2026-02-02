#include <stdio.h>
#include <string.h>
#include <ctype.h>


void removeDuplicates(char *str) {
    int hash[256] = {0};
    int i, j = 0;
    char temp;

    for (i = 0; str[i] != '\0'; i++) {
        temp = str[i];
        unsigned char index = (unsigned char)temp;


        if (hash[index] == 0) {
            hash[index] = 1;
            str[j++] = str[i];
        }

    }
    str[j] = '\0';
}

int main() {
    char str[256];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    removeDuplicates(str);

    printf("String after removing duplicates: %s\n", str);

    return 0;
}

