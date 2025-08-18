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

  void insert(TreeNode *&node, int val) {
    if (node == nullptr) {
      node = new TreeNode(val);
    } else if (val < node->val) {
      insert(node->left, val);
    } else {
      insert(node->right, val);
    }
  }

public:
  TreeNode *getRoot() { return root; }

  void insertHelper(int val) { insert(root, val); }

  int maxPathDown(TreeNode *node, int &maxSum);

  int maxPathSum(TreeNode *root);
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
  for (int val : input) {
    solution.insertHelper(val);
  }

  TreeNode *root = solution.getRoot();

  cout << "Output: " << solution.maxPathSum(root) << endl;

  return 0;
}
int Tree::maxPathDown(TreeNode *node, int &maxSum) {
  if (node == NULL)
    return 0;

  int left = max(0, maxPathDown(node->left, maxSum));
  int right = max(0, maxPathDown(node->right, maxSum));
  maxSum = max(maxSum, left + right + node->val);

  return max(left, right) + node->val;
}

int Tree::maxPathSum(TreeNode *root) {
  int maxSum = INT_MIN;
  maxPathDown(root, maxSum);
  return maxSum;
}
