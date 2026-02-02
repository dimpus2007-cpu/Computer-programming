#include <stdio.h>
#include <string.h>

int main()
{
    char str[200], word[50];
    char smallest[50], largest[50];
    int i = 0, j = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);


    smallest[0] = largest[0] = '\0';

    while (1)
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\0')
        {
            word[j] = '\0';

            if (j > 0)
            {
                if (smallest[0] == '\0' || strlen(word) < strlen(smallest))
                    strcpy(smallest, word);

                if (largest[0] == '\0' || strlen(word) > strlen(largest))
                    strcpy(largest, word);
            }
            j = 0;

            if (str[i] == '\0')
                break;
        }
        else
        {
            word[j++] = str[i];
        }
        i++;
    }

    printf("Smallest word: %s\n", smallest);
    printf("Largest word: %s\n", largest);

    return 0;
}
