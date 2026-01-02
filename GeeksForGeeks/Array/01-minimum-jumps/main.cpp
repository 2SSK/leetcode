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

  int minJumps(vector<int> &arr);
  int minJumpsRecur(int i, vector<int> &arr);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  cout << "Output: " << solution.minJumps(input);

  return 0;
}

int Solution::minJumpsRecur(int i, vector<int> &arr) {
  if (i >= arr.size() - 1)
    return 0;

  int ans = INT_MAX;

  for (int j = i + 1; j <= i + arr[i]; j++) {
    int val = minJumpsRecur(j, arr);
    if (val != INT_MAX) {
      ans = min(ans, 1 + val);
    }
  }

  return ans;
}

int Solution::minJumps(vector<int> &arr) {
  int ans = minJumpsRecur(0, arr);

  if (ans == INT_MAX)
    return -1;

  return ans;
}
