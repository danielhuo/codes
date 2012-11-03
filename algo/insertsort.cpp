#include "sortutil.h"

void insertsort(int* arr, int bg, int ed)
{
    int tmp, j;
    for(int i = bg + 1; i < ed; ++i) {
        tmp = arr[i];
        for(j = i - 1; j > -1 and arr[j] > tmp; --j) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = tmp;
    }
}

int main()
{
    int arrlen = 10;
    int* arr = make_array(arrlen);

    insertsort(arr, 0, arrlen);

    check_array(arr, 0, arrlen);

    return 0;
}
