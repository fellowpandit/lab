#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50

int employeeIDs[MAX];

void merge(int low, int mid, int high) {
    int leftIndex, rightIndex, mergedIndex, tempArray[MAX];
    leftIndex = low;
    rightIndex = mid + 1;
    mergedIndex = low;

    while ((leftIndex <= mid) && (rightIndex <= high)) {
        if (employeeIDs[leftIndex] <= employeeIDs[rightIndex]) {
            tempArray[mergedIndex] = employeeIDs[leftIndex];
            leftIndex++;
        } else {
            tempArray[mergedIndex] = employeeIDs[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }

    if (leftIndex > mid) {
        for (int i = rightIndex; i <= high; i++) {
            tempArray[mergedIndex] = employeeIDs[i];
            mergedIndex++;
        }
    } else {
        for (int i = leftIndex; i <= mid; i++) {
            tempArray[mergedIndex] = employeeIDs[i];
            mergedIndex++;
        }
    }

    for (int i = low; i <= high; i++)
        employeeIDs[i] = tempArray[i];
}

void merge_sort(int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main() {
    int numberOfEmployees, i;
    double runtime;
    clock_t startTime, endTime;

    printf("MERGE SORT\n");
    printf("Enter the number of employee records: ");
    scanf("%d", &numberOfEmployees);

    printf("\nEmployee ID:");
    for (i = 0; i < numberOfEmployees; i++) {
        employeeIDs[i] = rand() % 100;
        printf("\t%d", employeeIDs[i]);
    }

    startTime = clock();
    merge_sort(0, numberOfEmployees - 1);
    endTime = clock();

    runtime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("\nEmployee IDs in sorted order:\n");
    for (i = 0; i < numberOfEmployees; i++) {
        printf("\t%d", employeeIDs[i]);
    }
    printf("\nThe runtime is %f\n", runtime);
    return 0;
}
