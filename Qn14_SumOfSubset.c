#include <stdio.h>

int count, weights[10], desiredSum, solution[10];

void findSubsets(int currentSum, int k, int remainingSum) {
    int i;
    solution[k] = 1;
    if ((currentSum + weights[k]) == desiredSum) {
        printf("\nSubset solution = %d\n", ++count);
        for (i = 0; i <= k; i++) {
            if (solution[i] == 1) {
                printf("%d\n", weights[i]);
            }
        }
    } else if ((currentSum + weights[k] + weights[k + 1]) <= desiredSum) {
        findSubsets(currentSum + weights[k], k + 1, remainingSum - weights[k]);
    }
    if ((currentSum + remainingSum - weights[k] >= desiredSum) && (currentSum + weights[k + 1]) <= desiredSum) {
        solution[k] = 0;
        findSubsets(currentSum, k + 1, remainingSum - weights[k]);
    }
}

int main() {
    int sum = 0, i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements in ascending order:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &weights[i]);
    printf("Enter the desired sum: ");
    scanf("%d", &desiredSum);
    for (i = 0; i < n; i++)
        sum += weights[i];
    if (sum < desiredSum) {
        printf("No solution exists.\n");
    }
    printf("The solution is:\n");
    count = 0;
    findSubsets(0, 0, sum);
    return 0;
}
