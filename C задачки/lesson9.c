#include <stdio.h>

int main()
{

    char line[255];

    FILE *file = fopen("test.txt", "r"); // r - чтение, w - запись, a - добавить без удаления

    fgets(line, 255, file); // Позволяет в массив закинуть определенное количество символов которое в последствии будет считываться

    printf("%s", line);

    fgets(line, 255, file); // Позволяет в массив закинуть определенное количество символов которое в последствии будет считываться

    printf("%s", line);

    fgets(line, 255, file); // Позволяет в массив закинуть определенное количество символов которое в последствии будет считываться

    printf("%s", line);

    fprintf(file, "Hello, I'm gey");

    fprintf(file, "\nBut, I love big ass white woman");

    fclose(file);

    return 0;
}