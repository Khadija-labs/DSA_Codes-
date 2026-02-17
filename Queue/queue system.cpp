 #include<iostream>
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
        if (tail >= 99) {
            cout << "\n ... Queue is full, value can't be added ...";
        } else {
            tail++;
            arr[tail] = value;
        }
    }

    void dequeue() {
        if (head > tail) {
            cout << "\n\t Queue is empty, value can't be removed";
        } else {
            cout << "\n  |  " << arr[head] << "  | at head of queue is dequeued.\n";
            head++;
        }
    }

    int headValue() {
        if (head > tail) {
            cout << "\n\t Queue is empty";
            return -1;
        } else {
        	cout<<"\n\t Head value : ";
            return arr[head];
        }
    }

    int tailValue() {
        if (head > tail) {
            cout << "\n\t Queue is empty";
            return -1;
        } else {
        	cout<<"\n\t Tail value : ";
            return arr[tail];
        }
    }
    void display() {
    if (head > tail) {
        cout << "\n\t ... Queue is empty, Enqueue value before display ...\n";
    } else {
        cout << "\n\t======= Queue values are =======\n\t   ";

        for (int i = head; i <= tail; i++) {
            cout << " _______ ";
        }

        cout << "\n\t   ";

        for (int i = head; i <= tail; i++) {
        	cout << "|  " << arr[i] << "  | ";   
        }

        cout << "\n\t   ";

        for (int i = head; i <= tail; i++) {
            cout << "|______| ";
        }

    }
    cout<<"\n\t";
}  
};

int main() {
    Queue q1;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);

    q1.display();
    cout << q1.headValue() << " \n";
    cout << q1.tailValue() << " \n";

    q1.dequeue();
     
    cout<< q1.headValue() << "\n";
   

    q1.dequeue();
    q1.display();
    cout<< q1.headValue() << "\n";
    cout<< q1.tailValue() << "\n";
    q1.dequeue();
    q1.dequeue();
    q1.display();
    cout << q1.headValue() << " \n";
    cout << q1.tailValue() << " \n";

    q1.dequeue();
    q1.display();

    return 0;
}
