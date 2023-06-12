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






/* T.C : O(N^2) */

int height(node* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    return 1+max(height(root->left),height(root->right));
}


int diameter(node* root){
    if(root==NULL) return 0;

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = 1+height(root->left)+height(root->right);

    return max({op1,op2,op3});
}

//pair<int,int>  ==> <diameter,height> 
pair<int,int> diameterFast(node* root){
    if(root==NULL){
        pair<int,int>p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = 1+left.second+right.second;

    pair<int,int>ans;
    ans.first = max({op1,op2,op3});
    ans.second = max(left.second,right.second)+1;
    return ans;

}




signed main(){
    node* root = NULL;
    
    //creating a Tree
    root = buildTree(root);

    //TC :O(N^2)
    cout<<diameter(root);
    cout<<endl;
    //TC :O(N)
    cout<<diameterFast(root).first;


    return 0;

}

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //         1 
    //    3         5
    //  7   11   17 