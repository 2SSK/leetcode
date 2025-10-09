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

  template <typename T> void printArr(vector<T> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        cout << "[ " << arr[i] << " | ";
      } else if (i == n - 1) {
        cout << arr[i] << " ]\n";
      } else {
        cout << arr[i] << " | ";
      }
    }
  }

  long long minTime(vector<int> &skill, vector<int> &mana);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> skill = solution.readInput<int>();
  vector<int> mana = solution.readInput<int>();

  cout << "Output: " << solution.minTime(skill, mana) << "\n";

  return 0;
}

long long Solution::minTime(vector<int> &skill, vector<int> &mana) {
  int n = skill.size();
  int m = mana.size();

  vector<long long> prefix_skill(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    prefix_skill[i] = prefix_skill[i - 1] + skill[i - 1];
  }

  long long portion_start_time = 0;

  for (int j = 0; j < m - 1; j++) {
    long long max_diff = LLONG_MIN;

    for (int i = 1; i <= n; i++) {
      long long current_diff = (long long)mana[j] * prefix_skill[i] -
                               (long long)mana[j + 1] * prefix_skill[i - 1];

      max_diff = max(max_diff, current_diff);
    }

    portion_start_time += max_diff;
  }

  return portion_start_time + (long long)mana[m - 1] * prefix_skill[n];
}
