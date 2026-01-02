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

int maxSubarraySum(vector<int> &arr) {
  int res = arr[0];

  int maxEnding = arr[0];

  for (int i = 1; i < arr.size(); i++) {
    maxEnding = max(arr[i], maxEnding + arr[i]);
    res = max(res, maxEnding);
  }

  return res;
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  cout << "Output: " << maxSubarraySum(input) << endl;

  return 0;
}
