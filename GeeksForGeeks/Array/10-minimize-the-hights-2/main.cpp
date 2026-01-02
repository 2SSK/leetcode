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
};

int getMinDiff(vector<int> &arr, int k) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  int res = arr[n - 1] - arr[0];

  for (int i = 1; i < n; i++) {
    if (arr[i] - k < 0) {
      continue;
    }

    int minH = min(arr[0] + k, arr[i] - k);
    int maxH = max(arr[i - 1] + k, arr[n - 1] - k);
    res = min(res, maxH - minH);
  }

  return res;
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int test_case;
  cin >> test_case;
  cin.ignore();

  while (test_case--) {
    int k;
    cin >> k;
    cin.ignore();
    vector<int> input = solution.readInput<int>();
    cout << "Output: " << getMinDiff(input, k) << endl;
  }

  return 0;
}
