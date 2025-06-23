#include <stdio.h>

#define ROWS 4
#define COLS 3

int main() {
    int matrix[ROWS][COLS] = {
        {0, 0, 3},
        {0, 0, 0},
        {5, 0, 0},
        {0, 2, 0}
    };

    int sparse[10][3];  // To store triplets: row, col, value
    int k = 0;  // counter for non-zero elements

    // Traverse matrix and store non-zero elements
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    // Print the sparse matrix representation
    printf("Sparse Matrix Representation (Triplet form):\n");
    printf("Row Col Value\n");
    for (int i = 0; i < k; i++) {
        printf("%3d %3d %5d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    return 0;
}
