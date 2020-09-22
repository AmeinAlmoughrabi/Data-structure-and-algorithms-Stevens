#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include "../util/wtime.h"

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void linear(int *array, int size, int *tries, int num_of_searches){
    
    double time=wtime();
    for(int j = 0; j < num_of_searches; j ++)
    {
        int is_found=0;
        int val = tries[j];
        for(int i = 0; i < size; i ++)
        {
            if (array[i] == val)
            {
                //std::cout<<val<<" is at index "<<i<<"\n";
                is_found = 1;
                break;
            }
        }
    }

    time = wtime() - time;
    //if (is_found == 0) std::cout<<val<<" is not found\n";

    std::cout<<"Linear search time is: "<<time<<" second(s).\n";
    return;
}

void binary(int *array, int size, int *tries, int num_of_searches){
    
    double time=wtime();
   
   //For qsort, please refer to https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm for details
   //Link might expire.
   //Sept 22, 2020
    qsort(array, size, sizeof(int), cmpfunc);
    
    for(int j = 0; j < num_of_searches; j ++)
    {
        int begin = 0;
        int end = size;
        int val = tries[j];

        if (array[begin] == val) 
            //std::cout<<val<<" is at index "<<begin<<"\n";
            continue;

        if (array[end] == val) 
            //std::cout<<val<<" is at index "<<end<<"\n";
            continue;

        int is_found=0;
        while(begin < end - 1)
        {
            int middle = (begin + end) / 2;

            if (val < array[middle])
                end = middle;
            else if (val > array[middle])
                begin = middle;
            else 
            {
                //std::cout<<val<<" is at index "<<middle<<"\n";
                is_found = 1;
                break;
            }
        }
    }
    time = wtime() - time;
    //if (is_found == 0) std::cout<<val<<" is not found\n";

    std::cout<<"Binary search time is: "<<time<<" second(s).\n";
    return;
}


int main(int args, char **argv)
{
    std::cout<<"/path/to/exe array_size num_of_searches\n";

    assert(args >= 3);

    int array_size = atoi(argv[1]);
    int num_of_searches = atoi(argv[2]);

    int *array = new int[array_size];
    int *tries = new int[num_of_searches];

    for(int i = 0; i < array_size; i ++)
        array[i] = rand()%2020360;
    
    for(int i = 0; i < num_of_searches; i ++)
        tries[i] = rand()%2020360;

    int *sorted_array = new int[array_size];
    
    memcpy(sorted_array, array, sizeof(int)*array_size);
    

    linear(array, array_size, tries, num_of_searches);
    binary(sorted_array, array_size, tries, num_of_searches);

    delete[] array;
    delete[] tries;

    return 1;
}

