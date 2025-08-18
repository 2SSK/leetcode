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

  void insert(TreeNode *&node, int value) {
    if (node == nullptr) {
      node = new TreeNode(value);
    } else if (value < node->val) {
      insert(node->left, value);
    } else {
      insert(node->right, value);
    }
  }

public:
  TreeNode *getRoot() { return root; }
  void insertHelper(int value) { insert(root, value); }

  vector<vector<int>> zigzagLevelOrder(TreeNode *root);
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
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++) {
      if (i > 0) {
        cout << ", ";
      }
      cout << arr[i];
    }
    cout << " ]";
  }

  template <typename T> void printArr(vector<vector<T>> arr) {
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++) {
      if (i > 0) {
        cout << ", ";
      }
      printArr(arr[i]);
    }
    cout << " ]";
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();
  for (int value : input) {
    solution.insertHelper(value);
  }

  TreeNode *root = solution.getRoot();

  vector<vector<int>> output = solution.zigzagLevelOrder(root);

  cout << "Output: ";
  solution.printArr(output);

  return 0;
}

vector<vector<int>> Tree::zigzagLevelOrder(TreeNode *root) {
  vector<vector<int>> result;

  if (root == nullptr) {
    return result;
  }

  queue<TreeNode *> nodesQueue;
  nodesQueue.push(root);
  bool leftToRight = true;

  while (!nodesQueue.empty()) {
    int size = nodesQueue.size();
    vector<int> row(size);
    for (int i = 0; i < size; i++) {
      TreeNode *node = nodesQueue.front();
      nodesQueue.pop();

      int index = leftToRight ? i : size - 1 - i;
      row[index] = node->val;

      if (node->left) {
        nodesQueue.push(node->left);
      }
      if (node->right) {
        nodesQueue.push(node->right);
      }
    }
    leftToRight = !leftToRight;
    result.push_back(row);
  }

  return result;
}
