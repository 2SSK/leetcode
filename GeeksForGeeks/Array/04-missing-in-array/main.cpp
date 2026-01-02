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
};

int missingNum(vector<int> &nums) {
  int n = nums.size() + 1;

  int totalSum = n * (n + 1) / 2;
  int arrSum = 0;

  for (const auto &it : nums) {
    arrSum += it;
  }

  int diff = abs(totalSum - arrSum);

  return (diff == 0) ? n + 1 : diff;
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  cout << "Output: " << missingNum(input);

  return 0;
}
