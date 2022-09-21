from mpi4py import MPI
import math
comm = MPI.COMM_WORLD
rank = comm.Get_rank()

taylor = 0

if rank == 0:
    i = 1
    while i<=5:
        div = 1/i
        i+=1
        taylor += div

    req = comm.send(taylor, dest=1, tag=11)
if rank == 1:
    i = 6
    while i<=10:
        div = 1/i
        i+=1
        taylor += div
        
    rank0taylor = comm.recv(source=0,tag=11)
    taylor+= rank0taylor
    print("Valor final da Serie de Taylor(10): ", taylor)
