// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int data) {
    val = data;
    left = nullptr;
    right = nullptr;
  }
};

class BinaryTree {
public:
  TreeNode *buildTree(vector<string> &input);
  void printLevelOrder(vector<vector<int>> &result, ofstream &outFile);
};

class Solution : public BinaryTree {
public:
  vector<vector<int>> levelOrder(TreeNode *root);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution solution;

  vector<string> input;
  string value;
  while (cin >> value) {
    input.push_back(value);
  }

  TreeNode *root = solution.buildTree(input);

  vector<vector<int>> output = solution.levelOrder(root);

  ofstream outFile("output.txt");
  outFile << "Output: ";
  solution.printLevelOrder(output, outFile);

  return 0;
}

TreeNode *BinaryTree::buildTree(vector<string> &input) {
  if (input.empty() || input[0] == "null")
    return nullptr;

  TreeNode *root = new TreeNode(stoi(input[0]));
  queue<TreeNode *> q;
  q.push(root);
  int i = 1;

  while (!q.empty() && 1 < input.size()) {
    TreeNode *current = q.front();
    q.pop();

    // Left Child
    if (i < input.size() && input[i] != "null") {
      current->left = new TreeNode(stoi(input[i]));
      q.push(current->left);
    }

    // Right Child
    if (i < input.size() && input[i] != "null") {
      current->right = new TreeNode(stoi(input[i]));
      q.push(current->right);
    }
    i++;
  }

  return root;
}

vector<vector<int>> Solution::levelOrder(TreeNode *root) {
  vector<vector<int>> ans;
  if (!root)
    return ans;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int size = q.size();
    vector<int> level;

    for (int i = 0; i < size; i++) {
      TreeNode *node = q.front();
      q.pop();
      level.push_back(node->val);

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }

    ans.push_back(level);
  }

  return ans;
}

void BinaryTree::printLevelOrder(vector<vector<int>> &result,
                                 ofstream &outFile) {
  outFile << "[";
  for (size_t i = 0; i < result.size(); ++i) {
    outFile << "[";
    for (size_t j = 0; j < result[i].size(); ++j) {
      outFile << result[i][j];
      if (j != result[i].size() - 1)
        outFile << ", ";
    }
    outFile << "]";
    if (i != result.size() - 1)
      outFile << ",";
  }
  outFile << "]" << endl;
}
