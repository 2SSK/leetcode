// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  template <typename T> void printArr(vector<T> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        cout << "| " << arr[i] << " | ";
      } else if (i == n - 1) {
        cout << arr[i] << " |\n";
      } else {
        cout << arr[i] << " | ";
      }
    }
  }

  vector<int> minPartition(int N);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int N;
  cin >> N;

  vector<int> output = solution.minPartition(N);
  cout << "Output : ";
  solution.printArr(output);

  return 0;
}

vector<int> Solution::minPartition(int N) {
  vector<int> output;

  vector<int> currency{2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

  for (int i = 0; i < currency.size(); i++) {
    while (N >= currency[i]) {
      N -= currency[i];
      output.push_back(currency[i]);
    }
  }

  return output;
};
