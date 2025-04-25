// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <ios>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool divideArray(vector<int> &nums);
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

  cout << "Output: " << boolalpha << s.divideArray(input) << endl;

  return 0;
}

bool Solution::divideArray(vector<int> &nums) {
  unordered_map<int, int> freq;

  for (auto num : nums) {
    freq[num]++;
  }

  for (auto it : freq) {
    if (it.second % 2 != 0) {
      return false;
    }
  }

  return true;
};
