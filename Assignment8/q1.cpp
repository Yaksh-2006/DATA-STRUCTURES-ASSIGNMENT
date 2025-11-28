#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data=value;
        left=right;
        right=nullptr;
    }
    };
Node* createNode(int value){
    return new Node(value);
}
void preorder(Node* root){
    if(root== nullptr)
    return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root == nullptr)
    return;
    inorder(root->left);
    cout << root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root== nullptr){
        return;
    }
        inorder(root->left);
        cout<<root->data;
        cout<<" ";
        inorder(root->right);
}
int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);

    cout<<"preordertrans: ";
    preorder(root);
    cout<<endl;

    cout<<"inordertrans: ";
    inorder(root);
    cout<<endl;
    cout<<"postordertrans: ";
    postorder(root);
    cout<<endl;
    return 0;


}