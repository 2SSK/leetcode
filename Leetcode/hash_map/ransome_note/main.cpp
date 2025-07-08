// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <ios>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
  if (ransomNote.size() > magazine.size()) {
    return false;
  }

  unordered_map<char, int> charCount;

  for (char c : magazine) {
    charCount[c]++;
  }

  for (char c : ransomNote) {
    if (charCount[c] > 0) {
      charCount[c]--;
    } else {
      return false;
    }
  }

  return true;
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string ransome_note, magazine;
  cin >> ransome_note >> magazine;

  cout << "Output: " << boolalpha << canConstruct(ransome_note, magazine)
       << endl;

  return 0;
}
