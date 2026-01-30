#include <stdio.h>
#include <string.h>

int main() {
    char url[200], clean[200];
    int i = 0, j = 0;

    printf("Enter URL: ");
    gets(url);   // for exam use; avoid in real projects

    // Skip http:// or https://
    if (strncmp(url, "http://", 7) == 0)
        i = 7;
    else if (strncmp(url, "https://", 8) == 0)
        i = 8;

    // Skip www.
    if (strncmp(&url[i], "www.", 4) == 0)
        i += 4;

    // Copy till '?' or end
    while (url[i] != '\0' && url[i] != '?') {
        clean[j++] = url[i++];
    }

    // Remove trailing '/'
    if (j > 0 && clean[j - 1] == '/')
        j--;

    clean[j] = '\0';

    printf("Clean URL: %s\n", clean);

    return 0;
}
