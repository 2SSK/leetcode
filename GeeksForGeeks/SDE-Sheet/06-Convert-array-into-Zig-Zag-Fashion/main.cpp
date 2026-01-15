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

void zigZag(vector<int> &arr) {
  for (int i = 0; i < arr.size() - 1; i++) {
    if ((i % 2 == 0 && arr[i] > arr[i + 1]) ||
        (i % 2 != 0 && arr[i] < arr[i + 1])) {
      swap(arr[i], arr[i + 1]);
    }
  }
}

bool isZigZag(vector<int> &arr) {

  for (int i = 1; i < arr.size() - 1; i++) {
    if ((i % 2 == 0 && arr[i] > arr[i + 1]) ||
        (i % 2 != 0 && arr[i] < arr[i + 1])) {
      return false;
    }
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
    vector<int> arr = solution.readInput<int>();

    zigZag(arr);
    cout << "Output: " << boolalpha << isZigZag(arr) << endl;
  }

  return 0;
}
