#include <cstdlib>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    const int arrlen = 100;
    vector<int> arr(arrlen);

    srand(time(NULL));
    for(int i = 0; i < arrlen; ++i) {
        arr[i] = random() % (arrlen);
    }

    sort(arr.begin(), arr.end());
    vector<int>::iterator it = unique(arr.begin(), arr.end());
    arr.resize(it - arr.begin());

    printf("array size: %d\n", arr.size());

    int t1 = accumulate(arr.begin(), arr.end(), 0);

    int idx = random() % arr.size();
    int num = arr[idx]; // clear num
    printf("clear arr[%d]: %d\n", idx, num);
    arr[idx] = 0;

    printf("goto find it\n");

    int t2 = accumulate(arr.begin(), arr.end(), 0);
    printf("find it: %d, arr[%d]: %d\n", (t1 - t2), idx, num);

    return 0;
}
