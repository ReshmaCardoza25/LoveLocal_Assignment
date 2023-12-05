#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    int smallest = a;
    if (b < smallest) {
        smallest = b;
    }
    if (c < smallest) {
        smallest = c;
    }
    return smallest;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {// Function to find the largest square containing only 1's
    if (matrixSize == 0 || *matrixColSize == 0) {
        return 0;
    }

    int maxSide = 0;
    int** dp = (int**)malloc(matrixSize * sizeof(int*));

    for (int i = 0; i < matrixSize; i++) {
        dp[i] = (int*)malloc((*matrixColSize) * sizeof(int));
        for (int j = 0; j < *matrixColSize; j++) {
            dp[i][j] = matrix[i][j] - '0';
            if (i > 0 && j > 0 && dp[i][j] == 1) {
                dp[i][j] += min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
            }
            if (dp[i][j] > maxSide) {
                maxSide = dp[i][j];
            }
        }
    }

    // Free the allocated memory
    for (int i = 0; i < matrixSize; i++) {
        free(dp[i]);
    }
    free(dp);

    return maxSide * maxSide;
}

int main() { // Get input from the user
    int m, n;
    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns (n): ");
    scanf("%d", &n);

    char** matrix = (char**)malloc(m * sizeof(char*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (char*)malloc(n * sizeof(char));
        printf("Enter the elements of row %d (use '0' or '1', without spaces): ", i + 1);
        scanf("%s", matrix[i]);
    }

    // Find the largest square containing only 1's and print the result
    int result = maximalSquare(matrix, m, &n);
    printf("Output: %d\n", result);
    for (int i = 0; i < m; i++) {// To free the allocated memory
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
