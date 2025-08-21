
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Tree {
public:
  TreeNode *buildTree(vector<int> &arr) {
    if (arr.empty())
      return nullptr;

    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;

    while (i < arr.size()) {
      TreeNode *current = q.front();
      q.pop();

      if (i < arr.size() && arr[i] != -1) {
        current->left = new TreeNode(arr[i]);
        q.push(current->left);
      }
      i++;

      if (i < arr.size() && arr[i] != -1) {
        current->right = new TreeNode(arr[i]);
        q.push(current->right);
      }
      i++;
    }

    return root;
  }

  vector<int> rightSideView(TreeNode *root);
  void traversal(TreeNode *root, vector<int> &node, int level);
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
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
      cout << arr[i];
      if (i < arr.size() - 1) {
        cout << ", ";
      }
    }
    cout << "]" << endl;
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  TreeNode *root = solution.buildTree(input);

  vector<int> rightView = solution.rightSideView(root);

  cout << "Output: ";
  solution.printArr(rightView);

  return 0;
}

vector<int> Tree::rightSideView(TreeNode *root) {
  vector<int> ans;

  if (root == nullptr) {
    return ans;
  }

  traversal(root, ans, 0);

  return ans;
}

void Tree::traversal(TreeNode *node, vector<int> &arr, int level) {
  if (node == nullptr) {
    return;
  }

  if (level == arr.size()) {
    arr.push_back(node->val);
  }

  traversal(node->right, arr, level + 1);
  traversal(node->left, arr, level + 1);
}
