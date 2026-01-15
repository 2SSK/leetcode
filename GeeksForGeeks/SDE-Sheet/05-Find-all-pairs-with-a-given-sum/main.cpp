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

  template <typename T> void printPair(vector<pair<T, T>> arr) {
    int n = arr.size();
    cout << "[";
    for (int i = 0; i < n; i++) {
      cout << "(" << arr[i].first << ", " << arr[i].second << ")";
      if (i < n - 1) {
        cout << ", ";
      }
    }
    cout << "]\n";
  }
};

vector<pair<int, int>> allPairs(int target, vector<int> &arr1,
                                vector<int> &arr2) {
  vector<pair<int, int>> result;

  unordered_map<int, int> freqArr2;
  for (int num : arr2) {
    freqArr2[num]++;
  }

  for (int u : arr1) {
    int diff = target - u;
    if (freqArr2.count(diff)) {
      int count = freqArr2[diff];
      for (int i = 0; i < count; i++) {
        result.push_back({u, diff});
      }
    }
  }

  sort(result.begin(), result.end());

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
    int target;
    cin >> target;
    cin.ignore();

    vector<int> a = solution.readInput<int>();
    vector<int> b = solution.readInput<int>();

    vector<pair<int, int>> output = allPairs(target, a, b);
    cout << "Output: ";
    solution.printPair(output);
  }

  return 0;
}
