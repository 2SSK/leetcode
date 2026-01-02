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

int majorityElement(vector<int> &arr) {
  int candidate = -1;
  int count = 0;

  for (int num : arr) {
    if (count == 0) {
      candidate = num;
      count = 1;
    } else if (num == candidate) {
      count++;
    } else {
      count--;
    }
  }

  count = 0;
  for (int num : arr) {
    if (num == candidate) {
      count++;
    }
  }

  return (count > arr.size() / 2) ? candidate : -1;
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int t;
  cin >> t;
  cin.ignore();

  while (t--) {
    vector<int> input = solution.readInput<int>();
    cout << "Output: " << majorityElement(input) << endl;
  }

  return 0;
}
