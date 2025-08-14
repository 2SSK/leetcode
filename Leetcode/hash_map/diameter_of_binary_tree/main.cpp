#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Tree {
private:
  TreeNode *root = nullptr;

  int height(TreeNode *node, int &diameter) {
    if (!node)
      return 0;
    int lh = height(node->left, diameter);
    int rh = height(node->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
  }

  void insertHelper(TreeNode *&node, int data) {
    if (!node) {
      node = new TreeNode(data);
      return;
    }
    if (data < node->val)
      insertHelper(node->left, data);
    else if (data > node->val)
      insertHelper(node->right, data);
  }

public:
  void insert(int data) { insertHelper(root, data); }
  int diameterOfBinaryTree() {
    int diameter = 0;
    height(root, diameter);
    return diameter;
  }
};

class Solution : public Tree {
public:
  template <typename T> vector<T> readInput() {
    vector<T> inputArr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    T value;
    while (ss >> value)
      inputArr.push_back(value);
    return inputArr;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;
  vector<int> input = solution.readInput<int>();
  for (int val : input)
    solution.insert(val);

  cout << "Output: " << solution.diameterOfBinaryTree() << "\n";
  return 0;
}
