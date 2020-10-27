#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>

struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 

// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%d \n", root->key); 
		inorder(root->right); 
	} 
}


void bfs_order(struct node *root, int vertex_count)
{
    int current_count = 0;
    int next_count = 0;
    
    struct node **current_frontier_queue = new struct node* [vertex_count];
    struct node **next_frontier_queue = new struct node* [vertex_count];

    if (root != NULL){

        current_frontier_queue [current_count++] = root;
        std::cout<<root->key<<"\n";
    }

    while(current_count != 0){
        
        for(int i = 0; i < current_count; i ++)
        {
            if(current_frontier_queue[i]->left != NULL)
            {
                next_frontier_queue[next_count++]= current_frontier_queue[i]->left;
                std::cout<<current_frontier_queue[i]->left->key<<" ";
            }
            else std::cout<<"-1 ";

            if(current_frontier_queue[i]->right != NULL)
            {
                next_frontier_queue[next_count++]= current_frontier_queue[i]->right;
                std::cout<<current_frontier_queue[i]->right->key<<" ";
            }
            else std::cout<<"-1 ";
        }
        std::cout<<"\n";

        struct node **tmp = next_frontier_queue;
        next_frontier_queue = current_frontier_queue;
        current_frontier_queue = tmp;

        current_count = next_count;
        next_count = 0;
    }

    delete[] current_frontier_queue;
    delete[] next_frontier_queue;
}


void search(struct node *node, int value, struct node* &parent, struct node* &current_node, int &num_child){
	
    if (node == NULL){
        parent = NULL;
        current_node = NULL;
        return;
    } 
    
    if (node -> key == value){
        current_node = node;
        num_child = (node->left != NULL) + (node->right != NULL);
        return;
    }
    
    parent = node;

	/* Otherwise, recur down the tree */
	if (value < node->key) 
		search(node->left, value, parent, current_node, num_child); 
	else if (value > node->key) 
		search(node->right, value, parent, current_node, num_child); 


}


void delete_node(struct node *root, int value){
    
    struct node *parent = NULL;
    struct node *current_node = NULL;
    int num_child = -1;

    search(root, value, parent, current_node, num_child);
    
    //std::cout<<current_node<<"\n";

    if (!current_node){
        
        std::cout<<value<<" not exist!\n";
        return;
    }
    
    std::cout<<value<<" has "<<num_child<<" child vertices\n"; 

    switch (num_child){

        case 0:
            if (parent->left == current_node) parent->left = NULL;
            else parent->right = NULL;

            break;

        case 1:
            if(parent->left == current_node)
                if (current_node->left != NULL) parent->left = current_node->left;
                else parent->left = current_node->right; 
            else
                if (current_node->left != NULL) parent->right = current_node->left;
                else parent->right = current_node->right; 

            break;

        case 2:
            std::cout<<"Student, please finish this one\n";            
            break;
        default:
            std::cout<<"Not valid\n";
            return;
    }
    
}


/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 

	/* return the (unchanged) node pointer */
	return node; 
} 

// Driver Program to test above functions 
int main(int args, char **argv) 
{ 
	/* Let us create following BST 
           50 
		 /	  \ 
		30	   70 
		 \     / \ 
         40   60 80 */
	
	struct node *root = NULL; 
	root = insert(root, 50); 
	insert(root, 30); 
//	insert(root, 20); 
	insert(root, 40); 
	insert(root, 70); 
	insert(root, 60); 
	insert(root, 80); 
    

    int delete_val = 30;
    if (args > 1) delete_val = atoi(argv[1]);
    
    bfs_order(root, 6);
	// print inoder traversal of the BST 
//	inorder(root); 


#ifdef SEARCH
// ------- Debugging the search function-----------
    struct node *parent = NULL;
    struct node *current_node = NULL;
    int num_child = 0;

    search (root, delete_val, parent, current_node, num_child);
    
    //if((current_node != NULL) && (parent != NULL))
    std::cout<<delete_val<<"'s parent node is "<<parent->key<<" and "<<delete_val<<" has "<<num_child<<" children\n";
    
    //if((current_node != NULL) && (parent == NULL))
    //std::cout<<delete_val<<"'s parent node is NULL and "<<delete_val<<" has "<<num_child<<" children\n";
//----------------------------------
#endif

    delete_node(root, delete_val);
    
    bfs_order(root, 6);

	return 0; 
} 

