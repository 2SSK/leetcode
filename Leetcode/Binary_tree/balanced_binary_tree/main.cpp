// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

// BST
struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

class Solution {
public:
  void insert(TreeNode *&root, int data) {
    if (root == nullptr) {
      root = new TreeNode(data);
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

  int checkHeight(TreeNode *root);
  bool isBalanced(TreeNode *root);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();
  TreeNode *root = nullptr;
  for (int i = 0; i < input.size(); i++) {
    solution.insert(root, input[i]);
  }

  cout << "Output: " << boolalpha << solution.isBalanced(root) << endl;

  return 0;
}

bool Solution::isBalanced(TreeNode *root) { return checkHeight(root) != -1; }

int Solution::checkHeight(TreeNode *root) {
  if (!root)
    return 0;

  int leftHeight = checkHeight(root->left);
  if (leftHeight == -1)
    return -1;

  int rightHeight = checkHeight(root->right);
  if (rightHeight == -1)
    return -1;

  if (abs(leftHeight - rightHeight) > 1)
    return -1;

  return std::max(leftHeight, rightHeight) + 1;
}
