// Binary Search Tree:
// Add nodes to the tree
// Search for a value in the tree
// Remove any node from the tree
// In-order, Pre-order and Post-order traversals of the tree
// And finally, a menu in the main() function to help a user make use of the
// above functionalities.

#include <cmath>
#include <iostream>
using namespace std;

class Node {
 public:
  int value;
  Node *nextNodeOne;
  Node *nextNodeTwo;

  Node() {
    value = 0;
    nextNodeOne = NULL;
    nextNodeTwo = NULL;
  }
};
class Tree {
 public:
  Node *root;
  Tree() { root = NULL; }
  void insert(int input) {
    Node *temp = new Node;
    temp->value = input;
    Node *previous = NULL;
    Node *current = NULL;
    if (root == NULL) {
      root = temp;
    } else {
      previous = root;
      current = root;
      while (current != NULL) {
        if (current->value == input) {
          cout << "Ignoring duplicate value \n";
          return;
        }
        if (input < current->value) {
          previous = current;
          current = current->nextNodeOne;
        } else {
          previous = current;
          current = current->nextNodeTwo;
        }
      }
      if (input < previous->value) {
        previous->nextNodeOne = temp;
      } else {
        previous->nextNodeTwo = temp;
      }
    }
  }
  void search(int input, Node *ptr) {
    if (ptr == NULL) {
      cout << "Could not find the value \n";
      return;
    } else {
      if (input == ptr->value) {
        cout << "Found the value \n";
        return;
      } else if (input < ptr->value) {
        search(input, ptr->nextNodeOne);
      } else {
        search(input, ptr->nextNodeTwo);
      }
    }
  }
  void printInOrder(Node *ptr) {
    if (ptr == NULL) {
      return;
    } else {
      printInOrder(ptr->nextNodeOne);
      cout << ptr->value << " ";
      printInOrder(ptr->nextNodeTwo);
    }
  }
  void printPreOrder(Node *ptr) {
    if (ptr == NULL) {
      return;
    } else {
      cout << ptr->value << " ";
      printPreOrder(ptr->nextNodeOne);
      printPreOrder(ptr->nextNodeTwo);
    }
  }
  void printPostOrder(Node *ptr) {
    if (ptr == NULL) {
      return;
    } else {
      printPostOrder(ptr->nextNodeOne);
      printPostOrder(ptr->nextNodeTwo);
      cout << ptr->value << " ";
    }
  }

  void remove(int input, Node *ptr) {
    if (ptr == NULL) {
      cout << "Value not found" << endl;
      return;
    }
    Node *previous, *current;
    previous = current = ptr;

    while (current != NULL && current->value != input) {
      if (input < current->value) {
        previous = current;
        current = current->nextNodeOne;
      } else {
        previous = current;
        current = current->nextNodeTwo;
      }
    }

    if (current == NULL) {
      cout << "Value not found" << endl;
      return;
    }

    if (current->nextNodeOne == NULL && current->nextNodeTwo == NULL) {
      if (previous->nextNodeOne == current) {
        previous->nextNodeOne = NULL;
        // cout << "About to delete : " << current->value << endl;
        delete current;
      } else {
        previous->nextNodeTwo == NULL;
        // cout << "About to delete : " << current->value << endl;
        delete current;
      }
    } else if (current->nextNodeOne != NULL && current->nextNodeTwo == NULL) {
      if (previous->nextNodeOne == current) {
        previous->nextNodeOne = current->nextNodeOne;
        // cout << "About to delete : " << current->value << endl;
        delete current;
      } else {
        previous->nextNodeTwo = current->nextNodeOne;
        // cout << "About to delete : " << current->value << endl;
        delete current;
      }
    } else if (current->nextNodeOne == NULL && current->nextNodeTwo != NULL) {
      if (previous->nextNodeOne == current) {
        previous->nextNodeOne = current->nextNodeTwo;
        // cout << "About to delete : " << current->value << endl;
        delete current;
      } else {
        previous->nextNodeTwo = current->nextNodeTwo;
        //  cout << "About to delete : " << current->value << endl;
        delete current;
      }
    } else {
      int minValue = findMin(current->nextNodeTwo);
      current->value = minValue;
      remove(minValue, current->nextNodeTwo);
    }
  }
  int findMin(Node *ptr) {
    if (ptr == NULL) {
      return -1;
    } else {
      Node *temp = ptr;
      while (temp->nextNodeOne != NULL) {
        temp = temp->nextNodeOne;
      }
      return temp->value;
    }
  }
  int height(Node *ptr) {
    if (ptr == NULL)
      return 0;
    else {
      int lDepth = height(ptr->nextNodeOne);
      int rDepth = height(ptr->nextNodeTwo);

      if (lDepth > rDepth)
        return (lDepth + 1);
      else
        return (rDepth + 1);
    }
  }
  void deleteTree(Node *ptr) {
    if (ptr == NULL) {
      return;
    } else {
      printPostOrder(ptr->nextNodeOne);
      printPostOrder(ptr->nextNodeTwo);
      cout << "deleting" << ptr->value << " ";
      delete ptr;
    }
  }
  int maxValue(Node *ptr) {
    if (ptr == NULL) {
      return 0;
    } else {
      while (ptr->nextNodeTwo != NULL) {
        ptr = ptr->nextNodeTwo;
      }
      int max = ptr->value;
      return max;
    }
  }
  int minValue(Node *ptr) {
    if (ptr == NULL) {
      return 0;
    } else {
      while (ptr->nextNodeOne != NULL) {
        ptr = ptr->nextNodeOne;
      }
      int min = ptr->value;
      return min;
    }
  }
  int balanceTree(Node *ptr) {
    int difference;
    if (ptr == NULL)
      return 0;
    else {
      int lDepth = height(ptr->nextNodeOne);
      int rDepth = height(ptr->nextNodeTwo);
      difference = abs(lDepth - rDepth);
    }
    return difference;
  }
};

