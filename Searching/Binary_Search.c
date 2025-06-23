#include <stdio.h>

// Recursive function for binary search
int binarySearch(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;  // Key not found

    int mid = (low + high) / 2; 

    if (arr[mid] == key)
        return mid;
    else if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, high, key);
}

int main() {
    int arr[100], n, key, i, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, 0, n - 1, key);

    if (result == -1)
        printf("Element not found in the array.\n");
    else
        printf("Element found at index %d (position %d).\n", result, result + 1);

    return 0;
}
