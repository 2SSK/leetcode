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

int findEquilibrium(vector<int> &arr) {
  int prefSum = 0, total = 0;

  for (int ele : arr) {
    total += ele;
  }

  for (int i = 0; i < arr.size(); i++) {
    int suffSum = total - prefSum - arr[i];

    if (prefSum == suffSum) {
      return i;
    }

    prefSum += arr[i];
  }

  return -1;
}

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
    cout << "Output: " << findEquilibrium(arr) << endl;
  }

  return 0;
}
