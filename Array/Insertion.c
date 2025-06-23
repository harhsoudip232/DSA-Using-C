#include <stdio.h>
int main() {
    int arr[10] = {10, 20, 30, 40};
    int n = 4;  // current size
    int pos = 2;  // index to insert
    int value = 25;

    // Shift elements right
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    n++;  // size increases

    printf("After Insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
