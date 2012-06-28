#include <stdio.h>
#include <string.h>

#define PRINT(fmt, arg...) \
                   printf("%s[%d]: "#fmt"\n", __func__, __LINE__, ##arg)

#define BUFLEN 1024
#define BL_NULL do{}while(0)
#define BL_PRINTF(fmt,args...)\
    do{\
        printf(#fmt "\n", ##args);\
    } while(0)

int main()
{
    BL_NULL;

    PRINT("hello %s, %s, %s", "berlin", "bl2", "bl3");
    BL_PRINTF("hello %s, %s, %s", "berlin", "bl2", "bl3");

    return 0;
}
