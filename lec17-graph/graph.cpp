#include <iostream>

int graph_matrix(int ** &graph, int &vertex_count){
    

    //We can in fact randomly initiate a graph.
    //In this code, we will use the example graph from our lecture
    //
    //
    
    vertex_count = 4;

    graph = new int *[vertex_count];

    for(int i = 0; i < vertex_count; i ++)
        graph[i] = new int[vertex_count];

    for(int i = 0; i < vertex_count; i ++)
        for(int j = 0; j < vertex_count; j ++)
            graph[i][j] = 0;

    
    
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[3][1] = 1;


}

int bfs_matrix(int **graph, int vertex_count, int root){

    int *current_queue = new int[vertex_count];
    int *next_queue = new int[vertex_count];

    int current_queue_count = 0;
    int next_queue_count = 0;

    int *status = new int [vertex_count];
    int *parent = new int [vertex_count];


    for(int i = 0; i < vertex_count; i ++){
        status [i] = -1;
        parent[i] =  -1;
        
    }
    
    int level = 0;
    current_queue[current_queue_count ++] = root;
    status[root] = level;

    level ++;

    while(current_queue_count != 0)
    {
       for(int i = 0; i < current_queue_count; i ++)
       {
            int frontier = current_queue[i];

            for(int j = 0; j < vertex_count; j ++)
            {
                if(graph[frontier][j] == 1)
                {
                    int neighbor = j;
                    if(status [neighbor] == -1)
                    {
                        status[neighbor] = level;
                        next_queue[next_queue_count++] = neighbor;
                        parent[neighbor] = frontier;
                    }
                }
            }
       }
    
       std::cout<<level<<" visited "<<next_queue_count<<" vertices\n";
       level ++;
       int *tmp = current_queue;
       current_queue = next_queue;
       next_queue = tmp;

       current_queue_count = next_queue_count;
       next_queue_count = 0;

    }

    //Check the result
    for(int i = 0; i < level; i ++)
    {
        std::cout<<"Level "<<i<<": ";
        for(int j = 0; j < vertex_count; j ++)
            if(status[j] == i)
            {
                std::cout<<j<<" (parent: "<<parent[j]<<" ) ";
            }
        
        std::cout<<"\n";
    }

}


int main (int args, char **argv)
{
    int **graph;
    int vertex_count;

    int root = 2;

    graph_matrix(graph, vertex_count);

    bfs_matrix(graph, vertex_count, root);
    
    return 0;
}
