// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals);

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
      if (i == n - 1) {
        cout << arr[i];
      } else {
        cout << arr[i] << " | ";
      }
    }
  }

  void printSuperArr(vector<vector<int>> superArr) {
    int n = superArr.size();

    cout << "[";
    for (int i = 0; i < n; i++) {
      cout << "[";
      printArr(superArr[i]);
      if (i == n - 1) {
        cout << "]";
      } else {
        cout << "] ";
      }
    }
    cout << "]";
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int size;
  cin >> size;
  cin.ignore();

  vector<vector<int>> intervals;
  for (int i = 0; i < size; i++) {
    vector<int> input = solution.readInput<int>();
    intervals.push_back(input);
  }

  vector<vector<int>> output = solution.merge(intervals);
  cout << "Output: ";
  solution.printSuperArr(output);

  return 0;
}

vector<vector<int>> Solution::merge(vector<vector<int>> &intervals) {
  vector<vector<int>> output;
  if (intervals.size() == 0)
    return output;

  sort(intervals.begin(), intervals.end());
  vector<int> tempInterval = intervals[0];

  for (auto it : intervals) {
    if (it[0] <= tempInterval[1]) {
      tempInterval[1] = max(it[1], tempInterval[1]);
    } else {
      output.push_back(tempInterval);
      tempInterval = it;
    }
  }

  output.push_back(tempInterval);

  return output;
};
