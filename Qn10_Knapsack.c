#include <stdio.h>
#include <time.h>

int max(int x, int y) {
    return (x > y) ? x : y;
}

int knapsack(int numItems, int weights[10], int values[10], int capacity, int table[10][10]) {
    int i, j;

    for (i = 0; i <= numItems; i++) {
        for (j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (j < weights[i])
                table[i][j] = table[i - 1][j];
            else
                table[i][j] = max(table[i - 1][j], values[i] + table[i - 1][j - weights[i]]);
        }
    }

    printf("\nThe table for solving the knapsack problem using dynamic programming is:\n");
    for (i = 0; i <= numItems; i++) {
        for (j = 0; j <= capacity; j++) {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }

    return table[numItems][capacity];
}

int main() {
    double elapsedTime;
    clock_t startTime, endTime;
    int table[10][10], numItems, i, j, weights[10], values[10], capacity, result;

    printf("Enter the number of items:");
    scanf("%d", &numItems);

    printf("Enter the weights of %d items:\n", numItems);
    for (i = 1; i <= numItems; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the values of %d items:\n", numItems);
    for (i = 1; i <= numItems; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter the capacity of the knapsack:");
    scanf("%d", &capacity);

    for (i = 0; i <= numItems; i++) {
        for (j = 0; j <= capacity; j++) {
            table[i][j] = 0;
        }
    }

    startTime = clock();
    result = knapsack(numItems, weights, values, capacity, table);
    endTime = clock();

    elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("Optimal solution for the knapsack problem is %d\n", result);
    printf("Time taken for execution: %f seconds\n", elapsedTime);

    return 0;
}
