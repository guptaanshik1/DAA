#include<stdio.h>
#include<math.h>
// #include <stdbool.h>

int min(int a, int b) { return (a > b) ? b : a; }

int isSafe (int board[10][10], int n, int row, int col) {
    int i;
    for (i = 0; i < n; i++) {
        if (board[i][col] == 1) {
            return 0;
        }
    }
    
    int leftDiagnol = min(row, col);
    for (i = 1; i <= leftDiagnol; i++) {
        if (board[row - i][col - i] == 1) {
            return 0;
        }
    }
    
    int rightDiagnol = min(row, n - col - 1);
    for (i = 0; i < rightDiagnol + 1; i++) {
        if (board[row - 1][col + 1] == 1) {
            return 0;
        }
    }
    return 1;
}

void display(int board[10][10], int n) {
    int row, col;
    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++) {
            if (board[row][col] == 1) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int queenCount(int board[10][10], int n, int row) {
    if (row == n) {
        display(board, n);
        printf("\n");
        return 1;
    }

    int count = 0;
    int col;
    for (col = 0; col < n; col++) {
        if (isSafe(board, n, row, col) == 1) {
            board[row][col] = 1;
            count += queenCount(board, n, row + 1);
            board[row][col] = 0;
        } 
    }
    
    return count;
}

int main () {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    int board[10][10] = { 0 };
    int ans = queenCount(board, n, 0);
    printf("%d", ans);
}
