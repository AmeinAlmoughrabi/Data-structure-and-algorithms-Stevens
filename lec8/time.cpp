#include <iostream>

#define TRIAL   (1<<4)
#define CAP     34445345

#ifndef __TIME_H__
#define __TIME_H__

#include <sys/time.h>
#include <stdlib.h>

double
wtime ()
{
  double time[2];
  struct timeval time1;
  gettimeofday (&time1, NULL);

  time[0] = time1.tv_sec;
  time[1] = time1.tv_usec;

  return time[0] + time[1] * 1.0e-6;
}

#endif

int
linear_search (int *arr, int n, int x)
{
  int i;
  for (i = 0; i < n; i++)
    if (arr[i] == x)
      return i;
  return -1;
}


void
binary_search (int *array, int size, int val)
{


  //For qsort, please refer to https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm for details
  //Link might expire.
  //Sept 22, 2020

  int begin = 0;
  int end = size;

  if (array[begin] >= val)
    //           std::cout<<val<<" is at index "<<begin<<"\n";
    return;

  if (array[end] <= val)
//            std::cout<<val<<" is at index "<<end<<"\n";
    return;

  int is_found = 0;
  while (begin < end - 1)
    {
      int middle = (begin + end) / 2;
      std::cout << begin << " " << end << "\n";
      if (val < array[middle])
	end = middle;
      else if (val > array[middle])
	begin = middle;
      else
	{
	  //             std::cout<<val<<" is at index "<<middle<<"\n";
	  is_found = 1;
	  break;
	}
    }
  //   if (is_found == 0) std::cout<<val<<" is not found\n";

  return;
}



int
cmpfunc (const void *a, const void *b)
{
  return (*(int *) a - *(int *) b);
}

int
main (int args, char **argv)
{
  std::cout << "/path/to/exe 1<<size\n";

  int size = (1 << atoi (argv[1]));

  int *arr = new int[size];
  for (int i = 0; i < size; i++)
    arr[i] = rand () % CAP;

  //O(N)
  double linear = wtime ();
  for (int i = 0; i < TRIAL; i++)
    linear_search (arr, size, rand () % CAP);
  linear = (wtime () - linear) / TRIAL;

  //O(NLogN)
  double sort = wtime ();
  for (int i = 0; i < TRIAL; i++)
    qsort (arr, size, sizeof (int), cmpfunc);
  sort = (wtime () - sort) / TRIAL;

  //O(LogN)
  double binary = wtime ();
  for (int i = 0; i < TRIAL; i++)
    binary_search (arr, size, rand () % CAP);
  binary = (wtime () - binary) / TRIAL;
  std::cout << size << "\n";

  std::cout << binary << "," << linear << "," << sort << "\n";

  //Your part to understand the time complexity of matrix matrix multiplication.
}
