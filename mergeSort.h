#ifndef MM
#define MM
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
void mergeSort(int* a, int p, int r);
void merge(int* A, int p, int q, int r);
void merge2Threads(int* a, int p, int r);
void mergeNThreads(int* a, int p, int r, int thr);
void finalMergeNThreads(int* a, int p, int r, int thr, int* checkPos);

#endif