// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

// BST
struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

class Solution {
public:
  void insert(Node *&root, int data);

  template <typename T> vector<T> readInput() {
    vector<T> inputArr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    T value;
    while (ss >> value) {
      inputArr.push_back(value);
    }

    return inputArr;
  }

  void inorderTraversal(Node *root);
  void preorderTraversal(Node *root);
  void postorderTraversal(Node *root);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();
  Node *root = nullptr;
  for (int i = 0; i < input.size(); i++) {
    solution.insert(root, input[i]);
  }

  cout << "Inorder Traversal: ";
  solution.inorderTraversal(root);
  cout << endl << "Preorder Traversal: ";
  solution.preorderTraversal(root);
  cout << endl << "Postorder Traversal: ";
  solution.postorderTraversal(root);

  return 0;
}

void Solution::insert(Node *&root, int data) {
  if (root == nullptr) {
    root = new Node(data);
    return;
  }
  if (data < root->data) {
    insert(root->left, data);
  } else if (data > root->data) {
    insert(root->right, data);
  }
};

void Solution::inorderTraversal(Node *root) {
  if (root == nullptr) {
    return;
  }
  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
};

void Solution::preorderTraversal(Node *root) {
  if (root == nullptr) {
    return;
  }
  cout << root->data << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
};

void Solution::postorderTraversal(Node *root) {
  if (root == nullptr) {
    return;
  }
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout << root->data << " ";
};
