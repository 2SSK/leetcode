#include <bits/stdc++.h>
#include <unordered_map>
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
  void markParents(TreeNode *root,
                   unordered_map<TreeNode *, TreeNode *> &parent_track,
                   TreeNode *target);

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

  TreeNode *findNode(TreeNode *root, int val) {
    if (!root)
      return nullptr;
    if (root->val == val)
      return root;
    TreeNode *left = findNode(root->left, val);
    if (left)
      return left;
    return findNode(root->right, val);
  }

  vector<int> distanceK(TreeNode *root, TreeNode *target, int k);
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
  int targetVal, k;
  cin >> targetVal >> k;

  TreeNode *root = solution.buildTree(input);
  TreeNode *target = solution.findNode(root, targetVal);

  vector<int> output = solution.distanceK(root, target, k);

  cout << "Output: ";
  solution.printArr(output);

  return 0;
}

void Tree::markParents(TreeNode *root,
                       unordered_map<TreeNode *, TreeNode *> &parent_track,
                       TreeNode *target) {
  queue<TreeNode *> queue;
  queue.push(root);
  while (!queue.empty()) {
    TreeNode *current = queue.front();
    queue.pop();
    if (current->left) {
      parent_track[current->left] = current;
      queue.push(current->left);
    }
    if (current->right) {
      parent_track[current->right] = current;
      queue.push(current->right);
    }
  }
}

vector<int> Tree::distanceK(TreeNode *root, TreeNode *target, int k) {
  unordered_map<TreeNode *, TreeNode *> parent_track;
  markParents(root, parent_track, target);

  unordered_map<TreeNode *, bool> visited;
  queue<TreeNode *> queue;
  queue.push(target);
  visited[target] = true;
  int curr_level = 0;
  while (!queue.empty()) {
    int size = queue.size();
    if (curr_level++ == k)
      break;
    for (int i = 0; i < size; i++) {
      TreeNode *current = queue.front();
      queue.pop();
      if (current->left && !visited[current->left]) {
        queue.push(current->left);
        visited[current->left] = true;
      }
      if (current->right && !visited[current->right]) {
        queue.push(current->right);
        visited[current->right] = true;
      }
      if (parent_track[current] && !visited[parent_track[current]]) {
        queue.push(parent_track[current]);
        visited[parent_track[current]] = true;
      }
    }
  }

  vector<int> result;
  while (!queue.empty()) {
    TreeNode *current = queue.front();
    queue.pop();
    result.push_back(current->val);
  }
  return result;
}
