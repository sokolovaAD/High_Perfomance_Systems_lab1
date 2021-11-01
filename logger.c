#include "logger.h"



double logNThreads(long size, char opt) {
        long* bigArr = (long*)malloc(size * sizeof(long));
        for (long i = 0; i < size; i++) {
            bigArr[i] = rand() % 1000000;
        }
        clock_t begin = clock();

        switch (opt)
        {
            case '1':
            mergeSort(bigArr, 0, size - 1);
            break;

            case '2':
            merge2Threads(bigArr, 0, size - 1);
            break;

            case '3':
            mergeNThreads(bigArr, 0, size - 1, 2);
            break;

            case '4':
            mergeNThreads(bigArr, 0, size - 1, 4);
            break;
        }

        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        free(bigArr);
        return time_spent;
}

// вывод затраченного на сортировку времени в лог файл
int logger() {
    FILE *fp;
    if ((fp = fopen("mergeSort.log", "w"))==NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    long sizeFinish = 1000*1000*100;
    long sizePlus = 10000000;
    fprintf(fp, "....................................................\n");
    fprintf(fp, "LOG FOR 1 THREAD\n");
    for (long size = 5000000; size<=sizeFinish; size+=sizePlus) {
        double time = logNThreads(size, '1');
        fprintf(fp, "size: %lld, time: %f\n", size, time);
    }
    fprintf(fp, "....................................................\n");

    fprintf(fp, "LOG FOR 2 THREADS USING SECTIONS\n");
    for (long size = 5000000; size<=sizeFinish; size+=sizePlus) {
        double time = logNThreads(size, '2');
        fprintf(fp, "size: %lld, time: %f\n", size, time);
    }
    fprintf(fp, "....................................................\n");

    fprintf(fp, "LOG FOR 2 THREADS USING FOR\n");
    for (long size = 5000000; size<=sizeFinish; size+=sizePlus) {
        double time = logNThreads(size, '3');
        fprintf(fp, "size: %lld, time: %f\n", size, time);
    }
    fprintf(fp, "....................................................\n");

    fprintf(fp, "LOG FOR 4 THREADS USING FOR\n");
    for (long size = 5000000; size<=sizeFinish; size+=sizePlus) {
        double time = logNThreads(size, '4');
        fprintf(fp, "size: %lld, time: %f\n", size, time);
    }
    fprintf(fp, "....................................................\n");


    fclose(fp);
    return 0;
}


int smallLogger() {
    FILE *fp;
    if ((fp = fopen("mergeSortSmall.log", "w"))==NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    long sizeFinish = 1000*1000;
    long sizePlus = 100000;
    fprintf(fp, "....................................................\n");
    fprintf(fp, "LOG FOR 1 THREAD\n");
    for (long size = 100000; size<=sizeFinish; size+=sizePlus) {
        double time = logNThreads(size, '1');
        fprintf(fp, "size: %lld, time: %f\n", size, time);
    }
    fprintf(fp, "....................................................\n");

    fprintf(fp, "LOG FOR 2 THREADS USING SECTIONS\n");
    for (long size = 100000; size<=sizeFinish; size+=sizePlus) {
        double time = logNThreads(size, '2');
        fprintf(fp, "size: %lld, time: %f\n", size, time);
    }
    fprintf(fp, "....................................................\n");

    fprintf(fp, "LOG FOR 2 THREADS USING FOR\n");
    for (long size = 100000; size<=sizeFinish; size+=sizePlus) {
        double time = logNThreads(size, '3');
        fprintf(fp, "size: %lld, time: %f\n", size, time);
    }
    fprintf(fp, "....................................................\n");

    fprintf(fp, "LOG FOR 4 THREADS USING FOR\n");
    for (long size = 100000; size<=sizeFinish; size+=sizePlus) {
        double time = logNThreads(size, '4');
        fprintf(fp, "size: %lld, time: %f\n", size, time);
    }
    fprintf(fp, "....................................................\n");


    fclose(fp);
    return 0;
}


