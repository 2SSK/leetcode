#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Tree {
public:
  TreeNode *buildTree(vector<int> &nodes) {
    if (nodes.empty())
      return nullptr;

    TreeNode *root = new TreeNode(nodes[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
      TreeNode *current = q.front();
      q.pop();

      if (nodes[i] != -1) { // Assuming -1 represents null
        current->left = new TreeNode(nodes[i]);
        q.push(current->left);
      }
      i++;

      if (i < nodes.size() && nodes[i] != -1) {
        current->right = new TreeNode(nodes[i]);
        q.push(current->right);
      }
      i++;
    }

    return root;
  }

  TreeNode *findNode(TreeNode *root, int val) {
    if (!root)
      return nullptr;
    if (root->val == val)
      return root;
    TreeNode *left = findNode(root->left, val);
    if (left)
      return left;
    return findNode(root->right, val);
  }

  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);
};

class Solution : public Tree {
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
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();
  int p_val, q_val;
  cin >> p_val >> q_val;

  TreeNode *root = solution.buildTree(input);

  TreeNode *p = solution.findNode(root, p_val);
  TreeNode *q = solution.findNode(root, q_val);

  TreeNode *output = solution.lowestCommonAncestor(root, p, q);

  cout << "Output: " << output->val << "\n";

  return 0;
}

TreeNode *Tree::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (root == NULL || root == p || root == q)
    return root;
  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  TreeNode *right = lowestCommonAncestor(root->right, p, q);

  if (left == NULL) {
    return right;
  } else if (right == NULL) {
    return left;
  } else {
    return root;
  }
}
