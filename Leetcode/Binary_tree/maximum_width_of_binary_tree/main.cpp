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

  int widthOfBinaryTree(TreeNode *root);
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

  cout << "Output: " << solution.widthOfBinaryTree(root) << endl;
  return 0;
}

int Tree::widthOfBinaryTree(TreeNode *root) {
  if (!root)
    return 0;

  int ans = 0;
  queue<pair<TreeNode *, int>> q;
  q.push({root, 0});
  while (!q.empty()) {
    int size = q.size();
    int mmin = q.front().second;
    int first, last;
    for (int i = 0; i < size; i++) {
      int cur_id = q.front().second - mmin;
      TreeNode *node = q.front().first;
      q.pop();
      if (i == 0)
        first = cur_id;
      if (i == size - 1)
        last = cur_id;
      if (node->left)
        q.push({node->left, cur_id * 2 + 1});
      if (node->right)
        q.push({node->right, cur_id * 2 + 2});
    }
    ans = max(ans, last - first + 1);
  }

  return ans;
}
