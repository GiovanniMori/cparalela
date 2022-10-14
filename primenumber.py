#######################################
#  Giovanni Vichiatti Mori 32054033   #
# Leonardo Sergio Caus Donda 32087535 #
#######################################
# Tempo de execução
# 8 - 0,284s
# 4 - 0,325s
# 2 - 0,272s
# 1 - 0,707s
#
# Versão Serial
# for number in range(1, 1000):
#     if number > 1:
#         for i in range(2, number):
#             if (number % i) == 0:
#                 break
#             else:
#                 print(number)

from mpi4py import MPI
import sys
comm = MPI.COMM_WORLD

size = comm.Get_size()
rank = comm.Get_rank()

lower_value = int(sys.argv[1])
num = int(sys.argv[2])
div = num//size
divr = num % size
cont = size-1

if lower_value < 1:
    lower_value = 1
diff = (num - lower_value)//size
diffr = (num - lower_value) % size
start = (rank*diff)+lower_value
end = (diff*(rank+1))+lower_value


if rank == size-1:
    arrayprimo = []
    for number in range(start, end+diffr):
        if number > 1:
            for i in range(2, number):
                if (number % i) == 0:
                    break
            else:
                arrayprimo.append(number)
    while cont != 0:
        numreceived = comm.recv()
        if (numreceived == -1):
            cont -= 1
        else:
            arrayprimo.append(numreceived)
    arrayprimo.sort()
    print(
        f"Números Primos:\n{arrayprimo}\nQuantidade de primos: {len(arrayprimo)}")
else:
    for number in range(start, end):
        if number > 1:
            for i in range(2, number):
                if (number % i) == 0:
                    break
            else:
                req = comm.send(number, dest=size-1, tag=11)
    finished = comm.send(-1, dest=size-1, tag=11)
