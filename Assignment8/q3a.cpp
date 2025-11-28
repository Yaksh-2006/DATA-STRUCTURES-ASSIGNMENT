#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left, *right;

    Node(int value){
        data=value;
        left = right;
        right = nullptr;
    }
};
class BST{
    public:
    Node* root;
    BST(){
        root=nullptr;
    }
    Node* insert(Node* node,int value){
        if(node == nullptr)
        return new Node(value);
        if(value<node->data)
        node->left=
        insert(node->left,value);
        else if(value>node->data)
        node->right=
        insert(node->right,value);
        return node;
}
void inorder(Node* node){
    if (node != nullptr){
        inorder(node->left);
        cout<<node->data<<endl;
        inorder(node->right);
    }
    }
};
int main(){
    BST tree;

    tree.root = tree.insert(tree.root,50);
    tree.root = tree.insert(tree.root,30);
    tree.root = tree.insert(tree.root,70);
    tree.root = tree.insert(tree.root,20);
    tree.root = tree.insert(tree.root,40);
    tree.root = tree.insert(tree.root,60);
    tree.root = tree.insert(tree.root,80);
    tree.root = tree.insert(tree.root,30);
    cout<<"BST:";
    tree.inorder(tree.root);
    return 0;
}