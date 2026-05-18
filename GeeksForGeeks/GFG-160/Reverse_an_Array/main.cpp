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
    if (n > 1) {
      for (int i = 0; i < n; i++) {
        if (i == 0) {
          cout << "[ " << arr[i] << ", ";
        } else if (i == n - 1) {
          cout << arr[i] << " ]\n";
        } else {
          cout << arr[i] << ", ";
        }
      }
    } else {
      cout << "[ " << arr[0] << " ]";
    }
  }

  void reverseArray(vector<int> &arr) {
    int s = 0;
    int e = arr.size() - 1;

    while (s <= e) {
      swap(arr[s++], arr[e--]);
    }
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
    solution.reverseArray(arr);
    cout << "Output: ";
    solution.printArr(arr);
  }

  return 0;
}
