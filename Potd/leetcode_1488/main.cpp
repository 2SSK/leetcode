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

  vector<int> avoidFlood(vector<int> &rains);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  vector<int> result = solution.avoidFlood(input);

  cout << "Output: ";
  solution.printArr(result);

  return 0;
}

vector<int> Solution::avoidFlood(vector<int> &rains) {
  int n = rains.size();
  vector<int> result(n, 1);
  map<int, int> full_lakes;
  set<int> sunny_days;

  for (int i = 0; i < n; ++i) {
    int lake = rains[i];
    if (lake == 0) {
      sunny_days.insert(i);
    } else {
      if (full_lakes.count(lake)) {
        auto it = sunny_days.upper_bound(full_lakes[lake]);
        if (it == sunny_days.end()) {
          return {};
        }
        result[*it] = lake;
        sunny_days.erase(it);
      }
      result[i] = -1;
      full_lakes[lake] = i;
    }
  }

  return result;
}
