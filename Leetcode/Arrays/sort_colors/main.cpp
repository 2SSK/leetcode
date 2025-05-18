// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

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
        cout << "| " << arr[i] << " | ";
      } else if (i == n - 1) {
        cout << arr[i] << " |\n";
      } else {
        cout << arr[i] << " | ";
      }
    }
  }

  void sortColors(vector<int> &nums);

  void mergeSort(vector<int> &nums, int left, int right);

  void merge(vector<int> &nums, int left, int mid, int right);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  solution.sortColors(input);

  cout << "Output: ";
  solution.printArr(input);

  return 0;
}

void Solution::sortColors(vector<int> &nums) {
  int n = nums.size();
  if (n <= 1) {
    return;
  }

  mergeSort(nums, 0, n - 1);
};

void Solution::mergeSort(vector<int> &arr, int left, int right) {
  if (left >= right) {
    return;
  }

  int mid = left + (right - left) / 2;

  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);

  merge(arr, left, mid, right);
};

void Solution::merge(vector<int> &arr, int left, int mid, int right) {
  vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
  vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

  int size_of_L = L.size();
  int size_of_R = R.size();

  int i = 0;
  int j = 0;
  int k = left;

  while (i < size_of_L && j < size_of_R) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < size_of_L) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < size_of_R) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
