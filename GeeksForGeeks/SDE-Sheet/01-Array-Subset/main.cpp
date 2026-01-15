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
bool isSubset(vector<int> &a, vector<int> &b) {
  multiset<int> hashSet(a.begin(), a.end());

  for (int num : b) {
    if (hashSet.find(num) == hashSet.end()) {
      return false;
    }
    hashSet.erase(hashSet.find(num));
  }

  return true;
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
    vector<int> a = solution.readInput<int>();
    vector<int> b = solution.readInput<int>();

    cout << "Output: " << boolalpha << isSubset(a, b) << endl;
  }

  return 0;
}
