// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  void addAtBack(ListNode *&head, int data);
  void printLL(ListNode *head);
  ListNode *llMiddle(ListNode *head);
  ListNode *reverseLL(ListNode *head);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Sbject of `solution` class
  Solution s;

  // Input data size
  int listSize;
  cin >> listSize;

  // Store the inputs in an Linked list
  ListNode *ll = nullptr;
  for (int i{}; i < listSize; i++) {
    int input;
    cin >> input;
    s.addAtBack(ll, input);
  }

  // Print the Linked list
  cout << "Linked List : ";
  s.printLL(ll);

  cout << "Max Pair Sum : " << s.pairSum(ll) << "\n";

  return 0;
}

void Solution::addAtBack(ListNode *&head, int data) {
  ListNode *newNode = new ListNode(data);

  if (head == nullptr) {
    head = newNode;
    return;
  }

  ListNode *temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }

  temp->next = newNode;
};

void Solution::printLL(ListNode *head) {
  ListNode *temp = head;

  while (temp != nullptr) {
    cout << temp->val;
    if (temp->next != nullptr) {
      cout << "->";
    }
    temp = temp->next;
  }
  cout << "\n";
}

ListNode *Solution::llMiddle(ListNode *head) {
  if (head == nullptr)
    return nullptr;

  ListNode *slow = head;
  ListNode *fast = head;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

ListNode *Solution::reverseLL(ListNode *head) {
  ListNode *prev = nullptr;
  ListNode *curr = head;

  while (curr != nullptr) {
    ListNode *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}
