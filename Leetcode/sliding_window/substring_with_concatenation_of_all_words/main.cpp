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
        cout << "[ " << arr[i] << " | ";
      } else if (i == n - 1) {
        cout << arr[i] << " ]\n";
      } else {
        cout << arr[i] << " | ";
      }
    }
  }

  vector<int> findSubstring(string s, vector<string> &words);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  string s;
  cin >> s;
  cin.ignore();

  vector<string> words = solution.readInput<string>();

  vector<int> result = solution.findSubstring(s, words);

  cout << "Output: ";
  solution.printArr(result);

  return 0;
}

vector<int> Solution::findSubstring(string s, vector<string> &words) {
  vector<int> result;
  if (s.empty() || words.empty())
    return result;

  int word_len = words[0].length();
  int num_words = words.size();
  int total_len = word_len * num_words;

  if (s.length() < total_len)
    return result;

  unordered_map<string, int> word_count;
  for (const auto &word : words) {
    word_count[word]++;
  }

  for (int i = 0; i < word_len; ++i) {
    int left = i;
    unordered_map<string, int> seen;
    int count = 0;

    for (int j = i; j <= (int)s.length() - word_len; j += word_len) {
      string curr_word = s.substr(j, word_len);
      if (word_count.find(curr_word) != word_count.end()) {
        seen[curr_word]++;
        count++;

        while (seen[curr_word] > word_count[curr_word]) {
          string left_word = s.substr(left, word_len);
          seen[left_word]--;
          count--;
          left += word_len;
        }

        if (count == num_words) {
          result.push_back(left);
          string left_word = s.substr(left, word_len);
          seen[left_word]--;
          count--;
          left += word_len;
        }
      } else {
        seen.clear();
        count = 0;
        left = j + word_len;
      }
    }
  }

  return result;
};
