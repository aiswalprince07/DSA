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

vector<int>ans; // For inorder

void Morris_traversal(node* root){
    if(root==NULL) return;
    node* curr = root;
    node* prev = NULL;
    while(curr!=NULL){
        // ans.pus_back(curr->data);  // --> For Iterative InOrder 
        if(curr->left==NULL){
            cout<<curr->data<<" ";  // For Iterative PreOrder  ||  [ If you perfom PostOrder then store curr->data;]
            curr = curr->right;
        }else{
            prev = curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                prev = prev->right;
            }

            if(prev->right==NULL){
                // If I do Post Order then I store curr->data;
                prev->right = curr;
                curr = curr->left;
            }else{
                prev->right = NULL;
                cout<<curr->data<<" ";  // for Iterative PreOrder
                curr = curr->right;
                //ans.pop();            // For Iterative InOrder
            }
        }
    }
}

signed main(){
    node* root = NULL;
    
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    Morris_traversal(root);

    // for Inorder Traversal print --> vector<int>ans;
    // for(auto i : ans) cout<<i<<" ";

    //For PostOrder Traversal --> Convert all [Left <--> right] in morrisTraversal

    return 0;

}