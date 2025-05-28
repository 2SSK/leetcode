// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <sstream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedListOperations {
public:
  void addAtBack(ListNode *&head, int data);
  void printLL(ListNode *head);
  ListNode *llMiddle(ListNode *head);
  ListNode *reverseLL(ListNode *head);
};

class Solution : public LinkedListOperations {
public:
  ListNode *reverseList(ListNode *head);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Sbject of `solution` class
  Solution s;

  // Input data size
  string line;
  getline(cin, line);
  stringstream ss(line);

  // Store the inputs in an Linked list
  ListNode *ll = nullptr;
  int input;
  while (ss >> input) {
    s.addAtBack(ll, input);
  }

  // Print the Linked list
  ListNode *output = s.reverseList(ll);
  cout << "Output : ";
  s.printLL(output);

  return 0;
}

ListNode *Solution::reverseList(ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  ListNode *miniHead = reverseList(head->next);

  head->next->next = head;
  head->next = NULL;

  return miniHead;
};

void LinkedListOperations::addAtBack(ListNode *&head, int data) {
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

void LinkedListOperations::printLL(ListNode *head) {
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

ListNode *LinkedListOperations::llMiddle(ListNode *head) {
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

ListNode *LinkedListOperations::reverseLL(ListNode *head) {
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
