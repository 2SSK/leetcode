// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

// Linked list structure
struct Node {
  int data;
  Node *next;
};

// Class to implement stack using linked list
class StImLL {
private:
  Node *top;

public:
  StImLL() : top(nullptr) {}

  void Push(int n);
  int Pop();
};

// Class function's body
void StImLL::Push(int n) {
  Node *newNode = new Node();
  newNode->data = n;
  newNode->next = top;
  top = newNode;
}

int StImLL::Pop() {
  if (top == nullptr) {
    return -1;
  }
  Node *temp{top};
  top = top->next;
  int poppedValue{temp->data};
  delete temp;
  return poppedValue;
}

// INFO: Main function
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  StImLL st;
  int size;
  cin >> size;
  cin.ignore();

  string line;
  getline(cin, line);

  vector<vector<int>> ops;

  // Take input
  for (int i{}; i < size; i++) {
    string line;
    getline(cin, line);

    stringstream ss(line);
    int num;

    vector<int> op;
    while (ss >> num) {
      op.push_back(num);
    }

    ops.push_back(op);
  }

  // First process all push operations
  for (const auto &op : ops) {
    if (op.size() == 2 && op[0] == 1)
      st.Push(op[1]);
  }

  // Then process all pop operations
  for (const auto &op : ops) {
    if (op.size() == 1 && op[0] == 2)
      printf("pop : %d\n", st.Pop());
  }

  return 0;
}
