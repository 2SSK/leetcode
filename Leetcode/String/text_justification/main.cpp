// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int getTotalLength(vector<string> &words, int start, int end);

public:
  vector<string> fullJustify(vector<string> &words, int maxWidth);

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
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<string> input = solution.readInput<string>();
  int maxWidth = 0;
  cin >> maxWidth;

  vector<string> output = solution.fullJustify(input, maxWidth);
  cout << "Output: ";
  solution.printArr(output);

  return 0;
}

vector<string> Solution::fullJustify(vector<string> &words, int maxWidth) {
  vector<string> result;
  int i = 0, n = words.size();

  while (i < n) {
    int lineLen = words[i].length();
    int j = i + 1;

    while (j < n && lineLen + 1 + words[j].length() <= maxWidth) {
      lineLen += 1 + words[j].length();
      j++;
    }

    int spaces = maxWidth - getTotalLength(words, i, j);
    int numWords = j - i;

    string line;

    if (j == n || numWords == 1) {
      for (int k = i; k < j; ++k) {
        line += words[k];
        if (k != j - 1)
          line += ' ';
      }
      line += string(maxWidth - line.length(), ' ');
    } else {
      int spaceBetween = spaces / (numWords - 1);
      int extra = spaces % (numWords - 1);

      for (int k = i; k < j; ++k) {
        line += words[k];
        if (k != j - 1) {
          int spaceCount = spaceBetween + (k - i < extra ? 1 : 0);
          line += string(spaceCount, ' ');
        }
      }
    }

    result.push_back(line);
    i = j;
  }

  return result;
};

int Solution::getTotalLength(vector<string> &words, int start, int end) {
  int total = 0;

  for (int i = start; i < end; ++i) {
    total += words[i].length();
  }

  return total;
};
