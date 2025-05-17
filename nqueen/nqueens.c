#include <stdio.h>
#include <stdlib.h>

int isSafe(int board[], int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    return 1;
}

void printSolution(int board[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        printf("\n");
    }
    printf("\n");
}

void solveNQueens(int board[], int row, int n, int *count) {
    if (row == n) {
        printSolution(board, n);
        (*count)++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row] = col;
            solveNQueens(board, row + 1, n, count);
        }
    }
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    int board[n];
    int count = 0;
    solveNQueens(board, 0, n, &count);
    printf("Total solutions: %d\n", count);
    return 0;
}