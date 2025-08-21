#include <bits/stdc++.h>
#include <ios>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Tree {
private:
  bool isMirror(TreeNode *left, TreeNode *right);

public:
  TreeNode *buildTree(vector<int> &values) {
    if (values.empty())
      return nullptr;

    TreeNode *root = new TreeNode(values[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;

    while (i < values.size()) {
      TreeNode *current = q.front();
      q.pop();

      if (i < values.size() && values[i] != -1) {
        current->left = new TreeNode(values[i]);
        q.push(current->left);
      }
      i++;

      if (i < values.size() && values[i] != -1) {
        current->right = new TreeNode(values[i]);
        q.push(current->right);
      }
      i++;
    }

    return root;
  }

  bool isSymmetric(TreeNode *root);
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

  cout << "Output: " << boolalpha << solution.isSymmetric(root) << endl;

  return 0;
}

bool Tree::isSymmetric(TreeNode *root) {
  if (!root)
    return true;

  return isMirror(root->left, root->right);
}

bool Tree::isMirror(TreeNode *left, TreeNode *right) {
  if (!left && !right) {
    return true;
  }

  if (!left || !right) {
    return false;
  }

  return (left->val == right->val) && isMirror(left->left, right->right) &&
         isMirror(left->right, right->left);
}
