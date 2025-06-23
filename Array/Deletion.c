#include <stdio.h>
int main() {
    int arr[10] = {10, 20, 30, 40};
    int n = 4;
    int pos = 1;  // index to delete

    // Shift elements left
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;  // size decreases

    printf("After Deletion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
