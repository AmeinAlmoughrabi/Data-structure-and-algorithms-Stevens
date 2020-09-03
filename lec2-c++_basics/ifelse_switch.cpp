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

void adder(int a, int b)
{
    std::cout<< a + b<<"\n";
    return;
}


int main (int args, char **argv)
{   
//    int i = 9;
//    
//    std::cout<<i<<"\n";
//    {
    
    long int dummy = 0;
    double ifelsetime = wtime();
    int i = 0;
    //for(int i = 0; i<(1<<30); i++)
    do
    {
       
        if (i%2==1)
            dummy++; 
        else 
            dummy --;
        i ++;
    } while (i < (1<<30));
    ifelsetime = wtime() - ifelsetime;
    
    

    double swtime = wtime();
    //int i = 0; 
    i = 0;
    while (i < (1<<30))
    //for(int i = 0; i<(1<<30); i++)
    {
        int status = (i%2 == 1);
        switch (status)
        {
            case 0:
                dummy--; break;
            
            case 1:
                dummy ++; break;
        }
        i ++;
    }
    swtime = wtime() - swtime;

    std::cout<<"ifelse: "<<ifelsetime<<" vs sw: "<<swtime<<"\n";
    //If you can use switch case, never use if-else.
    //
   
//    std::cout<<i<<"\n";

    return 0;
}
