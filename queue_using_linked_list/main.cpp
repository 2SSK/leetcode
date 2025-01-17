// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int n) {
    data = n;
    next = NULL;
  }
};

class queueWithLL {
private:
  Node *front, *rear;

public:
  void push(int n);
  int pop();

  queueWithLL() : front{NULL}, rear{NULL} {}
};

void queueWithLL::push(int n) {
  Node *newNode = new Node(n);
  if (front == NULL) {
    front = rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
}

int queueWithLL::pop() {
  if (front == NULL) {
    return -1;
  }
  Node *temp = front;
  front = front->next;
  int poppedVal = temp->data;
  delete temp;

  if (front == NULL)
    rear = NULL;

  return poppedVal;
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  queueWithLL qu;

  // Take size of inputs
  int size;
  cin >> size;

  vector<int> inputs(size);
  // Take inputs
  for (size_t i{}; i < size; i++) {
    cin >> inputs[i];
  }

  // Perform task
  for (size_t i{}; i < size; i++) {
    if (inputs[i] == 1) {
      qu.push(inputs[i + 1]);
    }
    if (inputs[i] == 2 && inputs[i - 1] != 1) {
      printf("pop : %d\n", qu.pop());
    }
  }

  return 0;
}
