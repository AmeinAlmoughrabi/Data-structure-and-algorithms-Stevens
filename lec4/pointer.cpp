#include <iostream>

int main (int args, char **argv)
{

    int course=360;
    
    int *ptr_to_course = &course;

    std::cout<<course<<"\n";
    std::cout<<&course<<" vs "<<ptr_to_course<<"\n";

    return 0;
}
