// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <functional>
using namespace std;

class Solution {
public:
  double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity);
};

vector<int> readInput() {
  vector<int> inputArr;
  string input;
  getline(cin, input);
  stringstream ss(input);
  int value;
  while (ss >> value) {
    inputArr.push_back(value);
  }

  return inputArr;
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> val = readInput();
  vector<int> wt = readInput();
  int capacity;
  cin >> capacity;

  cout << "Output: " << solution.fractionalKnapsack(val, wt, capacity);

  return 0;
}

double Solution::fractionalKnapsack(vector<int> &val, vector<int> &wt,
                                    int capacity) {
  int n = val.size();

  vector<pair<double, int>> items(n);

  for (int i = 0; i < n; i++) {
    if (wt[i] == 0)
      continue;
    double ratio = static_cast<double>(val[i] / wt[i]);
    items[i] = {ratio, i};
  }

  sort(begin(items), end(items), greater<pair<double, int>>());

  double totalValue = 0;
  double remainingCapacity = capacity;

  for (const auto &item : items) {
    int idx = item.second;
    if (remainingCapacity >= wt[idx]) {
      totalValue += val[idx];
      remainingCapacity -= wt[idx];
    } else {
      double fraction = remainingCapacity / static_cast<double>(wt[idx]);
      totalValue += val[idx] * fraction;
      remainingCapacity = 0;
      break;
    }
  }

  return totalValue;
};
