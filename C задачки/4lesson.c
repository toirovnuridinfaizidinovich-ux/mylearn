#include <stdio.h>
#include <windows.h>

/*
&& - 'и'
|| - 'или'
! - меняет булево значение
    */

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int x = 4;

    if (x > 5 || x == 4)

    {
        if (x == 2)
        {
            printf("BDSM");
        }

        else if (x == 5)
        {
            printf("I'm really gey?");
        }
        else
        {
            printf("I love PornHub");
        }
    }
    printf("\n");
    int day = 3;

    switch (day)
    {
    case 1:
        printf("Понедельник\n");
        break;
    case 2:
        printf("Вторник\n");
        break;
    case 3:
        printf("Среда\n");
        break;
    default:
        printf("Другой день\n");
        break;
    }

    int dick_size = 18;

    const char *dick_status =
        (dick_size >= 18)
            ? "Big Dick"
        : (14 <= dick_size <= 17)
            ? "Medium Dick"
            : "Small Dick";
    printf(dick_status);
    return 0;
}