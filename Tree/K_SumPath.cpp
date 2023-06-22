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

void solve(node* root,int k,unordered_map<int,int>&m,int &cnt,int sum){
        if(root==NULL) return;
        
        sum+=root->data;
        cnt+=m[sum-k];
        // if(sum==k) cnt++;   // or this
        m[sum]++;
        solve(root->left,k,m,cnt,sum);
        solve(root->right,k,m,cnt,sum);
        m[sum]--;
}



signed main(){
    node* root = NULL;
    
    //creating a Tree
    root = buildTree(root);

    unordered_map<int,int>m;
    m[0]++; //or this
    int cnt = 0;
    solve(root,k,m,cnt,0);
    return cnt;
    


    return 0;

}

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //         1 
    //    3         5
    //  7   11   17 