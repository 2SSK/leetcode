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

vector<int> findDuplicates(vector<int> &arr) {
  vector<int> res;

  for (int i = 0; i < arr.size(); i++) {
    int idx = abs(arr[i]) - 1;

    if (arr[idx] > 0) {
      arr[idx] = -arr[idx];
    } else {
      res.push_back(abs(arr[i]));
    }
  }

  return res;
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  vector<int> output = findDuplicates(input);
  cout << "Output: ";
  solution.printArr(output);

  return 0;
}
