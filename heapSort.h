#ifndef HEAP_H
#define HEAP_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>


void downHeap(long* a, long k, long n, long size, long info);

void heapSort(long* a , long size);
void heapSort2Threads(long* a , long size);
void heapSortNThreads(long* a , long size, int thr);


#endif

