 #include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int head, tail;

public:
    Queue() {
        head = 0;
        tail = -1;
    }

    void enqueue(int value) {
        if(tail >= 99) {
            cout << "\n\t ... Queue is full, value can't be added ...\n\t";
        } else {
            tail++;
            arr[tail] = value;
            cout << "\n  |  " << arr[tail] << "  | enqueued at tail.\n";
        }
    }

    void dequeue() {
        if(head > tail) {
            cout << "\n\t Queue is empty, value can't be removed\n\t";
        } else {
            cout << "\n\t  |  " << arr[head] << "  | at head of queue is dequeued.\n";
            head++;
        }
    }

    int headValue() {
        if(head > tail) {
            cout << "\n\t Queue is empty\n\t";
            return -1;
        } else {
            cout << "\n\t Head value : ";
            return arr[head];
        }
    }

    int tailValue() {
        if(head > tail) {
            cout << "\n\t Queue is empty\n\t";
            return -1;
        } else {
            cout << "\n\t Tail value : ";
            return arr[tail];
        }
    }

    void display() {
        if(head > tail) {
            cout << "\n\t ... Queue is empty, Enqueue value before display ...\n";
        } else {
            cout << "\n\t======= Queue values are =======\n\t   ";
            for(int i = head; i <= tail; i++) cout << " _______ ";
            cout << "\n\t   ";
            for(int i = head; i <= tail; i++) cout << "|  " << arr[i] << "  | ";
            cout << "\n\t   ";
            for(int i = head; i <= tail; i++) cout << " ______  ";
            cout << "\n\t";
        }
    }

    void updateValue(int pos, int newVal) {
        if(head > tail || pos < head || pos > tail) {
            cout << "\n\t Invalid position, cannot update\n";
        } else {
            cout << "\n\t Value at position " << pos << " updated from " << arr[pos] << " to " << newVal << "\n";
            arr[pos] = newVal;
        }
    }
};

int main() {
    Queue q;
    int choice, val, pos, n;
    cout<<"\n\t ---------- Basic Queue Operations -----------  \n\t";

    do {
    cout << "\n\t============================================== ";
    cout << "\n\t|             Select an operation                |";
    cout << "\n\t|-------------------------------------------- |";
    cout << "\n\t| 1. Enqueue                                  |";
    cout << "\n\t| 2. Dequeue                                  |";
    cout << "\n\t| 3. Display Queue                            |";
    cout << "\n\t| 4. Head & Tail Values                       |";
    cout << "\n\t| 5. Update Value                             |";
    cout << "\n\t| 0. Exit                                     |";
    cout << "\n\t==============================================\n";
    cout << "\n\tEnter your choice: ";
    cin >> choice;

        switch(choice) {
            case 1:
                cout << "\n\t How many values do you want to enqueue? \n\t";
                cin >> n;
                for(int i=0; i<n; i++) {
                    cout << "\t Enter value " << i+1 << " : ";
                    cin >> val;
                    q.enqueue(val);
                }
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << q.headValue();
                cout << q.tailValue() << "\n";
                break;

            case 5:
                cout << "\t Enter position to update (head=0 index): ";
                cin >> pos;
                cout << "\t Enter new value: ";
                cin >> val;
                q.updateValue(pos, val);
                break;

            case 0:
                cout << "\n\t Exiting...\n";
                break;

            default:
                cout << "\n\t Invalid choice!\n";
        }

    } while(choice != 0);

    return 0;
}

