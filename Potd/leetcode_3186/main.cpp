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

  long long maximumTotalDamage(vector<int> &power);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  cout << "Output: " << solution.maximumTotalDamage(input) << endl;

  return 0;
}

long long Solution::maximumTotalDamage(vector<int> &power) {
  if (power.empty())
    return 0;

  int maxPower = *max_element(power.begin(), power.end());

  vector<long long> freq(maxPower + 1, 0);

  for (int x : power) {
    freq[x] += x;
  }

  vector<long long> dp(maxPower + 1, 0);
  dp[0] = freq[0];
  if (maxPower >= 1)
    dp[1] = max(freq[0], freq[1]);

  for (int i = 2; i <= maxPower; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + freq[i]);
  }

  return dp[maxPower];
}
