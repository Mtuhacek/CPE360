// Stacks:
//- push(int value)
//- pop()
//- displayContents()
#include <iostream>
using namespace std;

class Node {
 public:
  int value;
  Node *nextNode;

  Node() {
    value = 0;
    nextNode = NULL;
  }
};
class Stack {
 public:
  Node *firstNode;
  Node *lastNode;
  Stack() { firstNode = NULL; }
  void push(int input) {
    Node *temp = new Node;
    temp->value = input;
    if (firstNode == NULL) {
      firstNode = temp;
      lastNode = temp;
    } else {
      temp->nextNode = firstNode;
      firstNode = temp;
    }
  }
  void pop() {
    Node *tempPointer = firstNode;
    if (tempPointer == NULL) {
      cout << "Nothing to pop\n";
    } else {
      firstNode = firstNode->nextNode;
      delete tempPointer;
    }
  }
  void printStack() {
    Node *tempPointer = firstNode;
    while (tempPointer != NULL) {
      cout << tempPointer->value;
      cout << ", ";
      tempPointer = tempPointer->nextNode;
    }
    cout << "\n";
  }
};

int main() {
  int userChoice = 1;
  int stackInput;
  int stackOutput;
  Stack myStack;
  while (userChoice != 4) {
    cout << "Press 1 to push \n";
    cout << "Press 2 to pop \n";
    cout << "Press 3 to display contents \n";
    cout << "Press 4 to exit \n";
    cin >> userChoice;
    switch (userChoice) {
      case 1:
        cout << "What would you like to add?\n";
        cin >> stackInput;
        myStack.push(stackInput);
        break;
      case 2:
        cout << "You chose to pop an element\n";
        myStack.pop();
        break;
      case 3:
        cout << "Printing contents in lifo order:\n";
        myStack.printStack();
        break;
    }
  }
}