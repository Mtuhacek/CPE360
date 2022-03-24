#include <stdlib.h>
#include <time.h>

#include <iostream>
using namespace std;

int storeClock = 0;

class Customer {
 public:
  int inTime;
  int outTime;
  int waitTime;
  int orderTime;
  int originalOrderTime;
  Customer *next;

  Customer() {
    inTime = storeClock;
    outTime = 0;
    waitTime = 0;
    orderTime = rand() % 6 + 1;
    originalOrderTime = orderTime;
    next = NULL;
  }
};

class Queue {
 public:
  Customer *head;
  bool initialized = false;
  double avgWaitTime = 0;
  double avgServiceTime = 0;
  double avgQueueLength = 0;
  int bestWaitTime = 0;
  int bestServiceTime = 0;
  int bestQueueLength = 0;
  int worstWaitTime = 0;
  int worstServiceTime = 0;
  int worstQueueLength = 0;
  int bestQueueLengthTiming = 0;
  int bestServiceTimeTiming = 0;
  int bestWaitTimeTiming = 0;
  int worstQueueLengthTiming = 0;
  int worstServiceTimeTiming = 0;
  int worstWaitTimeTiming = 0;

  Queue() { head = NULL; }

  void enqueue() {
    Customer *temp = new Customer();
    temp->next = NULL;
    cout << "Just added a new customer to the line: " << temp->inTime
         << " and order time: " << temp->orderTime << endl;

    if (head == NULL) {
      head = temp;
    } else {
      Customer *another;
      another = head;
      while (another->next != NULL) {
        another = another->next;
      }
      another->next = temp;
    }

    if (initialized == false) {
      worstWaitTime = temp->waitTime;
      bestWaitTime = temp->waitTime;
      avgWaitTime = temp->waitTime;
      worstServiceTime = temp->waitTime + temp->originalOrderTime;
      bestServiceTime = temp->waitTime + temp->originalOrderTime;
      avgServiceTime = avgServiceTime;
      initialized = true;
    }
  }

  void dequeue() {
    if (head == NULL) {
      cout << "The queue is empty" << endl;
    } else {
      Customer *temp;
      temp = head;
      int queueSize = queueLength();
      head = head->next;
      cout << "At time: " << storeClock << " Customer left" << endl;

      if (temp->waitTime > worstWaitTime) {
        worstWaitTime = temp->waitTime;
        worstWaitTimeTiming = temp->inTime;
      }
      if (temp->waitTime < bestWaitTime) {
        bestWaitTime = temp->waitTime;
        bestWaitTimeTiming = temp->inTime;
      }
      if ((temp->waitTime + temp->originalOrderTime) > worstServiceTime) {
        worstServiceTime = temp->waitTime + temp->originalOrderTime;
        worstServiceTimeTiming = temp->inTime;
      }
      if ((temp->waitTime + temp->originalOrderTime) < bestServiceTime) {
        bestServiceTime = temp->waitTime + temp->originalOrderTime;
        bestServiceTimeTiming = temp->inTime;
      }
      avgWaitTime = (avgWaitTime + temp->waitTime) / 2;
      avgServiceTime =
          (avgServiceTime + temp->waitTime + temp->originalOrderTime) / 2;
      if (queueSize > worstQueueLength) {
        worstQueueLength = queueSize;
        worstQueueLengthTiming = temp->inTime;
      }
      if (queueSize < bestQueueLength) {
        bestQueueLength = queueSize;
        bestQueueLengthTiming = temp->inTime;
      }
      avgQueueLength = (queueSize + avgQueueLength) / 2;

      delete temp;
    }
  }

