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
  
void BottomView(node* root){
    if(root==NULL) return;

    map<int,int>m;
    queue<pair<node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int Hd = temp.second;

        m[Hd] = frontNode->data;

        if(frontNode->left)
            q.push({frontNode->left,Hd-1});
        if(frontNode->right)
            q.push({frontNode->right,Hd+1});
    }
    for(auto i : m){
        cout<<i.second<<" ";
    }
}

signed main(){
    node* root = NULL;
    
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    BottomView(root);

    return 0;

}