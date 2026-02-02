#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000
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

    if (len == 0) {
        printf("Empty string entered.\n");
        return 0;
    }

    printf("Characters at even index positions: ");
    for (size_t i = 0; i < len; i += 2) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}

