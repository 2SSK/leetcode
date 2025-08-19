#include <bits/stdc++.h>
#include <set>
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

public:
  TreeNode *getRoot() { return root; }

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

  vector<vector<int>> verticalTraversal(TreeNode *root);
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
    for (int i = 0; i < arr.size(); i++) {
      cout << arr[i];
      if (i < arr.size() - 1) {
        cout << ", ";
      }
    }
    cout << "]";
  }

  template <typename T> void printArr(vector<vector<T>> arr) {
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++) {
      printArr(arr[i]);
      if (i < arr.size() - 1) {
        cout << ", ";
      }
    }
    cout << " ]\n";
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  TreeNode *root = solution.buildTree(input);
  vector<vector<int>> output = solution.verticalTraversal(root);

  cout << "Output: ";
  solution.printArr(output);

  return 0;
}

vector<vector<int>> Tree::verticalTraversal(TreeNode *root) {
  map<int, map<int, multiset<int>>> nodes;
  queue<pair<TreeNode *, pair<int, int>>> todos;
  todos.push({root, {0, 0}});

  while (!todos.empty()) {
    auto p = todos.front();
    todos.pop();
    TreeNode *node = p.first;

    int x = p.second.first, y = p.second.second;
    nodes[x][y].insert(node->val);
    if (node->left) {
      todos.push({node->left, {x - 1, y + 1}});
    }
    if (node->right) {
      todos.push({node->right, {x + 1, y + 1}});
    }
  }

  vector<vector<int>> ans;
  for (auto p : nodes) {
    vector<int> col;
    for (auto q : p.second) {
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }

  return ans;
}
