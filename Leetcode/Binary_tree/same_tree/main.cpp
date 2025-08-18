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

public:
  TreeNode *getRoot() { return root; }
  void insert(TreeNode *&node, int value) {
    if (node == nullptr) {
      node = new TreeNode(value);
    } else if (value < node->val) {
      insert(node->left, value);
    } else {
      insert(node->right, value);
    }
  }

  bool isSameTree(TreeNode *p, TreeNode *q);
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

  TreeNode *p = nullptr;
  TreeNode *q = nullptr;

  vector<int> input1 = solution.readInput<int>();
  for (int value : input1) {
    if (value == -1) {
      p = nullptr;
      continue;
    }
    solution.insert(p, value);
  }

  vector<int> input2 = solution.readInput<int>();
  for (int value : input2) {
    if (value == -1) {
      q = nullptr;
      continue;
    }
    solution.insert(q, value);
  }

  cout << "Output: " << boolalpha << solution.isSameTree(p, q) << endl;

  return 0;
}

bool Tree::isSameTree(TreeNode *p, TreeNode *q) {
  if (p == nullptr && q == nullptr) {
    return true;
  }

  if (p == nullptr || q == nullptr) {
    return false;
  }

  return (p->val == q->val) && isSameTree(p->left, q->left) &&
         isSameTree(p->right, q->right);
}
