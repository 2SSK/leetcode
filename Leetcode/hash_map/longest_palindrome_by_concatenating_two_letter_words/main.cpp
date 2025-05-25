// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <algorithm>
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

  int longestPalindrome(vector<string> &words);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<string> input = solution.readInput<string>();

  int output = solution.longestPalindrome(input);
  cout << "Output: " << output << endl;

  return 0;
}

int Solution::longestPalindrome(vector<string> &words) {
  unordered_map<string, int> mpp;

  int ans = 0;

  for (const auto &word : words) {
    string reversed_word = string({word[1], word[0]});

    if (mpp[reversed_word] > 0) {
      ans += 4;
      mpp[reversed_word]--;
    } else {
      mpp[word]++;
    }
  }

  // check equal character words (Use only once)
  for (const auto &it : mpp) {
    string word = it.first;
    int count = it.second;

    if (word[0] == word[1] && count > 0) {
      ans += 2;
      break;
    }
  }

  return ans;
};
