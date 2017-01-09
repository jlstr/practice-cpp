#include "Queue.h"
#include "Stack/Stack.h"
#include <iostream>
using namespace std;

void printMenu() {
  cout << endl;
  cout << "===============================================================================" << endl;
  cout << "\t" << "1. " << "Print Queue" << endl;
  cout << "\t" << "2. " << "En-Queue new value" << endl;
  cout << "\t" << "3. " << "De-Queue value" << endl;
  cout << "\t" << "4. " << "Queue size" << endl;
  cout << "\t" << "5. " << "Exit" << endl;
  cout << "===============================================================================" << endl;
  cout << "\n" << "Select an option: ";
}

void printQueue(Queue*&);

int main() {
  printMenu();
  
  int option;
  bool breakLoop = false;
  
  Queue *queue = createQueue();

  while (!breakLoop && cin >> option) {
    switch(option) {
      case 1:
        if (!empty(queue)) {
          cout << "\n\t" << endl;
          printQueue(queue);
          cout << "\n" << endl;
        }
        break;
      case 2:
        int data;
        cout << "\n" << "Enter value: ";
        cin >> data;
        enQueue(queue, data);
        break;
      case 3: {
        int value = deQueue(queue);
        if (value == -666) cout << "\n Queue is fucking empty!" << endl;
        else cout << "\nDe-Queued value is: " << value << endl;
        break;
      }
      case 4:
        cout << "\n" << "Queue size = " << size(queue) << endl;
        break;
      case 5:
        breakLoop = true;
        break;
      default:
        breakLoop = true;
        break;
    };

    if (!breakLoop) printMenu();
  }

  return 0;
}

void printQueue(Queue* &queue) {
  Node *temp;

  for (temp = queue->front; temp != NULL; temp = temp->next) {
    cout << temp->data << " --- ";
  }

  cout << "[ END ]";
}
