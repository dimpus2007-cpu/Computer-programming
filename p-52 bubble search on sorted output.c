#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Bubble Sort function
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break; // Optimization: stop if already sorted
    }
}

// Binary Search function
int binarySearch(int arr[], int n, int target, int *closestSmaller, int *closestLarger) {
    int low = 0, high = n - 1;
    *closestSmaller = -1; // -1 means no smaller element
    *closestLarger = -1;  // -1 means no larger element

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Found
        } else if (arr[mid] < target) {
            *closestSmaller = arr[mid];
            low = mid + 1;
        } else {
            *closestLarger = arr[mid];
            high = mid - 1;
        }
    }
    return -1; // Not found
}

int main() {
    int n, target;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    // Sort the array
    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter element to search: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int closestSmaller, closestLarger;
    int index = binarySearch(arr, n, target, &closestSmaller, &closestLarger);

    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
    } else {
        printf("Element %d not found.\n", target);
        if (closestSmaller != -1)
            printf("Closest smaller element: %d\n", closestSmaller);
        else
            printf("No smaller element exists.\n");

        if (closestLarger != -1)
            printf("Closest larger element: %d\n", closestLarger);
        else
            printf("No larger element exists.\n");
    }

    return 0;
}
