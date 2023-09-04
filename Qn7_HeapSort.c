#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to build a max heap
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to the end
        swap(&arr[0],&arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    printf("Enter the number of resumes: ");
    scanf("%d", &n);

    int rankings[n];
    srand(time(NULL));

    // Generate random rankings for resumes (assuming a range from 1 to 100)
    printf("Random rankings:\n");
    for (int i = 0; i < n; i++) {
        rankings[i] = rand() % 100 + 1;
        printf("%d ", rankings[i]);
    }

    // Perform heap sort on the rankings
    clock_t start_t, end_t;
    start_t = clock();
    heapSort(rankings, n);
    end_t = clock();

    // Calculate and print the time taken for sorting in seconds
    double executionTime = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\n\nTime taken for sorting: %f seconds\n", executionTime);

    // Print the sorted rankings
    printf("Sorted rankings:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", rankings[i]);
    }
    printf("\n");

    return 0;
}
