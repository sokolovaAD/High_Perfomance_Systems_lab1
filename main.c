#include "./mergeSort.h"
#include "./heapSort.h"
#include <time.h>

void timeSort() {
    unsigned int bigSize1 = 100 * 100 * 1000;
    int* bigArr1 = (int*)malloc(bigSize1 * sizeof(int));
    for (unsigned int i = 0; i < bigSize1; i++) {
        bigArr1[i] = rand() % 10000;
    }

    clock_t begin1 = clock();

    mergeSort(bigArr1, 0, bigSize1 - 1);


    clock_t end1 = clock();
    double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
    printf("Elapsed 1 thread: %f seconds\n", time_spent1);
    free(bigArr1);

}


void time2Threads() {
    unsigned int bigSize2 = 100 * 100 * 1000;
    int* bigArr2 = (int*)malloc(bigSize2 * sizeof(int));
    for (unsigned int i = 0; i < bigSize2; i++) {
        bigArr2[i] = rand() % 10000;
    }

    clock_t begin2 = clock();

    merge2Threads(bigArr2, 0, bigSize2 - 1);

    clock_t end2 = clock();
    double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    printf("Elapsed 2 Threads: %f seconds\n", time_spent2);
    free(bigArr2);
}


void time4Threads() {
    unsigned int bigSize3 = 100 * 100 * 1000;
    int* bigArr3 = (int*)malloc(bigSize3 * sizeof(int));
    for (unsigned int i = 0; i < bigSize3; i++) {
        bigArr3[i] = rand() % 10000;
    }

    clock_t begin3 = clock();

    mergeNThreads(bigArr3, 0, bigSize3 - 1, 4);

    clock_t end3 = clock();
    double time_spent3 = (double)(end3 - begin3) / CLOCKS_PER_SEC;
    printf("Elapsed 4 Threads: %f seconds\n", time_spent3);
    free(bigArr3);
}

void main() {
    printf("hello \n");
    int arr[21] = {21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };
    int arr1[8] = { 8, 7, 6, 5, 4, 3, 2, 1 };


    int a = 0;
    int size = sizeof(arr) / sizeof(int) - 1;
    int size1 = sizeof(arr1) / sizeof(int) - 1;

    for (int i = 0; i <= size; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");

    //mergeSort(arr, a, size);
    //merge2Threads(arr, a, size);
    mergeNThreads(arr, a, size, 2); 


    for (int i = 0; i <= size; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");



    timeSort();
    time2Threads();
    time4Threads();


}

