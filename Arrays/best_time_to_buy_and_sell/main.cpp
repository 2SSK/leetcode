// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &arr);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution s;

  int size;
  cin >> size;

  vector<int> input(size);
  for (int i{}; i < size; i++) {
    cin >> input[i];
  }

  cout << "\nOutput: " << s.maxProfit(input);

  return 0;
}

int Solution::maxProfit(vector<int> &arr) {
  int size = arr.size();
  int profit{};

  for (int i{1}; i < size; i++) {
    profit += (arr[i] > arr[i - 1]) ? (arr[i] - arr[i - 1]) : 0;
  }

  return profit;
}
