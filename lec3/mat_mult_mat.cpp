#include <iostream>
#include <assert.h>
#include <stdlib.h>


#ifndef __TIME_H__
#define __TIME_H__

#include <sys/time.h>
#include <stdlib.h>

double wtime()
{
	double time[2];
	struct timeval time1;
	gettimeofday(&time1, NULL);

	time[0]=time1.tv_sec;
	time[1]=time1.tv_usec;

	return time[0]+time[1]*1.0e-6;
}

#endif

int mat_mult_mat (int **A, int **B, int **res, int dim)
{

}


int main(int args, char **argv)
{
    std::cout<<"Input: /path/to/exe dim\n";

    assert(args == 2);

    int dim = atoi(argv[1]);

	int **A;
	int **B;
	int **res;
    //Alloc the two dimensional arrays A, B and res;
    //
    //
    //

    //Random initialization of A and B.
    //
    //

    double time = wtime();
    mat_mult_mat (A, B, res, dim);
    
    time = wtime () - time;

    std::cout<<"It takes " << time <<" seconds to finish the "<<dim<<" by "<<dim<< "matrix multiplication\n";

    return 1;

}
