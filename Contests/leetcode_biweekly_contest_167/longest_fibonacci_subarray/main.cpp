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

  int longestSubarray(vector<int> &nums) {
    if (nums.size() < 3)
      return nums.size();

    int maxLen = 2;
    int currLen = 2;

    for (int i = 2; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1] + nums[i - 2]) {
        currLen++;
        maxLen = max(maxLen, currLen);
      } else {
        currLen = 2;
      }
    }

    return maxLen;
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  cout << solution.longestSubarray(input) << endl;

  return 0;
}
