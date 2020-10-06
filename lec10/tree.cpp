#include <iostream>
  
struct Node 
{ 
    int data; 
    struct Node* left;
    struct Node* right; 
}; 
  
/* allocates a new node */
Node* new_node(int data) 
{ 
    Node* node = (Node*)malloc(sizeof(Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
// insert nodes in array order 
Node* insert(int arr[], Node* root, 
                       int i, int n) 
{ 
    // Base case for recursion 
    if (i < n) 
    { 
        Node* temp = new_node(arr[i]); 
        root = temp; 
  
        // insert left child 
        root->left = insert(arr, 
                   root->left, 2 * i + 1, n); 
  
        // insert right child 
        root->right = insert(arr, 
                  root->right, 2 * i + 2, n); 
    } 
    return root; 
} 
  
// print the tree in order of level
void print_in_order(Node* root) 
{ 
    if (root != NULL) 
    { 
        print_in_order(root->left); 
        std::cout << root->data <<" "; 
        print_in_order(root->right); 
    } 
} 
  
int main(int args, char **argv) 
{ 
    int arr[] = { 1, 2, 3, 4, 5, 6}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    Node* root = insert(arr, root, 0, n); 
    print_in_order(root); 
} 
  

