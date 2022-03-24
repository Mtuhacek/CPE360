// Queues:
//-enqueue(int value)
//-dequeue()
//-printContents()
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
class Queue {
 public:
  Node *firstNode;
  Node *lastNode;
  Queue() { firstNode = NULL; }
  void enqueue(int input) {
    Node *temp = new Node;
    temp->value = input;
    if (firstNode == NULL) {
      firstNode = temp;
      lastNode = temp;
    } else {
      lastNode->nextNode = temp;
      lastNode = lastNode->nextNode;
    }
  }
  void dequeue() {
    Node *tempPointer = firstNode;
    if (tempPointer == NULL) {
      cout << "Nothing to dequeue\n";
    } else {
      firstNode = firstNode->nextNode;
      delete tempPointer;
    }
  }
  void printQueue() {
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
  int queueInput;
  int queueOutput;
  Queue myQueue;
  while (userChoice != 4) {
    cout << "Press 1 to enqueue \n";
    cout << "Press 2 to dequeue \n";
    cout << "Press 3 to display contents \n";
    cout << "Press 4 to exit \n";
    cin >> userChoice;
    switch (userChoice) {
      case 1:
        cout << "What would you like to add?\n";
        cin >> queueInput;
        myQueue.enqueue(queueInput);
        break;
      case 2:
        cout << "You chose to remove the first element\n";
        myQueue.dequeue();
        break;
      case 3:
        cout << "Printing contents in fifo order:\n";
        myQueue.printQueue();
        break;
    }
  }
}