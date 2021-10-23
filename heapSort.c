#include "./heapSort.h"

void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }

void sort(int* a, int p, int n)
{
    int sh = 0, b = 0, i,root;
    while (1)
    {
        b = 0;
        for (i = p; i < n; ++i)
        {
            root = sh + i;
            if (right < n)
            {
                if (a[root] > a[left] || a[root] > a[right])
                {
                    if (a[left] < a[right])
                    {
                        swap(&a[root], &a[left]);
                        b = 1;
                    }
                    else if (a[right] < a[left])
                    {
                        swap(&a[root], &a[right]);
                        b = 1;
                    }
                }
            }
            else if (left < n)
            {
                if (a[root] > a[left])
                {
                    swap(&a[root], &a[left]);
                    b = 1;
                }
            }
        }
        if (!b) sh++;
        if (sh + 2 == n) break;
    }


}


void sortThreads(int* a, int n, int root, int num) {
    //num - index of root

    
}