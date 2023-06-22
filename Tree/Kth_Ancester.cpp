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





signed main(){
    node* root = NULL;
    
    //creating a TreeNode* solve(Node *root, int &k, int node){
    if(root==NULL || root->data==node) return root;
    
    Node* Left = solve(root->left,k,node);
    Node* Right = solve(root->right,k,node);
    
    if(Left && !Right){
        k--;
        if(k<=0){
            //answer lock kar diya!!
            k = INT_MAX;
            return root;
        }
        return Left;
    }
    if(!Left && Right){
        k--;
        if(k<=0){
            //answer lock kar diya!!
            k = INT_MAX;
            return root;
        }
        return Right;
    }
    return NULL;
}
    root = buildTree(root);

    Node* ans = solve(root,k,node);
    if(ans==NULL || ans->data==node ) cout<<-1<<endl;
    cout<<ans->data<<endl;
    


    return 0;

}

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //         1 
    //    3         5
    //  7   11   17 