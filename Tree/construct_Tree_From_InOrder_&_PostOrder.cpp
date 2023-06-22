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

// We can optimize by using map !!!
int findPosition(vector<int>&inorder,int k){
        for(int i =0;i<inorder.size();i++){
            if(inorder[i]==k) return i;
        }
        return -1;
    }
    node* solve(vector<int>& postorder, vector<int>& inorder,int &index,int inStart,int inEnd){
        if(index<0 || inStart>inEnd){
            return NULL;
        }
        int element = postorder[index--];
        node* root = new node(element);
        int position = findPosition(inorder,element);
        root->right = solve(postorder,inorder,index,position+1,inEnd);
        root->left = solve(postorder,inorder,index,inStart,position-1);
        return root;
}


signed main(){
    int n;
    cin>>n;
    vector<int>postorder,inorder;

    for(int i =0;i<n;i++){
        int x;cin>>x;
        postorder.push_back(x);
    }
    for(int i =0;i<n;i++){
        int x;cin>>x;
        inorder.push_back(x);
    }
    
    int postorderIndex = n-1;
    int n = inorder.size();
    node* ans = solve(postorder,inorder,postorderIndex,0,n-1);
    return ans;
    


    return 0;

}

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //         1 
    //    3         5
    //  7   11   17 