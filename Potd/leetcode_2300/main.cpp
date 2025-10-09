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

  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> spells = solution.readInput<int>();
  vector<int> potions = solution.readInput<int>();

  long long success;
  cin >> success;

  vector<int> output = solution.successfulPairs(spells, potions, success);

  cout << "Output: ";
  solution.printArr(output);

  return 0;
}

vector<int> Solution::successfulPairs(vector<int> &spells, vector<int> &potions,
                                      long long success) {
  sort(potions.begin(), potions.end());
  vector<int> result;

  for (int spell : spells) {
    long long minPotion = (success + spell - 1) / spell;
    int idx = lower_bound(potions.begin(), potions.end(), minPotion) -
              potions.begin();
    result.push_back(potions.size() - idx);
  }

  return result;
}
