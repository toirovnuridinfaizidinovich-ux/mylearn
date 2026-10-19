#include <stdio.h>

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    arr[0] = 69;
    printf("%d\n", arr[0]);

    float numbers[3];
    numbers[0] = 1.2f;
    // numbers[1] = 2;
    numbers[2] = 3.5f;

    printf("%.2f\n", numbers[1]);

    char word[] = {'S', 'o', 'm', 'e'};

    char words[] = "Hello World!";

    words[1] = 'G';

    printf("%s\n", words);
    printf("%c\n", words[1]);

    int array[2][3] = {
        {1, 2, 3},
        {4, 6, 7}};

    array[0][2] = 69;

    printf("%d\n", array[0][2]);

    return 0;
}