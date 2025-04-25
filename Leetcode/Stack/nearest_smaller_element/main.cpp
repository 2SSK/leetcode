// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> prevSmaller(vector<int> &A);
};

void printArr(vector<int> &arr, int arr_size);

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution s;

  int arr_size;
  cin >> arr_size;

  vector<int> arr(arr_size);
  for (size_t i{}; i < arr_size; i++) {
    cin >> arr[i];
  }

  cout << "Array : ";
  printArr(arr, arr_size);

  vector<int> nearset_smaller_elements_arr = s.prevSmaller(arr);
  cout << "\nOutput : ";
  printArr(nearset_smaller_elements_arr, arr_size);

  return 0;
}

// Function body : prevSmaller()
vector<int> Solution::prevSmaller(vector<int> &A) {
  int arr_size = A.size();
  vector<int> ans(arr_size, -1); // Set default value to -1
  stack<int> st;

  for (size_t i{}; i < arr_size; i++) {
    while (!st.empty() && st.top() >= A[i]) {
      st.pop();
    }

    if (!st.empty()) {
      ans[i] = st.top();
    }

    st.push(A[i]);
  }

  return ans;
}

void printArr(vector<int> &arr, int arr_size) {
  cout << "[";
  for (size_t i{}; i < arr_size;) {
    if (i != arr_size - 1)
      cout << arr[i++] << ", ";
    else
      cout << arr[i++] << "]\n";
  }
}
