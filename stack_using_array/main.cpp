// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

class stkImpl {
private:
  int top{-1};
  int *st = new int[10];

public:
  void Push(int n);
  int Pop();
  // Destructor
  ~stkImpl() { delete[] st; }
};

// Push function
void stkImpl::Push(int n) {
  if (top >= 10) {
    cout << "Stack overflow!!\n";
    return;
  }
  st[++top] = n;
}

// Pop function
int stkImpl::Pop() {
  if (top == -1)
    return -1;

  return st[top--];
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  stkImpl st;
  int size;
  cin >> size;

  vector<int> ops(size);
  for (int i{}; i < size; i++) {
    cin >> ops[i];
  }

  for (size_t i{}; i < size; i++) {
    if (ops[i] == 1) {
      st.Push(ops[i + 1]);
    }
    if (ops[i] == 2 && ops[i - 1] != 1) {
      printf("Pop : %d\n", st.Pop());
    }
  }

  return 0;
}
