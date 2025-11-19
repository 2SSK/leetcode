#include <bits/stdc++.h>
using namespace std;

class Solution {
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

  bool kLengthApart(vector<int> &nums, int k);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  int k;
  cin >> k;

  cout << "Output: " << boolalpha << solution.kLengthApart(input, k) << "\n";

  return 0;
}

bool Solution::kLengthApart(vector<int> &nums, int k) {
  int last = -1;

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 1) {
      if (last == -1) {
        last = i;
      } else {
        if ((i - last - 1) < k) {
          return false;
        }
        last = i;
      }
    }
  }

  return true;
}
