#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandom(long *data, int MAX){
    long max = 100000000000;
    srand(time(NULL));
    for(int i=0; i<MAX; i++){
        int value = 0;
        while(value<(max/10)){
            value = (abs(rand()*max)) % max;
        }
        data[i] = value;
    }
}

void swap(long *a, long *b){
    long t = *a;
    *a = *b;
    *b = t;
}

void insertionSort(long *data, int MAX) {
    for (int i = 0; i < MAX; i++) {
        int j = i;
        while (j > 0 && data[j] < data[j - 1]) {
            swap(&data[j], &data[j - 1]);
            j--;
        }
    }
}

void displayData(long *data, int MAX){
    for(int i=0; i<MAX; i++){
        printf("%ld\t",data[i]);
    }
}

int main(){
    int n = 0;
    printf("\nEnter the number of items:");
    scanf("%d",&n);

    clock_t start_t, end_t;
    long dataList[n];

    generateRandom(&dataList, n);
//    printf("Random Data:\n");
//    displayData(&dataList,n);

    start_t = clock();
    insertionSort(&dataList,n);
    end_t = clock();

//    printf("Sorted Data:\n");
//    displayData(&dataList,n);

    double  time = (double)(end_t-start_t)/CLOCKS_PER_SEC;
    printf("\nThe time taken is %lf.\n",time);
    return 0;
}