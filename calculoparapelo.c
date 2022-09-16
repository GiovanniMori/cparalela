// Giovanni Vichiatti Mori 32054033
// Leonardo Sergio Caus Donda 32087535
#include <omp.h>
#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{

    double serie;
    long long int T = 2222222222;
    double S = 0;
    int rank, size, nlen;
    char name[MPI_MAX_PROCESSOR_NAME];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); /* get rank */
    MPI_Comm_size(MPI_COMM_WORLD, &size); /* get size */
    MPI_Get_processor_name(name, &nlen);  /* get name */
    if (rank == 0)
    {
        printf("I am process %d out of %d on %s\n ",
               rank, size, name);

        for (long long int i = 1; i <= T; i++)
        {
            S += (1.0 / i);
        }
        serie += S;
    }
    else
    {
        printf("Eu sou o outro processo %d de %d em %s\n ",
               rank, size, name);
    }
    printf("Serie de Taylor -> (%lld): %f\n", T, serie);
    MPI_Finalize();
}
