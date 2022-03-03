#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
// Duvida: primeiramente achei que seria facil dividir em threads, pegando uma parte da fatorial e dividindo em varias threads
// e no final de cada thread bastava multiplicar pelas outras
// depois de 12! começa a dar erro, mas acho que a "ideia" em si entendi

int main()
{
    pid_t pid;
    int i, num, j;
    int i2;
    int cont, fatorial;
    printf("Enter the number: ");
    scanf("%d", &num);
    if (num == 1)
    {
        printf("The factorial of %d is %d\n", num, 1);
        return 0;
    }
    if (num == 0)
    {
        printf("The factorial of %d is %d\n", num, 1);
        return 0;
    }
    j = num;
    int contador1for = 0;
    cont = 1;
    pid = fork();
    if (pid == 0)
    {
        for (i = 1; j != num / 2; j = j - 1)
        {
            i = i * j;
            contador1for++;
        }
    }
    waitpid(pid, NULL, 0);
    i2 = j * cont;
    for (cont = 1; cont != num / 2; cont = cont + 1)
    {
        i2 = i2 * cont;
    }
    fatorial = i2 * i;
    if (pid == 0)
    {
        printf("The factorial of %d is %d\n", num, fatorial);
    }
}