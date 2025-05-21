#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* makeTree(vector<int>& preorder, int start, int end){
    if(start > end) return nullptr;  
    
    Node* root = new Node{preorder[start], nullptr, nullptr};

    int mid = start + 1;
    while (mid <= end && preorder[mid] < preorder[start])
    {
        mid++;
    }

    root->left = makeTree(preorder, start+1, mid-1);
    root->right = makeTree(preorder, mid, end);

    return root;
    
}

void postorder(Node* node){
    if(!node) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << "\n";
}

int main(){

    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    vector<int> preorder;
    int node;
    while(cin >> node){
        preorder.push_back(node);
    }

    Node* root = makeTree(preorder, 0, preorder.size() - 1);

    postorder(root);

    return 0;
}