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
        cout << "[ " << arr[i] << ", ";
      } else if (i == n - 1) {
        cout << arr[i] << " ]\n";
      } else {
        cout << arr[i] << ", ";
      }
    }
  }

  int minJumpsRecur(int i, vector<int> &arr) {
    if (i > arr.size() - 1)
      return 0;

    int ans = INT_MAX;

    for (int j = i + 1; j <= i + arr[i]; j++) {
      int val = minJumpsRecur(j, arr);
      if (val != INT_MAX) {
        ans = min(ans, 1 + val);
      }
    }

    return ans;
  }

  int minJumps(vector<int> &arr) {
    int ans = minJumpsRecur(0, arr);

    return (ans == INT_MAX) ? -1 : ans;
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int test_cases;
  cin >> test_cases;
  cin.ignore();

  while (test_cases--) {
    vector<int> arr = solution.readInput<int>();
    cout << "Output: " << solution.minJumps(arr) << endl;
  }

  return 0;
}
