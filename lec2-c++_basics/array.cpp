#include <iostream>

int main (int args, char **argv)
{
    int arr[5];//stack of the computer


    //C like array allocation
    int *arr_m = (int *) malloc(sizeof (int) * 5);

    //C++ like array allocation, stays in the heap
    int *arr_new = new int[5];


    int arr2[5][5];

    //C like 
    //
    int **arr_2d_m = (int **) malloc(sizeof (int*) * 5);
    for(int i = 0; i < 5; i ++)
        arr_2d_m[i] = (int *) malloc(sizeof (int) * 5);


    //C++ like 
    //
    int **arr_2d_new = new int*[5];
    for(int i = 0; i < 5; i ++)
        arr_2d_new[i] = new int[5];

     return 0;
    
}
