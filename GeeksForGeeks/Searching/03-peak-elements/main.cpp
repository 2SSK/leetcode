#include <bits/stdc++.h>
#include <ios>
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
};

int peakElement(vector<int> &arr) {
  for (int i = 1; i < arr.size() - 1; i++) {
    if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
      return true;
    }
  }

  return 0;
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
    vector<int> input = solution.readInput<int>();
    cout << "Output: " << boolalpha << static_cast<bool>(peakElement(input))
         << endl;
  }

  return 0;
}
