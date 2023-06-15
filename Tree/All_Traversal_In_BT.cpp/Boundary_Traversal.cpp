#include<bits/stdc++.h>
using namespace std;
#define int long long

class node{
    public:
    int data;
    node* left;
    node*right;
    node(int d){
        this->data = d;
        this->left= NULL;
        this->right = NULL;
    }
};

//Recursive tree build kar rhe h !!

node* buildTree(node* root){
    cout<<"Enter the data :"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data==-1)return NULL;
    cout<<"Enter data for inserting in left :"<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right :"<<endl;
    root->right = buildTree(root->right);
    return root;
}

// Logic :
/*
    --> Firstlly print the root->data 
  1. Print left part exclusive leafnode
  2. print all leaf node
  3. print right part in reverse order exclusive leafnode
*/

void Traverse_Left(node* root){
    if((root==NULL)||(!root->left && !root->right)) return;

    cout<<root->data<<" ";
    if(root->left){
        Traverse_Left(root->left);
    }else{
        Traverse_Left(root->right);  
    }
}

void Traverse_Leaf(node* root){
    if(root==NULL) return;

    if(!root->left && !root->right){
        cout<<root->data<<" ";
        return;
    }
    Traverse_Leaf(root->left);
    Traverse_Leaf(root->right);
}

void Traverse_right(node* root){
    if((root==NULL)||(!root->left && !root->right)) return;

    if(root->right){
        Traverse_right(root->right);
    }else{
        Traverse_right(root->left);
    }
    cout<<root->data<<" ";

}

void Boundary_Traversal(node* root){
    if(root==NULL) return; 
    cout<<root->data<<" ";
    // 1.
    Traverse_Left(root->left);

    // 2.
    Traverse_Leaf(root->left);
    Traverse_Leaf(root->right);

    // 3.
    Traverse_right(root->right);

}


signed main(){
    node* root = NULL;
    
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    Boundary_Traversal(root);

    return 0;

}