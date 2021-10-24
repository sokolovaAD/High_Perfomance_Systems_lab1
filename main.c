#include "mergeSort.h"
#include "heapSort.h"
#include <time.h>
#include "logger.h"
#include "loggerHeapSort.h"
#include <string.h>



void timeSort(long bigSize) {
    //unsigned int bigSize = 100 * 500 * 1000;
    long* bigArr = (long*)malloc(bigSize * sizeof(long));
    for (long i = 0; i < bigSize; i++) {
        bigArr[i] = rand() % 10000;
    }

    clock_t begin = clock();

    //heapSort(bigArr, bigSize);
    mergeSort(bigArr,0,bigSize-1);


    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Elapsed 1 thread: %f seconds\n", time_spent);
    //logger(1, bigSize, time_spent);
    free(bigArr);

}


void time2Threads(long bigSize) {
    //unsigned int bigSize = 100 * 500 * 1000;
    long* bigArr = (long*)malloc(bigSize * sizeof(long));
    for (long i = 0; i < bigSize; i++) {
        bigArr[i] = rand() % 10000;
    }

    clock_t begin = clock();

    heapSort2Threads(bigArr, bigSize);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Elapsed 2 Threads: %f seconds\n", time_spent);
    //logger(2, bigSize, time_spent);
    free(bigArr);
}


void timeNThreads(long bigSize, int num) {
    //unsigned int bigSize = 100 * 500 * 1000;
    long* bigArr = (long*)malloc(bigSize * sizeof(long));
    for (long i = 0; i < bigSize; i++) {
        bigArr[i] = rand() % 10000;
    }

    clock_t begin = clock();

    //heapSortNThreads(bigArr, bigSize, num);
    mergeNThreads(bigArr, 0, bigSize-1, num);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Elapsed 4 Threads: %f seconds\n", time_spent);
    //logger(num, bigSize, time_spent, fp);
    free(bigArr);
}

void main() {
    
    long size = 95000000;

    printf("Start 1 Thread: \n");
    //timeSort(size);
    printf("End 1 Thread: \n");
    printf(".............................. \n");

    printf("Start 2 Threads using for: \n");
    //timeNThreads(size, 2);
    printf("End 2 Threads: \n");
    printf(".............................. \n");

    printf("Start 4 Threads using for: \n");
    //timeNThreads(size, 2);
    printf("End 4 Threads: \n");
    printf(".............................. \n");
    

   //logger();
   //smallLogger();

   long long arr[9] = {1,2,9,3,4,5,6,7,8};
   long arr1[11] = {1,10,2,9,3,4,11,5,6,7,8};
   //merge2Threads(arr,0,8);
   //heapSort2Threads(arr1, 10);
   //heapSort(arr1,11);
   //heapSortNThreads(arr1,11,2);
   for (int i=0;i<11;i++) {
       printf("%d ", arr1[i]);
   }
   printf("\n");
   //loggerHeapSort();


}

