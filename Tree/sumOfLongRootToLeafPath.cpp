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


void solve(node* root,int sum,int &mxSum,int len,int &mxLen){
        if(root==NULL){
            if(len>mxLen){
                mxLen = len;
                mxSum = sum;
            }else if(len==mxLen){
                mxSum = max(mxSum,sum);
            }
            return;
        }
    sum= sum+root->data;
    solve(root->left,sum,mxSum,len+1,mxLen);
    solve(root->right,sum,mxSum,len+1,mxLen);
}




signed main(){
    node* root = NULL;
    
    //creating a Tree
    root = buildTree(root);

    int sum=0,mxSum = INT_MIN,len=0,mxLen = 0;
    if(root==NULL) return 0;
    solve(root,sum,mxSum,len,mxLen);
    
    cout<<mxSum<<endl;


    return 0;

}

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //         1 
    //    3         5
    //  7   11   17 