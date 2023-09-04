#include <stdio.h>
#include <math.h>

#define FALSE 0
#define TRUE 1

int queenPositions[20]; // Array to store the positions of queens

// Function to check if it's safe to place a queen at column k and row i
int isSafeToPlace(int k, int i) {
    for (int j = 1; j <= k; j++) {
        if ((queenPositions[j] == i) || (abs(queenPositions[j] - i) == abs(j - k))) {
            return FALSE; // Not safe to place
        }
    }
    return TRUE; // Safe to place
}

// Function to solve the N Queens problem using backtracking
void solveNQueens(int k, int n) {
    int i, a;
    for (i = 1; i <= n; i++) {
        if (isSafeToPlace(k, i)) {
            queenPositions[k] = i;
            if (k == n) {
                // Print the solution
                for (a = 1; a <= n; a++) {
                    printf("%d\t", queenPositions[a]);
                }
                printf("\n");
            } else {
                solveNQueens(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("\nEnter the number of queens: ");
    scanf("%d", &n);
    printf("\nSolutions to the N Queens problem are:\n");
    solveNQueens(1, n);
    return 0;
}