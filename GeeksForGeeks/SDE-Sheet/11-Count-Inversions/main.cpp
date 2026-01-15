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

  int countAndMerge(vector<int> &arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; i++) {
      left[i] = arr[i + low];
    }

    for (int i = 0; i < n2; i++) {
      right[i] = arr[mid + 1 + i];
    }

    int res = 0;
    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
      if (left[i] <= right[j]) {
        arr[k++] = left[i++];
      } else {
        arr[k++] = right[j++];
        res += (n1 - i);
      }
    }

    while (i < n1) {
      arr[k++] = left[i++];
    }

    while (j < n2) {
      arr[k++] = right[j++];
    }

    return res;
  }

  int countInv(vector<int> &arr, int low, int high) {
    int res = 0;

    if (low < high) {
      int mid = (high + low) / 2;

      res += countInv(arr, low, mid);
      res += countInv(arr, mid + 1, high);

      res += countAndMerge(arr, low, mid, high);
    }

    return res;
  }

  int inversionCount(vector<int> &arr) {
    int n = arr.size();

    return countInv(arr, 0, n - 1);
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
    cout << "Output: " << solution.inversionCount(arr) << endl;
  }

  return 0;
}
