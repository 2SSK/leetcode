// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals);
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

  cout << "Output: " << solution.eraseOverlapIntervals(intervals) << endl;

  return 0;
}

int Solution::eraseOverlapIntervals(vector<vector<int>> &intervals) {
  if (intervals.empty())
    return 0;

  // Sort by end time (greedy)
  sort(intervals.begin(), intervals.end(),
       [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

  int count = 0;
  int last_end_time = intervals[0][1];

  for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i][0] < last_end_time) {
      // Overlapping interval → remove
      count++;
    } else {
      // No overlap → keep it and update last_end_time
      last_end_time = intervals[i][1];
    }
  }

  return count;
}
