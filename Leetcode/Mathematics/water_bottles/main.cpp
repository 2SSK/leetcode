#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int numBottles, numExchange;
  cin >> numBottles >> numExchange;

  cout << "Ouput: " << solution.numWaterBottles(numBottles, numExchange);

  return 0;
}

int Solution::numWaterBottles(int numBottles, int numExchange) {
  int num_of_bottles_drunk = numBottles;
  int empty_bottles = numBottles;

  while (empty_bottles >= numExchange) {
    int new_bottles = empty_bottles / numExchange;
    num_of_bottles_drunk += new_bottles;
    empty_bottles = empty_bottles % numExchange + new_bottles;
  }

  return num_of_bottles_drunk;
}
