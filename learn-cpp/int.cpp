#include <iostream>
#include <cmath>
#include <float.h>

void test1()
{
    float f = 0.1f;
    float sum = 0;

    for(int i = 0; i < 10; ++i) {
        sum += f;
    }
    float product = f * 10;
    printf("sum = %.15f, mul = %.15f, mul2 = %.15f\n", sum, product, f * 10);

}

int main()
{
    printf("%d\n", int((0.1+0.8)*10));  // 9
    printf("%d\n", int((0.1+0.7)*10));  // 7

    test1();

    float x = 1.1;
    if(x != 1.1) {
        printf("woo! 1.1 != 1.1\n");
    }

    float y = 1.1f;
    if(y == 1.1f) {
        printf("woo! 1.1f == 1.1f\n");
    }

    double a = 0.2;

    return 0;
}

