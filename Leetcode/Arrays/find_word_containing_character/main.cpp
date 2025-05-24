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

  vector<int> findWordsContaining(vector<string> &words, char x);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  char x;
  cin >> x;
  cin.ignore();

  vector<string> input = solution.readInput<string>();

  vector<int> output = solution.findWordsContaining(input, x);

  cout << "Output: ";
  solution.printArr(output);

  return 0;
}

vector<int> Solution::findWordsContaining(vector<string> &words, char x) {
  vector<int> result;

  for (size_t i = 0; i < words.size(); i++) {
    string word = words[i];
    if (find(word.begin(), word.end(), x) != word.end()) {
      result.push_back(i);
    }
  }

  return result;
};
