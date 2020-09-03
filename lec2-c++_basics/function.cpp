#include <iostream>



//void adder (int a, int b, int &res)   //pass by reference
//void adder (int a, int b, int res)    //pass by value
void adder (int a, int b, int *res)      //pass by pointer
{
     *res = a + b;
}



int main (int args, char **argv)
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    int res = 0;
    //adder(a, b, res);
    adder(a, b, &res);
    
    std::cout<<a<<" + "<<b<<" = "<<res<<"\n";

    return 0;
}
