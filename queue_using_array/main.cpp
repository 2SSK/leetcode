// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// Class
class quImpl {
private:
  int start{};
  int end{};
  int *arr = new int[10];

public:
  void Push(int n);
  int Pop();
  ~quImpl() { delete[] arr; }
};

// Main function
int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  quImpl q;
  int size;
  cin >> size;

  vector<int> ops(size);

  for (size_t i{}; i < size; i++) {
    cin >> ops[i];
  }

  for (int i{}; i < size; i++) {
    if (ops[i] == 1) {
      q.Push(ops[i + 1]);
    }
    if (ops[i] == 2 && ops[i - 1] != 1) {
      printf("pop: %d\n", q.Pop());
    }
  }

  return 0;
}

// Class functions body
void quImpl::Push(int n) {
  if (start <= 10) {
    arr[start++] = n;
  }
}

int quImpl::Pop() {
  if (start == end)
    return -1;

  return arr[end++];
}
