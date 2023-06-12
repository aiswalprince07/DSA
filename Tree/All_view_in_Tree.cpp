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
    cout<<"Enter data fro inserting in right :"<<endl;
    root->right = buildTree(root->right);
    return root;
}

//1. Left view in TREE (similarly Right view)

void leftView(node* root){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int cnt = q.size();
        for(int i =0;i<cnt;i++){
            node* curr = q.front();
            q.pop();
            if(i==0) cout<<curr->data<<" ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
}

// 2. Top view in TREE 

int height(node* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    return 1+max(height(root->left),height(root->right));
}


signed main(){
    node* root = NULL;
    
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //level order traversal
    // cout<<"Printing the level order traversal"<<endl;
    // levelOrder(root);

    // leftView(root);
    cout<<height(root);

    return 0;

}