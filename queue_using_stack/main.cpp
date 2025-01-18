// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <ios>
#include <sstream>
#include <string>
using namespace std;

class QuWtStk {
private:
  stack<int> st;
  stack<int> temp;

public:
  void push(int n);
  int pop();
  int peek();
  bool empty();
};

// Push function
void QuWtStk::push(int n) {
  // If stack is empty push the element
  if (st.empty()) {
    st.push(n);
    return;
  } else {
    // If st is not empty transfer all elements to another stack
    while (!st.empty()) {
      temp.push(st.top());
      st.pop();
    }
    // Now push the new element
    st.push(n);
    // Now inject all elements back to the original stack
    while (!temp.empty()) {
      st.push(temp.top());
      temp.pop();
    }
  }
}

// Pop function
int QuWtStk::pop() {
  // if stack is empty return -1
  if (st.empty()) {
    return -1;
  }
  // else return the top element
  int top = st.top();
  st.pop();
  return top;
}

// Peek function
int QuWtStk::peek() {
  if (st.empty()) {
    return -1;
  }
  return st.top();
}

// Empty function
bool QuWtStk::empty() { return st.empty(); }

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  QuWtStk qu;

  int size;
  cin >> size;
  cin.ignore();

  vector<string> operations(size);
  string tempOperations;
  getline(cin, tempOperations);
  stringstream ssOps(tempOperations);
  for (int i{}; i < size; i++) {
    ssOps >> operations[i];
  }

  vector<int> inputs(size, -1);
  string tempInputs;
  getline(cin, tempInputs);
  stringstream ssInputs(tempInputs);
  for (int i{}; i < size; i++) {
    if (operations[i] == "push") {
      ssInputs >> inputs[i];
    }
  }

  // Perform the operations
  for (int i{}; i < size; i++) {
    if (operations[i] == "MyQueue") {
      cout << "null ";
    } else if (operations[i] == "push") {
      qu.push(inputs[i]);
      cout << "null ";
    } else if (operations[i] == "pop") {
      cout << qu.pop() << " ";
    } else if (operations[i] == "peek") {
      cout << qu.peek() << " ";
    } else if (operations[i] == "empty") {
      cout << std::boolalpha << qu.empty() << " ";
    }
  }

  return 0;
}
