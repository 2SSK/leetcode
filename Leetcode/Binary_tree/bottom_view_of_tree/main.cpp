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

  vector<int> bottomView(TreeNode *root);
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

  vector<int> output = solution.bottomView(root);

  cout << "Output: ";
  solution.printArr(output);

  return 0;
}

vector<int> Tree::bottomView(TreeNode *root) {
  vector<int> ans;

  if (root == NULL) {
    return ans;
  }

  map<int, int> mpp;
  queue<pair<TreeNode *, int>> q;
  q.push({root, 0});

  while (!q.empty()) {
    auto it = q.front();
    q.pop();

    TreeNode *node = it.first;
    int hd = it.second;

    // Update the map with the current node's value
    mpp[hd] = node->val;

    // Traverse left and right children
    if (node->left != NULL) {
      q.push({node->left, hd - 1});
    }
    if (node->right != NULL) {
      q.push({node->right, hd + 1});
    }
  }

  for (const auto &pair : mpp) {
    ans.push_back(pair.second);
  }

  return ans;
}
