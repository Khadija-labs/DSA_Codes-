 #include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if(top >= 99) {
            cout << "\n ... Stack is full, value can't be added ...\n";
        } else {
            top++;
            arr[top] = value;
            cout << "\n  |  " << arr[top] << "  | pushed to stack.\n";
        }
    }

    void pop() {
        if(top < 0) {
            cout << "\n\t Stack is empty, value can't be removed\n";
        } else {
            cout << "\n  |  " << arr[top] << "  | at top of stack is popped.\n";
            top--;
        }
    }

    int head() {
        if(top < 0) {
            cout << "\n\t Stack is empty\n";
            return -1;
        } else {
            cout << "\n\t Top value : ";
            return arr[top];
        }
    }

    void display() {
        if(top < 0) {
            cout << "\n\t ... Stack is empty, Push value before display ...\n";
        } else {
            cout << "\n\t======= Stack values are =======\n\t";
            for(int i = top; i >= 0; i--) {
                cout << "\n  |  " << arr[i] << "  |";
                cout << "\n  ________";
            }
            cout << "\n\t";
        }
    }

    void updateValue(int pos, int newVal) {
        if(top < 0 || pos < 0 || pos > top) {
            cout << "\n\t Invalid position, cannot update\n";
        } else {
            cout << "\n\t Value at position " << pos << " updated from " << arr[pos] << " to " << newVal << "\n";
            arr[pos] = newVal;
        }
    }

    int getTopIndex() {  // ? Getter for top
        return top;
    }
};

int main() {
    Stack s;
    int choice, val, pos, n;

    do {
        cout << "\n\t==============================================";
        cout << "\n\t|            STACK OPERATIONS                 |";
        cout << "\n\t|-------------------------------------------- |";
        cout << "\n\t| 1. Push                                     |";
        cout << "\n\t| 2. Pop                                      |";
        cout << "\n\t| 3. Display Stack                            |";
        cout << "\n\t| 4. Top Value                                |";
        cout << "\n\t| 5. Update Value                             |";
        cout << "\n\t| 0. Exit                                     |";
        cout << "\n\t==============================================\n";
        cout << "\n\tEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\n\t How many values do you want to push? ";
                cin >> n;
                for(int i = 0; i < n; i++) {
                    cout << "\n\t Enter value " << i+1 << " : ";
                    cin >> val;
                    s.push(val);
                }
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.display();
                break;

            case 4:
                cout << s.head() << "\n";
                break;

            case 5:
                cout << "\t Enter position to update (0=bottom, top=" << s.getTopIndex() << "): ";
                cin >> pos;
                cout << "\n\t Enter new value: ";
                cin >> val;
                s.updateValue(pos, val);
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

