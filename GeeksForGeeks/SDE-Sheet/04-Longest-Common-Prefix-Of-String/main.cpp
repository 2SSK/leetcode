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
};

string longestCommonPrefix(vector<string> arr) {
  int n = arr.size();

  if (n == 1)
    return arr[0];

  string prefix = "";
  bool include;

  for (int i = 0; i < arr[0].length(); i++) {
    include = true;

    for (int j = 1; j < n; ++j) {
      if (i >= arr[j].length() || arr[0][i] != arr[j][i]) {
        include = false;
        break;
      }
    }

    if (!include) {
      break;
    }

    prefix += arr[0][i];
  }

  return prefix;
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
    vector<string> arr = solution.readInput<string>();
    cout << "Output: \"" << longestCommonPrefix(arr) << "\"" << endl;
  }

  return 0;
}
