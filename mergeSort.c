#include "./mergeSort.h"

void mergeSort(long* a, long p, long r) {
    if (p >= r)
        return;
    long q = (p + r) / 2;
    mergeSort(a, p, q);
    mergeSort(a, q + 1, r);
    merge(a, p, q, r);
    

}


void merge2Threads(long* a, long p, long r) {
    long q = (p + r) / 2;
    #pragma omp parallel sections
    {
            #pragma omp section
            {
                printf ("id = %d, \n", omp_get_thread_num());
                mergeSort(a, p, q);
            }
            #pragma omp section 
            {
               printf ("id = %d, \n", omp_get_thread_num());
               mergeSort(a, q+1, r);
            }
    }
    merge(a, p, q, r);
    
}


void mergeNThreads(long* a, long p, long r, long thr) {
    long tmp = (r + 1) % thr;
    long *checkPos;
    checkPos = (long*)malloc(sizeof(long) * (thr + 1));
    checkPos[0] = 0;
    for (long i = 0; i < thr; i++) {
        if (tmp != 0) {
            checkPos[i + 1] = checkPos[i]+((r+1) / thr)+1;
            tmp--;
        }
        else
            checkPos[i + 1] = checkPos[i]+((r+1) / thr);

    }
    #pragma omp parallel 
    {
        long n = thr;
        long i = 0, j = 0, k = 1, ii = 0;

        #pragma omp for
            for (i = 0; i < n; i = i + 1) {
                //printf ("id = %d, \n", omp_get_thread_num());
                 mergeSort(a, checkPos[i], checkPos[i + 1] - 1);
             }
        #pragma omp barrier
    }
       if(thr>1)
            finalMergeNThreads(a, p, r, thr, checkPos);
}


void finalMergeNThreads(long* a, long p, long r, long thr, long* checkPos) {
    #pragma omp parallel
    {
        long n = thr;
        long j = 0, jj = 0, k = 1;
        long rounds = (long)log2(thr);
        while (k <= rounds) {
            jj = 0;
            #pragma omp for
                for (j = 0; j < n/k; j =j+2) {
                    jj = (jj+ j) * k;
                    merge(a, checkPos[jj * k], checkPos[(jj+1)*k]-1, checkPos[(jj + 2) * k]-1);
                }
            #pragma omp barrier
            k = k * 2;

        }
    }
} 


void merge(long* A, long p, long q, long r)
{

    long n1 = q - p + 1;
    long n2 = r - q;

    long* L = (long*)malloc(n1 * sizeof(long));
    long* M = (long*)malloc(n2 * sizeof(long));


    for (long i = 0; i < n1; i++)
        L[i] = A[p + i];    
    for (long j = 0; j < n2; j++)
        M[j] = A[q + 1 + j];


    long i, j, k;
    i = 0;
    j = 0;
    k = p;



    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = M[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = M[j];
        j++;
        k++;
    }
    free(L);
    free(M);
}