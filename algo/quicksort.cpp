#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <algorithm>

#include "sortutil.h"

void qsort1(int* arr, int bg, int ed)
{
    if(bg >= ed) return ;

    int m = bg;
    for(int i = bg + 1; i < ed; ++i) {
        if(arr[i] < arr[bg]) {
            std::swap(arr[++m], arr[i]);
        }
    }

    std::swap(arr[bg], arr[m]);

    qsort1(arr, bg, m);
    qsort1(arr, m+1, ed);
}

int main()
{
    
    qsort1(arr, 0, arrlen);   

    check_arr(arr, 0, arrlen);

    return 0;
}
