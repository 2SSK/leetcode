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
  void traverse(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    cout << root->val << " ";
    traverse(root->left);
    traverse(root->right);
  }

  TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd,
                      vector<int> &inorder, int inStart, int inEnd,
                      map<int, int> &inMap);
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> preorder = solution.readInput<int>();
  vector<int> inorder = solution.readInput<int>();

  TreeNode *input = solution.buildTree(preorder, inorder);

  cout << "Output: ";
  solution.traverse(input);

  return 0;
}

TreeNode *Tree::buildTree(vector<int> &preorder, int preStart, int preEnd,
                          vector<int> &inorder, int inStart, int inEnd,
                          map<int, int> &inMap) {
  if (preStart > preEnd || inStart > inEnd) {
    return nullptr;
  }
  TreeNode *root = new TreeNode(preorder[preStart]);

  int inRoot = inMap[root->val];
  int numsLeft = inRoot - inStart;

  root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder,
                         inStart, inRoot - 1, inMap);
  root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder,
                          inRoot + 1, inEnd, inMap);

  return root;
}

TreeNode *Tree::buildTree(vector<int> &preorder, vector<int> &inorder) {
  map<int, int> inMap;

  for (int i = 0; i < inorder.size(); i++) {
    inMap[inorder[i]] = i;
  }

  return buildTree(preorder, 0, preorder.size() - 1, inorder, 0,
                   inorder.size() - 1, inMap);
}
