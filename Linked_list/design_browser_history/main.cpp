// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *prev{nullptr};
  Node *next{nullptr};
  string url;

  Node(string url) : url(url) {}
};

class BrowserHistory {
private:
  Node *curr{nullptr};

public:
  BrowserHistory(string homepage) { curr = new Node(homepage); }

  void visit(const string &url) {
    curr->next = new Node(url);
    curr->next->prev = curr;
    curr = curr->next;
  }

  string back(int steps) {
    while (curr->prev && steps-- > 0) {
      curr = curr->prev;
    }
    return curr->url;
  }

  string forward(int steps) {
    while (curr->next && steps-- > 0) {
      curr = curr->next;
    }
    return curr->url;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int size;
  cin >> size;

  vector<string> operations(size);
  vector<string> urls;
  vector<int> steps;

  for (int i{}; i < size; i++) {
    cin >> operations[i];
  }

  for (int i{}; i < size; i++) {
    if (operations[i] == "back" || operations[i] == "forward") {
      int step;
      cin >> step;
      steps.push_back(step);
      urls.push_back("");
    } else {
      string url;
      cin >> url;
      urls.push_back(url);
      steps.push_back(0);
    }
  }

  BrowserHistory *bh{nullptr};
  int stepIndex{};

  for (int i{}; i < size; i++) {
    if (operations[i] == "BrowserHistory") {
      bh = new BrowserHistory(urls[i]);
      cout << "null ";
    } else if (operations[i] == "visit") {
      bh->visit(urls[i]);
      cout << "null ";
    } else if (operations[i] == "back") {
      cout << bh->back(steps[stepIndex]) << " ";
      stepIndex++;
    } else if (operations[i] == "forward") {
      cout << bh->forward(steps[stepIndex]) << " ";
      stepIndex++;
    }
  }

  return 0;
}
