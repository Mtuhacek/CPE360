// Linked list:
//-insertAtHead(int value) Hint: Similar to Stacks, insert at position 1
//-insertAtPosition(int position, int value)Hint: This should insert a node with
//‘value’ at any position in the list as long as that position is valid
//-removeFromPosition(int position)Hint: Similar to insert above, this should
// remove a node from a list as long as position is valid -displayContents()

#include <iostream>
#include <stack>
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
class List {
 public:
  int elementCount = 0;
  Node *firstNode;
  Node *lastNode;
  List() { firstNode = NULL; }
  void insertAtHead(int input) {
    Node *temp = new Node;
    temp->value = input;
    if (firstNode == NULL) {
      firstNode = temp;
      lastNode = temp;
      elementCount++;
    } else {
      temp->nextNode = firstNode;
      firstNode = temp;
      elementCount++;
    }
  }
  void insertAtPosition(int listInput, int listPosition) {
    Node *temp = new Node;
    temp->value = listInput;
    if (listPosition > 0 && listPosition <= elementCount + 1) {
      if (listPosition == 1) {
        insertAtHead(listInput);
      } else {
        Node *countPointer = firstNode;
        for (int i = 1; i < listPosition - 1; i++) {
          countPointer = countPointer->nextNode;
        }
        temp->nextNode = countPointer->nextNode;
        countPointer->nextNode = temp;
      }
    } else {
      cout << "This postition is not valid \n";
    }
  }
  void deleteAtPosition(int listPosition) {
    Node *tempPointer = firstNode;
    Node *deletePointer = NULL;
    if (tempPointer == NULL) {
      cout << "Nothing to delete\n";
    } else {
      if (listPosition > 0 && listPosition <= elementCount + 1) {
        if (listPosition == 1) {
          delete tempPointer;
          firstNode = NULL;
        } else {
          Node *countPointer = firstNode;
          for (int i = 1; i < listPosition - 1; i++) {
            countPointer = countPointer->nextNode;
          }
          deletePointer = countPointer->nextNode;
          countPointer->nextNode = deletePointer->nextNode;
          delete deletePointer;
          cout << "Deleted\n";
        }
      } else {
        cout << "This postition is not valid \n";
      }
    }
  }
  void printList() {
    Node *tempPointer = firstNode;
    while (tempPointer != NULL) {
      cout << tempPointer->value;
      cout << ", ";
      tempPointer = tempPointer->nextNode;
    }
    cout << "\n";
  }
  void reverseLinkedList() {
    Node *tempPointer = firstNode;
    Node *popPointer = NULL;
    Node *newHeadPointer = NULL;
    stack<Node *> myStack;
    while (tempPointer != NULL) {
      myStack.push(tempPointer);
      tempPointer = tempPointer->nextNode;
    }
    if (myStack.size() > 0) {
      firstNode = myStack.top();
      myStack.pop();
      tempPointer = firstNode;
    }
    while (myStack.size() > 0) {
      popPointer = myStack.top();
      myStack.pop();
      tempPointer->nextNode = popPointer;
      tempPointer = popPointer;
    }
    tempPointer->nextNode = NULL;
  }
  void removeEveryOtherNode() {
    Node *tempPointer = firstNode;
    Node *priorPointer = NULL;
    int loopCounter = 0;

    while (tempPointer != NULL) {
      loopCounter++;
      priorPointer = tempPointer;
      tempPointer = tempPointer->nextNode;
      if (loopCounter % 2 > 0) {
        priorPointer->nextNode = tempPointer->nextNode;
        delete tempPointer;
        tempPointer = priorPointer;
      }
    }
  }
};

int main() {
  int userChoice = 1;
  int listInput;
  int listOutput;
  int listPosition;
  List myList;
  while (userChoice != 7) {
    cout << "Press 1 to insert at head \n";
    cout << "Press 2 to insert at position \n";
    cout << "Press 3 to delete at position \n";
    cout << "Press 4 to display contents \n";
    cout << "Press 5 to reverse linked list \n";
    cout << "Press 6 to remove every other node \n";
    cout << "Press 7 to exit \n";
    cin >> userChoice;
    switch (userChoice) {
      case 1:
        cout << "What would you like to insert?\n";
        cin >> listInput;
        myList.insertAtHead(listInput);
        break;
      case 2:
        cout << "What would you like to insert?\n";
        cin >> listInput;
        cout << "Where would you like to insert?\n";
        cin >> listPosition;
        myList.insertAtPosition(listInput, listPosition);
        break;
      case 3:
        cout << "Where would you like to delete?\n";
        cin >> listPosition;
        myList.deleteAtPosition(listPosition);
        break;
      case 4:
        cout << "Printing contents:\n";
        myList.printList();
        break;
      case 5:
        cout << "Reversing contents:\n";
        myList.reverseLinkedList();
        break;
      case 6:
        cout << "Removing every other node:\n";
        myList.removeEveryOtherNode();
        break;
    }
  }
}
