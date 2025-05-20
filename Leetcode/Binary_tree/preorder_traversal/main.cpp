// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree {
protected:
  TreeNode *root = nullptr;
  queue<TreeNode *> q;
  bool isLeftNext = true;

  // Insert a value into a complete binary tree
  void insertLevelOrder(int val) {
    if (val == -1) {
      if (!root)
        return;
      if (!q.empty()) {
        if (isLeftNext) {
          isLeftNext = false;
        } else {
          q.pop();
          isLeftNext = true;
        }
      }
      return;
    }

    TreeNode *newNode = new TreeNode(val);
    if (!root) {
      root = newNode;
      q.push(root);
      isLeftNext = true;
      return;
    }

    TreeNode *current = q.front();
    if (isLeftNext) {
      current->left = newNode;
      isLeftNext = false;
    } else {
      current->right = newNode;
      q.pop();
      isLeftNext = true;
    }
    q.push(newNode);
  }

  void preorder(TreeNode *node, vector<int> &result) {
    if (node) {
      result.push_back(node->val);
      preorder(node->left, result);
      preorder(node->right, result);
    }
  }

public:
  void insert(int value) { insertLevelOrder(value); }

  vector<int> preorderTraversal() {
    vector<int> result;
    preorder(root, result);
    return result;
  }

  virtual ~BinaryTree() {
    queue<TreeNode *> q;
    if (root)
      q.push(root);
    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);

      delete node;
    }
  }
};

class Solution : public BinaryTree {
public:
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

  template <typename T> void printArr(vector<T> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        cout << "[ " << arr[i] << " | ";
      } else if (i == n - 1) {
        cout << arr[i] << " ]\n";
      } else {
        cout << arr[i] << " | ";
      }
    }
  }

  void insertToTree(vector<int> &arr) {
    for (int val : arr) {
      insert(val);
    }
  }

  using BinaryTree::preorderTraversal;
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();
  solution.insertToTree(input);
  vector<int> output = solution.preorderTraversal();

  cout << "Output: ";
  solution.printArr(output);

  return 0;
}
