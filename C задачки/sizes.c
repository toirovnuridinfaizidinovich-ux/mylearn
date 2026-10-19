#include <stdio.h>
#include <windows.h>

int main(void)
{
    SetConsoleOutputCP(65001);
    printf("char:       %zu байт\n", sizeof(char));
    printf("short:      %zu байт\n", sizeof(short));
    printf("int:        %zu байт\n", sizeof(int));
    printf("long:       %zu байт\n", sizeof(long));
    printf("long long:  %zu байт\n", sizeof(long long));
    printf("float:      %zu байт\n", sizeof(float));
    printf("double:     %zu байт\n", sizeof(double));

    return 0;
}