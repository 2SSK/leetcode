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

  vector<int> toVector(TreeNode *root) {

    vector<int> result;

    if (!root)
      return result;

    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty()) {

      TreeNode *node = q.front();

      q.pop();

      result.push_back(node->val);

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }

    return result;
  }

  string serialize(TreeNode *root);

  TreeNode *deserialize(string data);
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

  string output = solution.serialize(root);
  TreeNode *newRoot = solution.deserialize(output);

  vector<int> outputArr = solution.toVector(newRoot);

  cout << "Output: ";
  solution.printArr(outputArr);

  return 0;
}

string Tree::serialize(TreeNode *root) {
  if (!root)
    return "";

  string output = "";
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *current = q.front();
    q.pop();
    if (current == nullptr) {
      output.append("#, ");
    } else {
      output.append(to_string(current->val) + ", ");
    }
    if (current != nullptr) {
      q.push(current->left);
      q.push(current->right);
    }
  }

  return output;
}

TreeNode *Tree::deserialize(string data) {
  if (data.size() == 0)
    return nullptr;

  stringstream s(data);
  string str;
  getline(s, str, ',');

  TreeNode *root = new TreeNode(stoi(str));
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    getline(s, str, ',');
    if (str == " #") {
      node->left = nullptr;
    } else {
      TreeNode *leftNode = new TreeNode(stoi(str));
      node->left = leftNode;
      q.push(leftNode);
    }

    getline(s, str, ',');
    if (str == " #") {
      node->right = nullptr;
    } else {
      TreeNode *rightNode = new TreeNode(stoi(str));
      node->right = rightNode;
      q.push(rightNode);
    }
  }

  return root;
}
