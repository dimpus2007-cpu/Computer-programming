#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[256] = {0};
    int i, count;

    printf("Enter string: ");
    scanf("%s", str);

    /* Count frequency of each character */
    for (i = 0; str[i] != '\0'; i++) {
        freq[str[i]]++;
    }

    /* String Compression */
    printf("Compressed string: ");
    for (i = 0; str[i] != '\0'; i++) {
        count = 1;
        while (str[i] == str[i + 1]) {
            count++;
            i++;
        }
        printf("%c%d", str[i], count);
    }

    /* First non-repeating character */
    for (i = 0; str[i] != '\0'; i++) {
        if (freq[str[i]] == 1) {
            printf("\nFirst non-repeating character: %c\n", str[i]);
            break;
        }
    }

    return 0;
}
