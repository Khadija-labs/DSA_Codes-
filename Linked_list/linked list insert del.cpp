 #include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Linked List class
class LinkedList {
private:
    Node* first;
    Node* last;

public:
    LinkedList() {
        first = NULL;
        last = NULL;
    }

    void insertAtEnd() {
        static int i = 1;
        int val;
        cout << "\n\t Enter the data in node " << i++ << " : ";
        cin >> val;

        Node* newNode = new Node(val);

        if (first == NULL) {
            first = last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    void removeNode(int key) {
        if (first == NULL) {
            cout << "\n\tLinked List is empty...!" << endl;
            return;
        }

        Node* q = first;
        Node* q1 = NULL;

        while (q != NULL && q->data != key) {
            q1 = q;
            q = q->next;
        }

        if (q == NULL) {
            cout << "\n\tValue " << key << " not found in the list...!" << endl;
            return;
        }

        // Case 1: only one node
        if (q == first && q == last) {
            first = last = NULL;
        }
        // Case 2: first node
        else if (q == first) {
            first = first->next;
        }
        // Case 3: last node
        else if (q == last) {
            q1->next = NULL;
            last = q1;
        }
        // Case 4: middle node
        else {
            q1->next = q->next;
        }

        delete q;
        cout << "\n\t....Node with value " << key << " deleted successfully...!" << endl;
    }

    void display() {
        if (first == NULL) {
            cout << "\n\tLinked List is empty...!" << endl;
            return;
        }

        Node* temp = first;
        while (temp != NULL) {
            cout << "    " << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main() {
    LinkedList list;

    cout << "\n\t===== Linked List Insertion & Deletion =====\n";

    list.insertAtEnd();
    list.insertAtEnd();
    list.insertAtEnd();

    cout << "\n\t---- Linked List before deletion ----\n";
    list.display();

    int key;
    cout << "\n\t---- Enter value to delete ----\n\t";
    cin >> key;

    list.removeNode(key);

    cout << "\n\t---- Linked List after deletion ----\n";
    list.display();

    return 0;
}

