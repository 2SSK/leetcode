// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class solution {
public:
  // Brute force solution
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ans(nums1.size(), -1);

    for (int i{}; i < nums1.size(); i++) {
      int idx = find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
      for (int j{idx}; j < nums2.size(); j++) {
        if (nums2[j] == nums1[i]) {
          continue;
        } else if (nums2[j] > nums1[i]) {
          ans[i] = nums2[j];
          break;
        }
      }
    }

    return ans;
  }
};

// Read array inputs at once
vector<int> readInput() {
  string inputStr;
  getline(cin, inputStr);
  stringstream ss(inputStr);
  vector<int> nums;
  int num;

  while (ss >> num) {
    nums.push_back(num);
  }

  return nums;
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solution s;

  vector<int> nums1 = readInput();
  vector<int> nums2 = readInput();

  vector<int> ans = s.nextGreaterElement(nums1, nums2);
  for (auto &x : ans) {
    cout << x << " ";
  }

  return 0;
}
