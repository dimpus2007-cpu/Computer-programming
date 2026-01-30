#include <stdio.h>
#include <string.h>
#include <ctype.h>


void removeWord(char *str, const char *word) {
    char *pos, temp[1000];
    int index = 0;
    int wordLen = strlen(word);


    while ((pos = strstr(str, word)) != NULL) {

        int lenBefore = pos - str;
        strncpy(temp, str, lenBefore);
        temp[lenBefore] = '\0';


        strcat(temp, pos + wordLen);


        strcpy(str, temp);
    }
}

int main() {
    char str[1000], word[100];

    printf("Enter a string: ");
    if (!fgets(str, sizeof(str), stdin)) {
        printf("Error reading string.\n");
        return 1;
    }
    str[strcspn(str, "\n")] = '\0';

    printf("Enter the word to remove: ");
    if (!fgets(word, sizeof(word), stdin)) {
        printf("Error reading word.\n");
        return 1;
    }
    word[strcspn(word, "\n")] = '\0';


    if (strlen(word) == 0) {
        printf("No word entered. Nothing to remove.\n");
        return 0;
    }

    removeWord(str, word);

    printf("String after removing '%s': %s\n", word, str);

    return 0;
}

