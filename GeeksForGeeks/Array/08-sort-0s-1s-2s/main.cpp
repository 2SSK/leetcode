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

void sort012(vector<int> &arr) {
  int n = arr.size();

  int lo = 0;
  int hi = n - 1;
  int mid = 0;

  while (mid <= hi) {
    if (arr[mid] == 0) {
      swap(arr[lo++], arr[mid++]);
    } else if (arr[mid] == 1) {
      mid++;
    } else {
      swap(arr[mid], arr[hi--]);
    }
  }
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  sort012(input);
  cout << "Output: ";
  solution.printArr(input);

  return 0;
}
