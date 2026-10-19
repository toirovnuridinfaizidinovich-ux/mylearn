#include "prototype6lesson.h"
#include <windows.h>

// void info(void); // Если не поставить прототип - выведет ошибку.

void sum(int a, int b);

void string(char arr[]);

float mult(float x, float y);

int main()
{

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    sum(33, 36);
    info();
    int a = 5, b = 7;

    string("Hello");

    char word[] = {'d', 'i', 'l', 'd', 'o', 'y'};

    string(word);

    sum(a, b);

    float result = mult(4.5f, 6.9f);
    printf("%.2f\n", result);

    return 0;
}

void sum(int a, int b)
{
    int res = a + b;
    printf("Результат: %d\n", res);
}

/*void info()
{
    printf("Hello\n");
    printf("Fucking\n");
    printf("Bich\n");
}*/

void string(char arr[])
{
    printf("%s\n", arr);
}

float mult(float x, float y)
{
    float res = x * y;
    printf("Result: %f\n", res);

    return res;
}
