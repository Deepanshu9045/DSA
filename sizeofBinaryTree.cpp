#include <iostream>
#include <queue>
using namespace std;

/*
Definition for Node
*/
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int getSize(Node* root) {
        if (root == NULL) return 0;

        return 1 + getSize(root->left) + getSize(root->right);
    }
};

// Function to build binary tree from level order input
Node* buildTree() {
    int val;
    cin >> val;

    if (val == -1) return NULL;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal >> rightVal;

        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }

        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }

    return root;
}

int main() {
    cout << "Enter tree nodes in level order (-1 for NULL): ";
    
    Node* root = buildTree();

    Solution obj;
    cout << "Size of Binary Tree: " << obj.getSize(root) << endl;

    return 0;
}