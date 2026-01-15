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

  int maxLength(vector<int> &arr) {
    int maxLen = 0;
    int sum = 0;
    unordered_map<int, int> prefixIndex;

    for (int i = 0; i < arr.size(); i++) {
      sum += arr[i];

      if (sum == 0) {
        maxLen = i + 1;
      }

      if (prefixIndex.find(sum) != prefixIndex.end()) {
        maxLen = max(maxLen, i - prefixIndex[sum]);
      } else {
        prefixIndex[sum] = i;
      }
    }

    return maxLen;
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
    cout << "Output: " << solution.maxLength(arr) << endl;
  }

  return 0;
}
