// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================
#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
  stack<pair<int, int>> st;

public:
  void push(int val);
  void pop();
  int top();
  int getMin();
};

void MinStack::push(int val) {
  if (st.empty()) {
    st.push({val, val});
  } else {
    st.push({val, min(val, st.top().second)});
  }
}

void MinStack::pop() {
  if (!st.empty()) {
    st.pop();
  }
}

int MinStack::top() {
  int topVal;
  if (!st.empty()) {
    topVal = st.top().first;
  }
  return topVal;
}

int MinStack::getMin() {
  int minVal;
  if (!st.empty()) {
    minVal = st.top().second;
  }
  return minVal;
}

template <typename T> stringstream readInput() {
  string inputStr;
  getline(cin, inputStr);
  stringstream ss(inputStr);
  return ss;
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int size;
  cin >> size;
  cin.ignore();

  vector<string> operations(size);
  stringstream ss = readInput<string>();

  vector<int> userInputs(size, INT_MIN);
  stringstream ii = readInput<string>();

  for (int i{}; i < size; i++) {
    ss >> operations[i];
    if (operations[i] == "push") {
      ii >> userInputs[i];
    }
  }

  MinStack ms;

  for (int i{}; i < size; i++) {
    if (operations[i] == "push") {
      ms.push(userInputs[i]);
      cout << "null ";
    } else if (operations[i] == "pop") {
      ms.pop();
      cout << "null ";
    } else if (operations[i] == "top") {
      cout << ms.top() << " ";
    } else if (operations[i] == "getMin") {
      cout << ms.getMin() << " ";
    } else {
      cout << "null ";
    }
  }

  return 0;
}
