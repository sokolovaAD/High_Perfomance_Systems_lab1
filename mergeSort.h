#ifndef MM
#define MM
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
void mergeSort(long* a, long p, long r);
void merge(long* A, long p, long q, long r);
void merge2Threads(long* a, long p, long r);
void mergeNThreads(long* a, long p, long r, long thr);
void finalMergeNThreads(long* a, long p, long r, long thr, long* checkPos);

#endif