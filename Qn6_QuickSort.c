#include <stdio.h>
#include<stdlib.h>
#include <time.h>

int partition(int array[], int low, int high) {
    int i, j, temp, pivot;
    pivot = array[low];
    i = low + 1;
    j = high;

    while (1) {
        while (i < high && array[i] <= pivot)
            i++;
        while (array[j] > pivot)
            j--;

        if (i < j) {
            //swapping i and j
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        } else {
            //swapping j and low
            temp = array[j];
            array[j] = array[low];
            array[low] = temp;
            return j;
        }
    }
}

void quick_sort(int array[], int low, int high) {
    int partition_index;
    if (low < high) {
        partition_index = partition(array, low, high);
        quick_sort(array, low, partition_index - 1);
        quick_sort(array, partition_index + 1, high);
    }
}

int main() {
    int i, n, rollNumbers[200000];
    double runtime;
    clock_t startTime, endTime;

    printf("Enter the number of student records: \n");
    scanf("%d", &n);

    printf("The roll numbers are \t\n");
    for (i = 0; i < n; i++) {
        rollNumbers[i] = rand() % 100;
        printf("\t%d", rollNumbers[i]);
    }

    startTime = clock();
    quick_sort(rollNumbers, 0, n - 1);
    endTime = clock();

    runtime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("\nSorted roll numbers are: \n");
    for (i = 0; i < n; i++)
        printf("\t%d", rollNumbers[i]);

    printf("\nThe runtime is %f\n", runtime);

    return 0;
}
