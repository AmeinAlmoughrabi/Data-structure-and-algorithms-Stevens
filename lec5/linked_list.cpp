/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <assert.h>

struct data {
    int value;
    struct data * next;
};

void print_linked_list(struct data *header)
{
    struct data *tmp = header;
    
    int rank = 0;
    while(tmp != NULL)
    {
        std::cout<<"Record "<<rank<<" value = "<<tmp->value<<"\n";
        tmp = tmp->next;
        rank ++;
    }
    
    std::cout<<"\n\n\n";
}

void search_linked_list(struct data *header, int index, struct data* &prior)
{
    struct data *tmp = header;
    
    int rank = 0;
    while(tmp != NULL)
    {
        if(rank == index)
        {
            std::cout<<"The"<<rank<<"-th record value = "<<tmp->value<<"\n";
            break;
        }
        prior = tmp;
        tmp = tmp->next;
        rank ++;
    }
    
    std::cout<<"\n\n\n";
    
}

int main(int args, char **argv)
{
//    std::cout<<"/path/to/exe num_inserts num_deletes num_searches\n";
    
    //int num_inserts = atoi(argv[1]);
    //int num_deletes = atoi(argv[2]);
    //int num_searches= atoi(argv[3]);

    int num_inserts = 4;
    int num_deletes = 1;
    int num_searches= 1;
    
    struct data *header = new struct data;
    header->value = 360;
    header->next = NULL; 
    
    //insertion
    for(int i = 0; i < num_inserts; i ++)
    {
        struct data *instance = new struct data;
        instance->value = rand()%360;
        instance->next = NULL;
        
        //record the old next of the header;
        struct data *tmp = header->next;
        
        //change the header's next to this newly allocated instance
        header->next = instance;
        
        //point the next of this newly allocated instance to the prior next instance from header
        instance->next = tmp;
        
        std::cout<<"Value "<<instance->value<<" is inserted\n";
        print_linked_list(header);

    }
    
    
    //deletion
    for(int i = 0; i < num_deletes; i ++)
    {
        //int delete_index = 4;
        assert(i<(num_inserts+1));
        
        int delete_index = rand()%(num_inserts+1-i);
        std::cout<<"I will delete the "<<delete_index<<"-th records.\n";
        
        if(delete_index == 0)
        {
            header = header->next;            
            
        }
        else
        {
            struct data *prior;
        
            search_linked_list(header, delete_index, prior);
            //std::cout<<"I got prior->value = "<<prior->value<<"\n";
        
            prior->next = prior->next->next;
            
            
        }
        print_linked_list(header);
        
    }
    return 0;
}

