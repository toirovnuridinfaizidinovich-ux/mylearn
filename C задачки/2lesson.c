#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int num_first = 4500; // Диапозон от -2млн до 2млн
    num_first = 4;

    num_first--; // Вычитает единицу

    int x = 2, y, res;
    y = 5;
    x *= num_first;
    res = y * x;
    printf("Пожилая сила", "Variable: %d\n", x);
    printf("\nVariable: %d * %d = %d", y, x, res);

    /*
    short s = 600; //Диапозон -32768 до - 32768 / в 2 раза меньше памяти

    unsigned short a = 5; // от 0 до 65 тысяч

    unsigned int num = 9; // От 0 до 4млн

    long a2 = 5; // в 2 раза больше обычного int

    long long a4 = 8; // еще больше

    float a3 = 4.5f;

    double a5 = 5.5; //Больше символов после запятой / long double

    char ch = '7'; // Строковый тип данных

    bool isHasCar = true;
*/

    //==
    float d = 5.5f, f = 6.5f, rest;
    rest = d * f;
    printf("\nResult: %.2f\n", rest);

    const char *text = "char";
    printf("%s\n", text);

    float x1, y1;
    scanf("%f", &x1);

    return 0;
}