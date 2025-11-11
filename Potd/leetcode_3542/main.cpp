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

  int minOperations(vector<int> &nums);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  cout << "Output: " << solution.minOperations(input) << endl;

  return 0;
}

int Solution::minOperations(vector<int> &nums) {
  int ans = 0;
  stack<int> st;
  st.push(0);

  for (int num : nums) {
    while (!st.empty() && st.top() > num) {
      st.pop();
    }
    if (st.empty() || st.top() < num) {
      ++ans;
      st.push(num);
    }
  }

  return ans;
}
