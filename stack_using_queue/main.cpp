// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <sstream>
#include <string>

using namespace std;

class MyStack
{
private:
  queue<int> q;

public:
  void push(int x);
  int pop();
  int top();
  bool empty();
};

void MyStack::push(int x)
{
  int qSize = q.size();
  q.push(x);

  for (int i{1}; i <= qSize; i++)
  {
    q.push(q.front());
    q.pop();
  }
}

int MyStack::pop()
{
  int poppedVal = q.front();
  q.pop();
  return poppedVal;
}

int MyStack::top() { return q.front(); }

bool MyStack::empty() { return q.empty(); }

int main()
{
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Object of MyStack class
  MyStack stack;

  // Read the number of operations
  int size;
  cin >> size;
  cin.ignore();

  // Read the operations
  vector<string> operations(size);
  string tempOperations;
  getline(cin, tempOperations);

  stringstream ssOps(tempOperations);
  string operation;
  for (int i{}; i < size; i++)
  {
    ssOps >> operations[i];
  }

  // Read the input data
  vector<int> inputs(size, -1);
  string tempInputs;
  getline(cin, tempInputs);

  stringstream ssInputs(tempInputs);
  for (int i{}; i < size; i++)
  {
    if (operations[i] == "push")
    {
      ssInputs >> inputs[i];
    }
  }

  // Perform the operations
  for (int i = 0; i < size; i++)
  {
    const auto &ops = operations[i];
    if (ops == "MyStack")
    {
      cout << "null ";
    }
    else if (ops == "push")
    {
      stack.push(inputs[i]);
      cout << "null ";
    }
    else if (ops == "pop")
    {
      cout << stack.pop() << " ";
    }
    else if (ops == "top")
    {
      cout << stack.top() << " ";
    }
    else if (ops == "empty")
    {
      cout << (stack.empty() ? "true" : "false") << " ";
    }
  }

  cout << "\n";
  return 0;
}
