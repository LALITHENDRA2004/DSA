// Binary Tree Implementation

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node *root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        if(temp -> left == NULL) {
            temp -> left = new Node(data);
            break;
        }
        else q.push(temp -> left);
        if(temp -> right == NULL) {
            temp -> right = new Node(data);
            break;
        }
        else q.push(temp -> right);
    }
    return root;
}

// Depth-First Search Algorithms

void preorder(Node *root) {
    if(root == NULL) return;
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(Node *root) {
    if(root == NULL) return;
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void postorder(Node *root) {
    if(root == NULL) return;
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

// Breadth-First Search Algorithms

void levelorder(Node *root) {
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        cout << temp -> data << " ";
        if(temp -> left != NULL) q.push(temp -> left);
        if(temp -> right != NULL) q.push(temp -> right);
    }
}

int countNodes(Node *root) {
    if(root == NULL) return 0;

    int leftCount = countNodes(root -> left);
    int rightCount = countNodes(root -> right);

    return leftCount + rightCount + 1;
}

int sumOfNodes(Node *root) {
    if(root == NULL) return 0;

    int leftSum = sumOfNodes(root -> left);
    int rightSum = sumOfNodes(root -> right);

    return leftSum + rightSum + root -> data;
}

int heightOfTree(Node *root) {
    if(root == NULL) return 0;

    int leftHeight = heightOfTree(root -> left);
    int rightHeight = heightOfTree(root -> right);
    int maxHeight = max(leftHeight, rightHeight) + 1;

    return maxHeight;
}

int main() {

    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    cout << "Preorder Traversal : "; 
    preorder(root);
    
    cout << endl << "Inorder Traversal : "; 
    inorder(root);
    
    cout << endl << "Postorder Traversal : ";
    postorder(root);

    cout << endl << "Levelorder Traversal : ";
    levelorder(root);

    cout << endl << "Count of Nodes : " << countNodes(root);

    cout << endl << "Sum of Nodes : " << sumOfNodes(root);

    cout << endl << "Height of tree : " << heightOfTree(root);

    return 0;
}













