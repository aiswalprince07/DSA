#include<bits/stdc++.h>
using namespace std;
// #define int long long

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





void verticalOrderTraversal(node* root){
    //  Hd ,    level     ,nodes
    map<int,map<int,vector<int>>>nodes;
    queue<pair<node*,pair<int,int>>>q;

    if(root==NULL) return;
    q.push({root,{0,0}});

    while(!q.empty()){
        pair<node*, pair<int,int>> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int Hd = temp.second.first;
        int level = temp.second.second;

        nodes[Hd][level].push_back(frontNode->data);
        if(frontNode->left)
            q.push({frontNode->left,{Hd-1,level+1}});

        if(frontNode->right)
            q.push({frontNode->right,{Hd+1,level+1}});
        
    }
    for(auto i : nodes){
        for(auto j : i.second){
            for(auto k : j.second){
                cout<<k<<" ";
            }
        }
    }
}



int main(){
    node* root = NULL;
    
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    verticalOrderTraversal(root);
    

    return 0;

}