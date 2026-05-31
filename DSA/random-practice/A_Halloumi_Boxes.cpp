#include <bits/stdc++.h>
using namespace std;
#define int long long int
class Node
{   
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->left = nullptr;
        this->right = nullptr;
        this->data = data;
    }
};
Node *buildTree(Node *root)
{
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting in the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in the right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrderTraversal(Node *root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL){
            // previous level is commmpletely 
            // Next Line 
            cout << endl;
            if (!q.empty()){
                // queue still have Some Child Nodes
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }
    }
}

int32_t main()
{
    Node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    
    return 0;
}