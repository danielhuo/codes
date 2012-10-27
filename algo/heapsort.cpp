#include <cstdio>
#include <cmath>
#include <algorithm>

int parent(int i)   { return (int)floor((i-1)/2); }
int left(int i)     { return (2*i + 1); }
int right(int i)    { return (2*i + 2); }

void max_heapify(int* arr, int len, int i)
{
    int lf = left(i);
    int rt = right(i);
    int largest = i;

    if(lf < len and arr[lf] > arr[i]) {
        largest = lf;
    } 
    if(rt < len and arr[rt] > arr[largest]) {
        largest = rt;
    }

    if(i != largest) {
        std::swap(arr[i], arr[largest]);
        max_heapify(arr, len, largest);
    }
}

void build_max_heap(int* arr, int len)
{
    int i = (int)floor((len-1)/2);
    for(; i > -1; --i) {
        max_heapify(arr, len, i);
    }
}

void heap_sort(int* arr, int len)
{
    build_max_heap(arr, len); 

    for(int i = len - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);  // move max value to tail
        --len;
        max_heapify(arr, len, 0);   // keep max heap
    }
}

int main()
{
    int arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    const int arrlen = (sizeof(arr)/sizeof(int));

    heap_sort(arr, arrlen);

    for(int i = 0; i < arrlen; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
