#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000


void longestUniqueWithDigit(const char *s) {
    int lastIndex[256]; // Stores last index of each character
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    int start = 0, maxLen = 0, maxStart = 0;
    int hasDigit = 0; // Tracks if current window has a digit

    for (int end = 0; s[end] != '\0'; end++) {
        char ch = s[end];

                if (lastIndex[(unsigned char)ch] >= start) {

            hasDigit = 0;
            for (int k = lastIndex[(unsigned char)ch] + 1; k <= end; k++) {
                if (isdigit((unsigned char)s[k])) {
                    hasDigit = 1;
                    break;
                }
            }
            start = lastIndex[(unsigned char)ch] + 1;
        }


        lastIndex[(unsigned char)ch] = end;


        if (isdigit((unsigned char)ch)) {
            hasDigit = 1;
        }

        if (hasDigit && (end - start + 1) > maxLen) {
            maxLen = end - start + 1;
            maxStart = start;
        }
    }

    if (maxLen > 0) {
        printf("Longest substring: \"");
        for (int i = maxStart; i < maxStart + maxLen; i++) {
            putchar(s[i]);
        }
        printf("\"\nLength: %d\n", maxLen);
    } else {
        printf("No valid substring found.\n");
    }
}

int main() {
    char s[MAX_LEN];

    printf("Enter the string: ");
    if (!fgets(s, sizeof(s), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }


    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    longestUniqueWithDigit(s);
    return 0;
}