  void printStats() {
    cout << "CUSTOMER QUEUE STATS: " << endl;
    cout << "Average wait time: " << avgWaitTime << endl;
    cout << "Best wait time: " << bestWaitTime << " at time "
         << bestWaitTimeTiming << endl;
    cout << "Worst wait time: " << worstWaitTime << " at time "
         << worstWaitTimeTiming << endl;

    cout << "Average service time: " << avgServiceTime << endl;
    cout << "Best service time: " << bestServiceTime << " at time "
         << bestServiceTimeTiming << endl;
    cout << "Worst service time: " << worstServiceTime << " at time "
         << worstServiceTimeTiming << endl;

    cout << "Average queue size: " << avgQueueLength << endl;
    cout << "Best queue size: " << bestQueueLength << " at time "
         << bestQueueLengthTiming << endl;
    cout << "Worst queue size: " << worstQueueLength << " at time "
         << worstQueueLengthTiming << endl;
  }

  int queueLength() {
    int size = 0;
    Customer *ptr = head;
    while (ptr != NULL) {
      size++;
      ptr = ptr->next;
    }
    return size;
  }

  void incrementAllWaitTime() {
    Customer *temp = head;
    while (temp != NULL) {
      temp->waitTime++;
      temp = temp->next;
    }
  }
};

int main() {
  srand(time(NULL));
  Queue myStore;
  int random_number;

  while (storeClock < 1020) {
    storeClock++;
    // 8:00 am to 10:00 am, pa= 0.3
    if (storeClock <= 120) {
      random_number = rand() % 100 + 1;
      if (random_number <= 30) {
        cout << "At time: " << storeClock << " We have 1 new customer" << endl;
        myStore.enqueue();
      } else {
        cout << "At time: " << storeClock << " No new customers arrived"
             << endl;
      }
    }
    // 10:00 am to 11:30 am, pa= 0.1
    else if (storeClock > 120 && storeClock <= 210) {
      random_number = rand() % 100 + 1;
      if (random_number <= 10) {
        cout << "At time: " << storeClock << " We have 1 new customer" << endl;
        myStore.enqueue();
      } else {
        cout << "At time: " << storeClock << " No new customers arrived"
             << endl;
      }
    }

    // 11:30 am to 1:30 pm, pa= 0.4
    else if (storeClock > 210 && storeClock <= 330) {
      random_number = rand() % 100 + 1;
      if (random_number <= 40) {
        cout << "At time: " << storeClock << " We have 1 new customer" << endl;
        myStore.enqueue();
      } else {
        cout << "At time: " << storeClock << " No new customers arrived"
             << endl;
      }
    }
    // 1 : 30 pm to 5 : 30 pm, pa = 0.1
    else if (storeClock > 330 && storeClock <= 570) {
      random_number = rand() % 100 + 1;
      if (random_number <= 10) {
        cout << "At time: " << storeClock << " We have 1 new customer" << endl;
        myStore.enqueue();
      } else {
        cout << "At time: " << storeClock << " No new customers arrived"
             << endl;
      }
    }
    // 5 : 30 pm to 8 : 00 pm, pa = 0.25
    else if (storeClock > 570 && storeClock <= 720) {
      random_number = rand() % 100 + 1;
      if (random_number <= 25) {
        cout << "At time: " << storeClock << " We have 1 new customer" << endl;
        myStore.enqueue();
      } else {
        cout << "At time: " << storeClock << " No new customers arrived"
             << endl;
      }
    }
    // 8 : 00 pm to 11 : 00 pm, pa = 0.2
    else if (storeClock > 720 && storeClock <= 900) {
      random_number = rand() % 100 + 1;
      if (random_number <= 20) {
        cout << "At time: " << storeClock << " We have 1 new customer" << endl;
        myStore.enqueue();
      } else {
        cout << "At time: " << storeClock << " No new customers arrived"
             << endl;
      }
    }
    // 11 : 00 pm to 1 : 00 am, pa = 0.1
    else {
      random_number = rand() % 100 + 1;
      if (random_number <= 10) {
        cout << "At time: " << storeClock << " We have 1 new customer" << endl;
        myStore.enqueue();
      } else {
        cout << "At time: " << storeClock << " No new customers arrived"
             << endl;
      }
    }
    if (myStore.head != NULL) {
      if (myStore.head->orderTime == 0) {
        myStore.dequeue();
      } else {
        myStore.incrementAllWaitTime();
        myStore.head->orderTime--;
      }
    }
  }
  myStore.printStats();
}
