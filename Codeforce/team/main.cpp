// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <cstdlib>
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
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int n;
  cin >> n;
  cin.ignore();

  int output = 0;

  for (int i = 0; i < n; i++) {
    vector<int> input = solution.readInput<int>();
    if (input[0] == 1 && input[1] == 1 || input[0] == 1 && input[2] == 1 ||
        input[1] == 1 && input[2] == 1) {
      output++;
    }
  }

  cout << output << endl;

  return 0;
}
