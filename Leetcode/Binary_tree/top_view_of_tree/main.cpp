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
  TreeNode *buildTree(vector<int> &input) {
    if (input.empty() || input[0] == -1) {
      return nullptr;
    }

    TreeNode *root = new TreeNode(input[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < input.size()) {
      TreeNode *curr = q.front();
      q.pop();

      // Left child
      if (input[i] != -1) {
        curr->left = new TreeNode(input[i]);
        q.push(curr->left);
      }
      i++;

      // Right child
      if (input[i] != -1) {
        curr->right = new TreeNode(input[i]);
        q.push(curr->right);
      }
      i++;
    }

    return root;
  }

  vector<int> topView(TreeNode *root);
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

  vector<int> output = solution.topView(root);

  cout << "Output: ";
  solution.printArr(output);

  return 0;
}

vector<int> Tree::topView(TreeNode *root) {
  vector<int> result;
  if (root == nullptr) {
    return result;
  }

  map<int, int> mpp;
  queue<pair<TreeNode *, int>> q;
  q.push({root, 0});

  while (!q.empty()) {
    auto it = q.front();
    q.pop();
    TreeNode *node = it.first;
    int hd = it.second;

    // If this is the first node at its horizontal distance
    if (mpp.find(hd) == mpp.end()) {
      mpp[hd] = node->val;
    }

    // Traverse left and right children
    if (node->left) {
      q.push({node->left, hd - 1});
    }
    if (node->right) {
      q.push({node->right, hd + 1});
    }
  }

  // Extracting the values in sorted order of horizontal distance
  for (auto it : mpp) {
    result.push_back(it.second);
  }

  return result;
}
