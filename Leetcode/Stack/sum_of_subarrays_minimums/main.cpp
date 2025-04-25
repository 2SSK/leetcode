// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

class Solution {
private:
  const int mod = 1e9 + 7;

public:
  // BruteForce Approach
  int sumSubarrayMins(vector<int> &arr);

  // Optimal Approach
  int optimal_sumSubarrayMins(vector<int> &arr);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution s;

  int size;
  cin >> size;

  vector<int> arr(size);
  for (int i{}; i < size; i++) {
    cin >> arr[i];
  }

  int min_subArr_sum = s.sumSubarrayMins(arr);
  cout << "output : " << min_subArr_sum << "\n";

  return 0;
}

int Solution::optimal_sumSubarrayMins(vector<int> &arr) {
  int n = arr.size();
  int sum{};
  stack<int> st;
  vector<int> left(n), right(n);

  for (int i{}; i < n; i++) {
    while (!st.empty() && arr[st.top()] > arr[i]) {
      st.pop();
    }
    left[i] = st.empty() ? i + 1 : i - st.top();
    st.push(i);
  }

  while (!st.empty()) {
    st.pop();
  }

  for (int i{n - 1}; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] >= arr[i]) {
      st.pop();
    }
    right[i] = st.empty() ? n - i : st.top() - i;
    st.push(i);
  }

  for (int i{}; i < n; i++) {
    sum = (sum + (long long)arr[i] * left[i] * right[i]) % mod;
  }

  return sum;
};

int Solution::sumSubarrayMins(vector<int> &arr) {
  int n = arr.size();
  int sum{};

  for (int i{}; i < n; i++) {
    int mini = arr[i];
    for (int j{i}; j < n; j++) {
      mini = min(mini, arr[j]);
      sum = (sum + mini) % mod;
    }
  }

  return sum;
}
