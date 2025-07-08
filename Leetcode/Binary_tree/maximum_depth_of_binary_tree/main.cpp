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
  void insert(Node *&root, int data) {
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

  int maxDepth(Node *root);
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

  cout << "Output: " << solution.maxDepth(root) << endl;

  return 0;
}

int Solution::maxDepth(Node *root) {
  if (root == nullptr) {
    return 0;
  }
  int leftDepth = maxDepth(root->left);
  int rightDepth = maxDepth(root->right);

  return max(leftDepth, rightDepth) + 1;
};
