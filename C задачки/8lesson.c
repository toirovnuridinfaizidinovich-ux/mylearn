#include "prototype8lesson.h"

int main()
{
    int num = 0;

    // int *pNum = &num; // p - pointer - указатель

    // printf("%p\n", pNum);

    // printf("%d\n", num);

    // printf("%d\n", *pNum);

    int *pNum = &num;

    printf("%p - %p\n", pNum, &num);

    printf("%d\n", num);
    *pNum = 10;
    printf("%d\n", *pNum);

    struct Abstract rect;
    rect.width = 6;
    rect.height = 3;

    calc(rect);

    return 0;
}

/*struct Abstract
{
    int width, height;
};*/

int calc(struct Abstract object)
{
    int res = object.width * object.height;
    printf("Результат: %d\n", res);

    return res;
}