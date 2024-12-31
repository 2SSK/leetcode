// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class solution {
public:
  void greet(string name) { cout << "Hello, " << name << "!\n"; }
};

int main() {
  solution s;

  string name;
  cin >> name;

  s.greet(name);

  return 0;
}
