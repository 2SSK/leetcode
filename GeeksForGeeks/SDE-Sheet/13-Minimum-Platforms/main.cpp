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

  int minPlatform(vector<int> &arr, vector<int> &dep) {
    int n = arr.size();

    int platforms = 0;
    int maxPlatforms = 0;

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0, j = 0;

    while (i < n) {
      if (arr[i] <= dep[j]) {
        platforms++;
        i++;
        maxPlatforms = max(maxPlatforms, platforms);
      } else {
        platforms--;
        j++;
      }
    }

    return maxPlatforms;
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
    vector<int> arr1 = solution.readInput<int>();
    vector<int> arr2 = solution.readInput<int>();
    cout << "Output: " << solution.minPlatform(arr1, arr2) << endl;
  }

  return 0;
}
