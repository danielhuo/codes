#include "sortutil.h"

void bubblesort(int* arr, int bg, int ed)
{
    int counter = ed - bg - 1;
    bool done = false;
    int end = ed;
    while(counter-- and !done) {
        done = true;
        for(int j = bg; j < ed - 1; ++j) {
            if(arr[j] > arr[j+1]) {
                done = false;
                std::swap(arr[j], arr[j+1]);
            }
        }
        --ed;
        print_array(arr, bg, end);
    }
}

int main()
{
    const int arrlen = 10;
    int* arr = make_array(arrlen);
    //int arr[arrlen] = {51, 64, 96, 37, 96, 59, 45, 48, 0, 99};

    bubblesort(arr, 0, arrlen);

    check_array(arr, 0, arrlen);

    return 0;
}
