#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

#define ADDKEY 123

// Leonardo S. C. Donda – 32087535
// Giovanni V. Mori – 32054033
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1. Crie um código-fonte que utilize fork() e shmget() entre 2 processos (pai e filho). Seu código deve garantir que:       //
// o processo pai e o processo filho compartilhem uma variável simples (por exemplo, inteiro - valor 1);                      //
// o processo pai imprime o valor inicial dessa variável; em seguida, cria o processo filho e espera-o;                       //
// o processo filho acessa esta variável, realiza uma operação, modificando o valor, em seguida, o processo filho termina;    //
// o processo pai realiza uma outra operação, modificando novamente o valor, e imprime novamente a variável;                  //
// Essa lógica de execução deve ser garantida no seu código-fonte em C;                                                       //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// return 1 = error

int main(void)
{
    int shmid;
    int size_shmid = 2048; //memory size
    char *path = "./"; // memory path
    if ((shmid = shmget(ftok(path, ADDKEY), size_shmid, IPC_CREAT | IPC_EXCL | SHM_R | SHM_W)) == -1){
        printf("SHMGET ERROR!\n"); return 1;
    }
    int *value = (int *)shmat(shmid, NULL, 0);    
    *value = 32054033;
    if ((int)*value != 32054033){
        printf("Error shared memory!\n"); return 1;
    } else {
        printf("Shmid: %d \nValue: %i\n", shmid, *value);
        pid_t parentpid = getpid();
        pid_t child = fork();
        if (child == -1){
            printf("Cannot start pid_t child!\n"); return 1;
        } else {
            if (child == 0){
                *value = *value + 2;
                printf("Fork Child: %ld -> parentpid: %ld\nValue(Value+2): %i\n", (long)getpid(), (long)parentpid, *value);
            } else{
                wait(NULL); *value = *value * 2;
                printf("Fork Parent: %ld -> parentpid: %ld \nValue(Value*2): %i\n\n", (long)getpid(), (long)parentpid, *value);
                if ((shmctl(shmid, IPC_RMID, NULL)) == -1){
                    printf("Erro cannot delete shared memory!\n\n"); return 1;
                } else {
                    printf("[SUCCESSFUL] Shared Memory in C\n\n");
                    return 0;
                }
            }
        }
    }
}