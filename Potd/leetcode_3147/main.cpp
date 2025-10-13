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
  int maximumEnergy(vector<int> &energy, int k);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  int k;
  cin >> k;

  cout << "Output: " << solution.maximumEnergy(input, k);

  return 0;
}

int Solution::maximumEnergy(vector<int> &energy, int k) {
  int n = energy.size();
  int result = INT_MIN;

  for (int i = n - k; i < n; i++) {
    int sum = 0;
    for (int j = i; j >= 0; j -= k) {
      sum += energy[j];
      result = max(result, sum);
    }
  }

  return result;
}
