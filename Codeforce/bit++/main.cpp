// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int output = 0;

  int n;
  cin >> n;
  cin.ignore();

  for (int i = 0; i < n; i++) {
    string input;
    getline(cin, input);

    if (input.find("++") != input.npos) {
      output++;
    } else {
      output--;
    }
  }

  cout << output << endl;

  return 0;
}
