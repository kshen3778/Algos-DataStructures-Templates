#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
  Node(int data){
    this-> data = data;
    left = NULL;
    right = NULL;
  }
};

//search for a Node in tree, return Null if not found
struct Node* search(struct Node* root, int key){
  //if node is found or at a leaf (not found)
  if(root == NULL || root->data == key){
    return root;
  }

  if(root->data < key){
    return search(root->right, key);
  } else {
    return search(root->left, key);
  }
}

//insert a node
struct Node* insert(struct Node* node, int key){
  //if at leaf or empty, the new node is returned
  if(node == NULL){
    return new Node(key);
  }

  if(key < node->data){
    node->left = insert(node->left, key);
  } else if (key > node->data){
    node->right = insert(node->right, key);
  } else{
    //this means the node was already found in the tree (so no need to insert)
    return node;
  }
}

//post order traversal  eft->right->root
void postOrder(struct Node* node){
  if(node == NULL){
    return;
  }

  postOrder(node->left);
  postOrder(node->right);
  cout << node->data << " ";
}

//in order: left->root->right
void inOrder(struct Node* node){
  if(node == NULL){
    return;
  }

  inOrder(node->left);
  cout << node->data << " ";
  inOrder(node->right);
}

//preorder: root->left->right
void preOrder(struct Node* node){
  if(node == NULL){
    return;
  }

  cout << node->data << " ";
  preOrder(node->left);
  preOrder(node->right);
}



int main(){
  struct Node *root = new Node(50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);
  Node* found = search(root, 120);
  if(found != NULL){
    cout << "Found Node with value: " << found->data << endl;
  } else {
    cout << "Node not found " << endl;
  }

  cout << "\nPreorder traversal of binary tree is \n";
  preOrder(root);

  cout << "\nInorder traversal of binary tree is \n";
  inOrder(root);

  cout << "\nPostorder traversal of binary tree is \n";
  postOrder(root);
}
