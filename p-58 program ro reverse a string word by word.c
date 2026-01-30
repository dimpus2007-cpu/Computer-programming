#include <stdio.h>
#include <string.h>
#include <ctype.h>


void reverse(char *str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}


void normalizeSpaces(char *str) {
    int i = 0, j = 0;
    int len = strlen(str);

    // Skip leading spaces
    while (i < len && isspace((unsigned char)str[i])) i++;

    int spaceFound = 0;
    while (i < len) {
        if (!isspace((unsigned char)str[i])) {
            str[j++] = str[i++];
            spaceFound = 0;
        } else {
            if (!spaceFound) {
                str[j++] = ' ';
                spaceFound = 1;
            }
            i++;
        }
    }

    if (j > 0 && str[j - 1] == ' ')
        j--;

    str[j] = '\0';
}


void reverseWords(char *str) {
    normalizeSpaces(str); // Clean up spaces

    int len = strlen(str);
    if (len == 0) return;


    reverse(str, 0, len - 1);


    int start = 0;
    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            reverse(str, start, i - 1);
            start = i + 1;
        }
    }
}

int main() {
    char str[200];

    printf("Enter a string: ");
    if (!fgets(str, sizeof(str), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }

    str[strcspn(str, "\n")] = '\0';

    reverseWords(str);

    printf("Reversed string word by word: \"%s\"\n", str);

    return 0;
}
