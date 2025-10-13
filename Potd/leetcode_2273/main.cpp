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

  vector<string> removeAnagrams(vector<string> &words);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<string> input = solution.readInput<string>();

  vector<string> output = solution.removeAnagrams(input);

  cout << "Output: ";
  solution.printArr(output);

  return 0;
}

vector<string> Solution::removeAnagrams(vector<string> &words) {
  vector<string> ans;

  if (words.empty())
    return ans;

  ans.push_back(words[0]);

  for (int i = 1; i < words.size(); i++) {
    string prev = ans.back();
    string curr = words[i];

    string sortedPrev = prev, sortedCurr = curr;
    sort(sortedPrev.begin(), sortedPrev.end());
    sort(sortedCurr.begin(), sortedCurr.end());

    if (sortedPrev != sortedCurr) {
      ans.push_back(curr);
    }
  }

  return ans;
}
