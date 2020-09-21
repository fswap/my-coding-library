#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>

void getn(int argc,char* argv[],int *n)
{
    int opt;
    char* endptr;
    errno=0;
    while((opt=getopt(argc,argv,"n:"))!=-1)
    {
        switch(opt)
        {
            case 'n':
                *n=strtol(optarg, &endptr, 10);
                if (*endptr!='\0')
                {
                    fprintf(stderr, "Invalid argument for N\n");
                    MPI_Abort(MPI_COMM_WORLD, MPI_ERR_ARG);
                }
                else if(errno)
                {
                    fprintf(stderr, "Overflow or Underflow for N\n");
                    MPI_Abort(MPI_COMM_WORLD, MPI_ERR_ARG);
                }
                else if (*n<1)
                {
                    fprintf(stderr, "N must be >= 1\n");
                    MPI_Abort(MPI_COMM_WORLD, MPI_ERR_ARG);
                }
                break;
            case '?': MPI_Abort(MPI_COMM_WORLD, MPI_ERR_ARG);
            case ':': MPI_Abort(MPI_COMM_WORLD, MPI_ERR_ARG);
        }
    }
}
int main(int argc, char *argv[]) 
{
    int size,rank,i,n=7,d=12;
    double lsum=0.0,gsum=0.0;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    getn(argc, argv, &n);

    for(i=rank+1;i<=n;i+=size)
	    lsum+=(1.0/(1.0*i));

    MPI_Reduce(&lsum, &gsum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Finalize();

    if (rank == 0)
        printf("S7 = %.*f\n",d,gsum);
    return 0;
}