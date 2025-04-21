// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval);
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
        cout << arr[i] << " ] ";
      } else {
        cout << arr[i] << " | ";
      }
    }
  }

  void printSuperArr(vector<vector<int>> arr) {
    int n = arr.size();
    cout << "[ ";
    for (int i{}; i < n; i++) {
      printArr(arr[i]);
    }
    cout << " ]";
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;
  int intervalSize;
  cin >> intervalSize;
  cin.ignore();

  vector<vector<int>> intervals;

  for (int i = 0; i < intervalSize; i++) {
    vector<int> input = solution.readInput<int>();
    intervals.push_back(input);
  }

  vector<int> newInterval = solution.readInput<int>();

  vector<vector<int>> output = solution.insert(intervals, newInterval);
  cout << "Output: ";
  solution.printSuperArr(output);

  return 0;
}

vector<vector<int>> Solution::insert(vector<vector<int>> &intervals,
                                     vector<int> &newInterval) {
  int n = intervals.size();
  vector<vector<int>> output;
  int i = 0;

  while (i < n && intervals[i][1] < newInterval[0]) {
    output.push_back(intervals[i]);
    i++;
  }

  while (i < n && intervals[i][0] <= newInterval[1]) {
    newInterval = {min(newInterval[0], intervals[i][0]),
                   max(newInterval[1], intervals[i][1])};
    i++;
  }
  output.push_back(newInterval);

  while (i < n) {
    output.push_back(intervals[i]);
    i++;
  }

  return output;
};
