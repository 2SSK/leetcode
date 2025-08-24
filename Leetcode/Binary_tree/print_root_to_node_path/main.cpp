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
  bool getPath(TreeNode *root, vector<int> &path, int x);

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

  vector<int> rootToNodePath(TreeNode *root, int target);
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
      cout << arr[i];
      if (i != arr.size() - 1)
        cout << ", ";
    }
    cout << " ]\n";
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int target;
  cin >> target;
  cin.ignore();

  vector<int> input = solution.readInput<int>();

  TreeNode *root = solution.buildTree(input);

  vector<int> output = solution.rootToNodePath(root, target);

  cout << "Output: ";
  solution.printArr(output);

  return 0;
}

bool Tree::getPath(TreeNode *root, vector<int> &path, int x) {
  if (!root)
    return false;

  path.push_back(root->val);

  if (root->val == x)
    return true;

  if (getPath(root->left, path, x) || getPath(root->right, path, x))
    return true;

  path.pop_back();
  return false;
}

vector<int> Tree::rootToNodePath(TreeNode *root, int target) {
  vector<int> path;

  if (root == NULL)
    return path;

  getPath(root, path, target);

  return path;
}
