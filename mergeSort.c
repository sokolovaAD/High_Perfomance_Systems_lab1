#include "./mergeSort.h"

void mergeSort(int* a, int p, int r) {
    if (p >= r)
        return;
    int q = (p + r) / 2;
    mergeSort(a, p, q);
    mergeSort(a, q + 1, r);
    merge(a, p, q, r);
    

}


void merge2Threads(int* a, int p, int r) {
    int q = (p + r) / 2;
    #pragma omp parallel sections
    {
            #pragma omp section
            {
                mergeSort(a, p, q);
            }
            #pragma omp section 
            {
               mergeSort(a, q+1, r);
            }
    }
    merge(a, p, q, r);
    
}


void mergeNThreads(int* a, int p, int r, int thr) {
    int tmp = (r + 1) % thr;
    int *checkPos;
    checkPos = (int*)malloc(sizeof(int) * (thr + 1));
    checkPos[0] = 0;
    for (int i = 0; i < thr; i++) {
        if (tmp != 0) {
            checkPos[i + 1] = checkPos[i]+((r+1) / thr)+1;
            tmp--;
        }
        else
            checkPos[i + 1] = checkPos[i]+((r+1) / thr);

    }
    #pragma omp parallel 
    {
        int n = thr, i = 0, j = 0, k = 1, ii = 0;

        #pragma omp for
            for (i = 0; i < n; i = i + 1) {
                 mergeSort(a, checkPos[i], checkPos[i + 1] - 1);
             }
        #pragma omp barrier
    }
       if(thr>1)
            finalMergeNThreads(a, p, r, thr, checkPos);
}


void finalMergeNThreads(int* a, int p, int r, int thr, int* checkPos) {
    #pragma omp parallel
    {
        int n = thr, j = 0, jj = 0, k = 1;
        int rounds = (int)log2(thr);
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


void merge(int* A, int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* M = (int*)malloc(n2 * sizeof(int));


    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];    
    for (int j = 0; j < n2; j++)
        M[j] = A[q + 1 + j];


    int i, j, k;
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