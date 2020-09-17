#include <iostream>
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

void linear(int *array, int size, int val){
    
    int is_found=0;
    double time=wtime();
    for(int i = 0; i < size; i ++)
    {
        if (array[i] == val)
        {
            std::cout<<val<<" is at index "<<i<<"\n";
            is_found = 1;
            break;
        }
    }
    time = wtime() - time;
    if (is_found == 0) std::cout<<val<<" is not found\n";

    std::cout<<"Linear search time is: "<<time<<" second(s).\n";
    return;
}

void binary(int *array, int size, int val){
    
    int begin = 0;
    int end = size;

    int is_found=0;
    double time=wtime();
    while(begin < end - 1)
    {
        int middle = (begin + end) / 2;
        
        if (val < array[middle])
            end = middle;
        else if (val > array[middle])
            begin = middle;
        else 
        {
            std::cout<<val<<" is at index "<<middle<<"\n";
            is_found = 1;
            break;
        }
    }

    time = wtime() - time;
    if (is_found == 0) std::cout<<val<<" is not found\n";

    std::cout<<"Binary search time is: "<<time<<" second(s).\n";
    return;
}


int main(int args, char **argv)
{
    std::cout<<"/path/to/exe array_size val_of_interest\n";

    assert(args >= 3);

    int array_size = atoi(argv[1]);
    int val = atoi(argv[2]);

    int *array = new int[array_size];

    for(int i = 0; i < array_size; i ++)
        array[i] = i;

    linear(array, array_size, val);
    binary(array, array_size, val);

    delete[] array;

    return 1;
}

