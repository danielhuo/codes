#include <cstdio>

int bsearch(int key, int* arr, int bg, int ed)
{
    if(bg > ed) return -1;

    int mid = (bg + ed) / 2;
    if(key == arr[mid]) return mid;

    if(key > arr[mid]) return bsearch(key, arr, mid+1, ed);
    else return bsearch(key, arr, bg, mid-1);
}

int bsearch2(int key, int* arr, int bg, int ed)
{
    int mid;
    while(bg <= ed) {
        mid = (bg + ed)/2;
        if(key == arr[mid]) return mid;
        if(key > arr[mid]) {
            bg = mid+1;
        } else {
            ed = mid-1;
        }
    }
    return -1;
}

int main()
{
    const int len = 10000;
    int arr[len];
    for(int i = 0; i < len; ++i) {
        arr[i] = i;
    }

    for(int i = 0; i < len; ++i) {
        if(bsearch(i, arr, 0, len) != i) {
            printf("bsearch failed: %d\n", i);
        }
    }

    for(int i = 0; i < len; ++i) {
        if(bsearch2(i, arr, 0, len) != i) {
            printf("bsearch2 failed: %d\n", i);
            break;
        }
    }

    return 0;
}
