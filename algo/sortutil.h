#ifndef _SORT_UTILITY
#define _SORT_UTILITY

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void print_array(int* arr, int bg, int ed)
{
    printf("arr: ");
    for(int i = bg; i < ed; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

bool check_array(int* arr, int bg, int ed) 
{
    while(bg < ed - 1) {
        if(arr[bg] > arr[bg+1]) {
            printf("check array failed: arr[i] > arr[i+1] (i:%d, %d, %d) \n", bg, arr[bg], arr[bg+1]);
            return false;
        }
        ++bg;
    }
    //printf("check done\n");
    return true;
}

int* make_array(int arrlen)
{
    int* arr = new int[arrlen];

    srand(time(NULL));
    for(int i = 0; i < arrlen; ++i) {
        arr[i] = random() % (arrlen * 10);
    }

    return arr;
}

#endif
