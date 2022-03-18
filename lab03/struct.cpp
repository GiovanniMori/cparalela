// Faça o exercício: http://www.inf.pucrs.br/~pinho/LaproI/ExerciciosValendoNota2008-1/Exercicio-Struct.html
// Siga a documentação de acordo com a linguagem de sua preferência, C ou C++.Observe que os links de documentação estão em C++
// mas isso não significa que o problema não possa ser resolvido em C.
// Leonardo S. C. Donda – 32087535
// Giovanni V. Mori – 32054033

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
    int age;
    float height;
} RG;

int main()
{
    FILE *data = fopen("input.txt", "r");
    if (data == NULL)
    {
        printf("Error 404 not found");
        return 0;
    }

    RG user[10];
    RG aux;
    for (int i = 0; i < 10; i++)
    {
        strcpy(user[i].name, "NULL");
        user[i].age = 0;
        user[i].height = 0.00;
    }

    int cont = 0;
    while (!feof(data))
    {
        fscanf(data, "%s", user[cont].name);
        fscanf(data, "%d", &user[cont].age);
        fscanf(data, "%f", &user[cont].height);
        cont++;
    }

    fclose(data);
    ///////////// Data Copy

    for (int i = 0; i < 10; i++)
    {
        for (int z = i + 1; z < 10; z++)
        {
            if (user[i].height > user[z].height)
            {
                aux = user[i];
                user[i] = user[z];
                user[z] = aux;
            }
        }
    }
    //////////// Data Ordered in AUX

    FILE *results = fopen("output.txt", "w");
    int cont2 = 0;

    if (results == NULL)
    {
        printf("Error file not created");
        return 0;
    }

    while (cont2!=10)
    {
        fprintf(results, "%s", user[cont2].name);
        fprintf(results, "%s", "\n");
        fprintf(results, "%d", user[cont2].age);
        fprintf(results, "%s", "\n");
        fprintf(results, "%.2f", user[cont2].height);
        fprintf(results, "%s", "\n");
        cont2++;
    }

    fclose(results);
    printf("New file output.txt has been created and it is ordered by height.\n");
    return 0;
}
