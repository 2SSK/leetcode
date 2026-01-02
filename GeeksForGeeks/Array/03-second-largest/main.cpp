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
};

int getSecondLargest(vector<int> &arr) {
  int largest = arr[0];
  int secondLargest = arr[0];

  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] > largest) {
      largest = arr[i];
    }

    if (arr[i] > secondLargest && arr[i] < largest) {
      secondLargest = arr[i];
    }
  }

  return secondLargest;
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  cout << "Output: " << getSecondLargest(input);

  return 0;
}
