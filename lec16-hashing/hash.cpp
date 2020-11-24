#include <iostream>

#define INIT (1<<30)
#define YES 1
#define NO 0


int hash_function(int element, int size){
    return (element%size);
}
int search_element(int *hash_table, int size, int element, int &index){
    
    int is_found = NO;
    index = hash_function(element, size);
   // std::cout<<hash_table[index]<<"--------"<<index<<"\n";
    if(hash_table[index] == element){
        is_found = YES;
        return is_found;
    }
    
    int trial = 1;

    while(hash_table[index] != element){
        
        index ++;
        index = index%size;

        if(hash_table[index] == element){
            is_found = YES;
            break;
        }

        trial ++;

        if(trial == size) break;

    }

    return is_found;
}



int insert(int *hash_table, int &count, int size, int element){
   
    std::cout<<"Insert "<<element<<" to hash table\n";
    assert(count <= size);
    count ++;

    int index = hash_function(element, size);

    int tmp_index = index;

    //no collision, element does not exist
    if(hash_table[index] == INIT){
        hash_table[index] = element;
        std::cout<<element<<" inserted at "<<index<<"\n";
        return 0;
    }

    //element already exists
    if(hash_table[index] == element)  return -1;
    
    //the desired location is taken
    //but the element still exists
    if (search_element(hash_table, size, element, tmp_index) == YES)
        return -1;
    
    //the desired location is taken
    //the element does not exist in hash table
    while(hash_table[index] != INIT)
        index ++;

    hash_table[index] = element;
    
    std::cout<<element<<" inserted at "<<index<<"\n";
    return 0;
}


int delete_element(int *hash_table, int &count, int size, int element){
    
    int index = -1;

    if(search_element(hash_table, size, element, index) == YES){
        std::cout<<element<<" found\n";
        hash_table[index] = INIT;
        return 0;
    }

    std::cout<<element<<" not found\n";
    return 1;
}


int construct_hash_table(int *&hash_table, int size){

    hash_table = new int[size];

    for (int i = 0; i < size; i ++)
        hash_table[i] = INIT;

    return 0;
}



int main (int args, char **argv)
{
    std::cout<<"This is a hash table with linear probing collision handling mechanism\n";

    std::cout<<"/path/to/exe size_of_hash_table num_of_elements_to_insert\n";

    assert(args>=3);

    int size = atoi(argv[1]);

    int num = atoi(argv[2]);

    int *hash_table;
    int count = 0; 

    assert(0==construct_hash_table (hash_table, size));

    for(int i = 0; i < num; i ++){
        int element = rand()%12;
        insert(hash_table, count, size, element);
    }
    

    int index = -1;

    search_element(hash_table, size, 10, index);
    insert(hash_table, count, size, 10);
    delete_element(hash_table, count, size, 10);

    return 0;
}
