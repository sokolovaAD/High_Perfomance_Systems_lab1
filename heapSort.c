#include "heapSort.h"


void downHeap(long* a, long k, long n, long size, long info) {
    long new_elem;
    long child;
    new_elem = a[k];

        child = 2 * (k - size) + size+1;
        if (child + 1 < info) {
            if (child < n && a[child] < a[child + 1])
                child++;
        }
        
        if (new_elem < a[child]) {
            a[k] = a[child];
            k = child;
        }
    a[k] = new_elem;
}



void heapSort2Threads(long* a, long size) {
    long i;
    long temp1, temp2;
    long size1, size2, info1, info2;

    size = size + 1;
    while (size > 2) {
        size = size - 1;
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                //printf("proc = %d\n", omp_get_thread_num());
                size2 = (long)((double)size - ceil((double)size / 2));
                info2 = size;
                for (i = (size + size2) / 2 - 1; i >= size / 2; i--)
                    downHeap(a, i, size - 1, size2, info2);
                temp2 = a[size / 2];
            }
            #pragma omp section
            {
                //printf("proc = %d\n", omp_get_thread_num());
                size1 = 0;
                info1 = (size + size2) / 2 - 1;
                for (i = size / 4 - 1; i >= 0; i--)
                    downHeap(a, i, size / 2 - 1, size1, info1);
                temp1 = a[0];
            }
        }
        
        if (temp1 >= temp2) {
            a[0] = a[size - 1];
            a[size - 1] = temp1;

        }
        else {
            a[size / 2] = a[size - 1];
            a[size - 1] = temp2;
        }
    }
}


void heapSort(long* a, long size) {
    long i;
    long temp, info=size;
    long size1=0;

    size++;
    while (size > 1) {
        size --;
        for(i=size/2-1; i >= 0; i--) {
            downHeap(a, i, size-1, size1, info); 
        }
        temp=a[size-1]; 
        a[size-1]=a[0]; 
        a[0]=temp;


    }
}


void heapSortNThreads(long* a, long size, int thr) {
    long sizes[thr];
    long info = size;
    int r = size - 1;
    long lastchild, firstparent;
    long temps[thr];
    long max = 0, maxPos = 0;

    long tmp = (r + 1) % thr;
    long* checkPos;
    checkPos = (long*)malloc(sizeof(long) * (thr + 1));
    checkPos[0] = 0;
    

    size++;
    int n = thr;
    while (size > thr) {
        size--;

        //запоминание позиций в массиве для разделения по потокам
        int r = size - 1;
        long tmp = (r + 1) % thr;
        for (long long i = 0; i < thr; i++) {
            if (tmp != 0) {
                checkPos[i + 1] = checkPos[i] + ((r + 1) / thr) + 1;
                tmp--;
            }
            else
                checkPos[i + 1] = checkPos[i] + ((r + 1) / thr);
        }

        //разделение по потокам
        #pragma omp parallel
        {
            #pragma omp for 
            
                for (int i = 0; i < n; i++) 
                {   
                    //printf("proc = %d\n", omp_get_thread_num());
                    sizes[i] = checkPos[i];
                    lastchild = checkPos[i + 1] - 1 - checkPos[i];
                    firstparent = (int)ceil((double)lastchild / 2) + checkPos[i]-1;
                    for (int j = firstparent; j >= checkPos[i]; j--)
                        downHeap(a, j, checkPos[i+1] - 1, sizes[i], info);
                    temps[i] = a[checkPos[i]];
                }
            
        }

        //нахождение наибольшего элемента от каждого потока
        int max = 0, maxPos = 0;
        for (int i = 0; i < thr; i++) {
            if (temps[i] > max) {
                max = temps[i];
                maxPos = checkPos[i];
            }
        }
        a[maxPos] = a[size - 1];
        a[size - 1] = max;

    }

    //last 4 numbers
    int number = 4, f;
    max = 0;
    while (number != 1) {
        max = 0;
        for (int i = 0; i < number; i++) {
            if (a[i] > max) {
                max = a[i];
                maxPos = i;
            }
        }
        f = a[number - 1];
        a[number-1] = max;
        a[maxPos] = f;
        number--;
    }

}
