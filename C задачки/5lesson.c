#include <stdio.h>

int main()
{
    /*
        for (float i = 100; i > 10; i /= 2)
        {
            printf("%f\n", i);
        }
    */

    /*int isHasCar = true, x = 1;

    while (isHasCar)
    {
        scanf("%d", &x);
        if (x == 1)
            isHasCar = false;
    }*/
    /*
        int i = 0;

        while (i < 10)
        {
            printf("%d\n", i);
            i++;
        } */
    /*
        bool isHasCar = false;
        do
        {
            printf("Yes\n");
        } while (isHasCar);
    */

    /*for (int x = 0; x < 5; x++)
    {
        if(x==3)
            break;
        if (x % 2 == 0)
            continue;
        printf("%d\n", x);
    }*/

    int arr[] = {5, 67, 0, -2, 6};
    for (int i = 0; i < 5; i++)
        printf("%d\n", arr[i]);
    printf("\n");
    int min = arr[0], max = arr[0];
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    printf("Minimum: %d\n", min);

    return 0;
}