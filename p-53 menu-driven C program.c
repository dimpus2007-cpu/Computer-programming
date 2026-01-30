#include <stdio.h>

void display(int *a, int n) {
    int i;
    printf("Array elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");
}

void bubbleAsc(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Sorted (Small → Large)\n");
}

void bubbleDesc(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Sorted (Large → Small)\n");
}

void binarySearch(int a[], int n) {
    int low = 0, high = n - 1, mid, key;
    printf("Enter element to search: ");
    scanf("%d", &key);

    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) {
            printf("Element found at position %d\n", mid + 1);
            return;
        } else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("Element not found\n");
}

int main() {
    int a[50], n, choice, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    do {
        printf("\nMENU\n");
        printf("1. Bubble Sort (Small to Large)\n");
        printf("2. Bubble Sort (Large to Small)\n");
        printf("3. Binary Search\n");
        printf("4. Display Array (Using Pointer)\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubbleAsc(a, n);
                break;
            case 2:
                bubbleDesc(a, n);
                break;
            case 3:
                bubbleAsc(a, n);   // Binary search needs sorted array
                binarySearch(a, n);
                break;
            case 4:
                display(a, n);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
