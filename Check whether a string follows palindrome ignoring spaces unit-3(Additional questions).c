#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[200], temp[200];
    int i, j = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);


    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && str[i] != '\n')
        {
            temp[j++] = tolower(str[i]);
        }
    }
    temp[j] = '\0';

    int left = 0, right = j - 1;
    int isPalindrome = 1;

    while (left < right)
    {
        if (temp[left] != temp[right])
        {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        printf("The string is a palindrome\n");
    else
        printf("The string is not a palindrome\n");

    return 0;
}
