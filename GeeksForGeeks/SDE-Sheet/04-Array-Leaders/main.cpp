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
        cout << "[ " << arr[i] << " , ";
      } else if (i == n - 1) {
        cout << arr[i] << " ]\n";
      } else {
        cout << arr[i] << " , ";
      }
    }
  }
};

vector<int> leaders(vector<int> &arr) {
  vector<int> result;

  int rightMax = INT_MIN;

  for (int i = arr.size() - 1; i >= 0; i--) {
    if (arr[i] >= rightMax) {
      result.push_back(arr[i]);
      rightMax = arr[i];
    }
  }

  reverse(result.begin(), result.end());

  return result;
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

    vector<int> output = leaders(arr);
    cout << "Output: ";
    solution.printArr(output);
  }

  return 0;
}
