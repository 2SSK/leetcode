// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

class Solution {

public:
  void insert(Node *&root, int val);

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

  void printBST(Node *root) {
    if (root == nullptr) {
      return;
    }
    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  Node *root = nullptr;
  for (auto val : input) {
    solution.insert(root, val);
  }
  cout << "BST: ";
  solution.printBST(root);

  return 0;
}

void Solution::insert(Node *&root, int val) {
  if (root == nullptr) {
    root = new Node(val);
    return;
  }
  if (val < root->data) {
    insert(root->left, val);
  } else {
    insert(root->right, val);
  }
}
