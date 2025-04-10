// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <sstream>
using namespace std;

class Solution {
public:
  int candy(vector<int> &ratings);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> ratings;

  string input;
  getline(cin, input);
  stringstream ss(input);
  int value;
  while (ss >> value) {
    ratings.push_back(value);
  }

  cout << "Output: " << solution.candy(ratings);

  return 0;
}

int Solution::candy(vector<int> &ratings) {
  int n = ratings.size();

  vector<int> left(n, 1);
  vector<int> right(n, 1);

  for (int i = 1; i < n; i++) {
    if (ratings[i] > ratings[i - 1]) {
      left[i] = left[i - 1] + 1;
    }
  }

  for (int i = n - 2; i >= 0; i--) {
    if (ratings[i] > ratings[i + 1]) {
      right[i] = right[i + 1] + 1;
    }
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += max(left[i], right[i]);
  }
  return sum;
};
