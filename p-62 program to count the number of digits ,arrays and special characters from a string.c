#include <stdio.h>

int main() {
    char str[100];
    int i, digits = 0, alphabets = 0, special = 0;

    printf("Enter a string: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            digits++;
        else if ((str[i] >= 'A' && str[i] <= 'Z') ||
                 (str[i] >= 'a' && str[i] <= 'z'))
            alphabets++;
        else
            special++;
    }

    printf("Digits = %d\n", digits);
    printf("Alphabets = %d\n", alphabets);
    printf("Special characters = %d\n", special);

    return 0;
}
