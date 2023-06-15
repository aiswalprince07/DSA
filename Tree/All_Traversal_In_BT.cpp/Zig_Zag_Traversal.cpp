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

//Recursive tree build kar rhe h (Build Tree using Recursion)!!

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

void Zig_Zag_Traversal(node* root){
    if(root==NULL) return;

    queue<node*>q;
    q.push(root);
    int level = 0;
    while(!q.empty()){
        int size = q.size();
        vector<int>temp(size);
        for(int i =0;i<size;i++){
            node* curr = q.front();
            q.pop();

            int idx = level%2==0?i:size-1-i;
            temp[idx] = curr->data;

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        level++;
        for(auto i : temp){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

// TC: O(N)  --> Beacause In worst case...if Tree is complete tree then.. last level ko process karne order of N time lag hi jayega !!
// SC: O(N)  --> Beacause In wrost case...last level me queue me order of N element ho sakte !!
 
signed main(){
    node* root = NULL;
    
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    Zig_Zag_Traversal(root);

    return 0;

}