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
private:
  int findHeightLeft(TreeNode *node) {
    int height = 0;
    while (node) {
      height++;
      node = node->left;
    }
    return height;
  }

  int findHeightRight(TreeNode *node) {
    int height = 0;
    while (node) {
      height++;
      node = node->right;
    }
    return height;
  }

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

      if (nodes[i] != -1) {
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

  int countNodes(TreeNode *root);
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

  TreeNode *root = solution.buildTree(input);

  cout << "Output: " << solution.countNodes(root);

  return 0;
}

int Tree::countNodes(TreeNode *root) {
  if (root == NULL)
    return 0;

  int lh = findHeightLeft(root);
  int rh = findHeightRight(root);

  if (lh == rh)
    return (1 << lh) - 1;

  return 1 + countNodes(root->left) + countNodes(root->right);
}
