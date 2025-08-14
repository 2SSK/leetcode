// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string s);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  string pattern;
  cin >> pattern;
  cin.ignore();

  string input;
  getline(cin, input);

  cout << "Output: " << boolalpha << solution.wordPattern(pattern, input)
       << endl;

  return 0;
}

bool Solution::wordPattern(string pattern, string s) {
  istringstream iss(s);
  vector<string> words;
  string word;

  while (iss >> word) {
    words.push_back(word);
  }

  if (pattern.size() != words.size())
    return false;

  unordered_map<char, string> char_to_word;
  unordered_map<string, char> word_to_char;

  for (int i = 0; i < pattern.size(); ++i) {
    char c = pattern[i];
    string w = words[i];

    if (char_to_word.count(c)) {
      if (char_to_word[c] != w) {
        return false;
      }
    } else {
      char_to_word[c] = w;
    }

    if (word_to_char.count(w)) {
      if (word_to_char[w] != c) {
        return false;
      }
    } else {
      word_to_char[w] = c;
    }
  }

  return true;
}
