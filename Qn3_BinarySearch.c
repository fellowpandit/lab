#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 "Digishop" an online shopping website needs to keep track of the product availability based on the product ID.
 Design a program in C to read the product ID provided by the customer search for its availability by using
 Binary Search method. Determine the time required to search for the product. Repeat the experiment for different
 values of n and plot a graph of the time taken versus n. (n=no. of elements.)
 */

int binarySearch(long *data, int start, int end, long x){
    int mid = (start+end)/2;
    if(data[mid] == x){
        return mid;
    }else if(start == mid){
        return -1;
    }else if(x<data[mid]){
        return binarySearch(data, start, mid, x);
    }else if(x>data[mid]){
        return binarySearch(data, mid+1,end,x);
    }else{
        return -1;
    }
}

void swap(long *a, long *b){
    long t = *a;
    *a = *b;
    *b = t;
}

void sort(long *data, int n){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(data[i]<data[j])
                swap(&data[i], &data[j]);
}

void display(long *data, int n){
    for(int i=0; i<n; i++)
        printf("%ld\t",data[i]);
}

void generateRandom(long *data, int n){
    for(int i=0; i<n; i++)
        data[i] = rand()%100;
}

int main(){
    int n = 0;
    printf("\nEnter the number of items:");
    scanf("%d",&n);

    clock_t start_t, end_t;
    long data[n];
    generateRandom(data, n);

    sort(data, n);
    display(data, n);

    long x;
    printf("\n Enter the Product ID: ");
    scanf("%ld",&x);

    start_t = clock();
    int ans = binarySearch(data, 0, n-1, x);
    end_t = clock();

    if(ans==-1) printf("Product Data not found!");
    else printf("\nThe product data was found at %d.",ans);

    double time=(double)(end_t-start_t)/CLOCKS_PER_SEC;
    printf("\nThe time taken is %lf.\n",time);
    return 0;
}