int main() {
  int userChoice = 1;
  int input;
  Tree myTree;
  myTree.insert(30);
  myTree.insert(20);
  myTree.insert(40);
  myTree.insert(15);
  myTree.insert(25);
  myTree.insert(50);
  myTree.insert(10);
  myTree.insert(9);
  myTree.insert(8);
  myTree.insert(7);
  while (userChoice != 10) {
    cout << "Press 1 to add node \n";
    cout << "Press 2 to search for a node \n";
    cout << "Press 3 to delete a node \n";
    cout << "Press 4 to do In-order, Pre-order and Post-order traversals \n";
    cout << "Press 5 to find height \n";
    cout << "Press 6 to delete the tree \n";
    cout << "Press 7 to find the max value \n";
    cout << "Press 8 to find the min value \n";
    cout << "Press 9 to check if the tree is balanced \n";
    cout << "Press 10 to exit \n";
    cin >> userChoice;
    switch (userChoice) {
      case 1:
        cout << "What would you like to insert?\n";
        cin >> input;
        myTree.insert(input);
        break;
      case 2:
        cout << "What would you like to search for?\n";
        cin >> input;
        myTree.search(input, myTree.root);
        break;
      case 3:
        cout << "What would you like to delete?\n";
        cin >> input;
        myTree.remove(input, myTree.root);
        break;
      case 4:
        cout << "\nPrinting contents In-order:\n";
        myTree.printInOrder(myTree.root);
        cout << "\nPrinting contents Pre-order:\n";
        myTree.printPreOrder(myTree.root);
        cout << "\nPrinting contents Post-order:\n";
        myTree.printPostOrder(myTree.root);
        cout << "\n";
        break;
      case 5:
        cout << "The height of the tree is: ";
        cout << myTree.height(myTree.root);
        cout << "\n";
        break;
      case 6:
        myTree.deleteTree(myTree.root);
        cout << "Tree deleted \n";
        break;
      case 7:
        cout << "The max value of the tree is: ";
        cout << myTree.maxValue(myTree.root);
        cout << "\n";
        break;
      case 8:
        cout << "The min value of the tree is: ";
        cout << myTree.minValue(myTree.root);
        cout << "\n";
        break;
      case 9:
        int difference = myTree.balanceTree(myTree.root);
        if (difference <= 2) {
          cout << "The tree is balanced \n";
        } else {
          cout << "The tree is not balanced \n";
        }
        break;
    }
  }
}