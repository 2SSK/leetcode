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

  vector<int> findTwoElement(vector<int> &arr) {
    int n = arr.size();
    int repeating{-1}, missing{-1};

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 1; i++) {
      if (arr[i] == arr[i + 1]) {
        repeating = arr[i];
      } else if (arr[i + 1] != arr[i] + 1) {
        missing = arr[i] + 1;
      }
    }

    if (arr[0] != 1) {
      missing = 1;
    } else if (arr[n - 1] != n) {
      missing = n;
    }

    return {repeating, missing};
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

    vector<int> output = solution.findTwoElement(arr);
    cout << "Output: ";
    solution.printArr(output);
  }

  return 0;
}
