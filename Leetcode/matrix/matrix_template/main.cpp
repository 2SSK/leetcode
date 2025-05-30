// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Utils {
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

  template <typename T> void printArr(vector<vector<T>> arr) {
    cout << "\n";
    for (const auto &row : arr) {
      printArr(row);
    }
  }
};

class Solution : public Utils {
public:
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int n;
  cin >> n;
  cin.ignore();

  vector<vector<int>> inputArr;
  while (n--) {
    vector<int> input = solution.readInput<int>();
    inputArr.push_back(input);
  }

  cout << "Matrix: ";
  solution.printArr(inputArr);

  return 0;
}
