#include <stdio.h>

#define MAXL 1000

//#define  root i+sh
#define  left 2*i+1+sh
#define right 2*i+2+sh

void swap(int* a, int* b);
void sort(int* a, int p, int q);

//void sort2Threads(int* a, int n);
//void sortThreads(int* a, int n, int sh, int n, int root);