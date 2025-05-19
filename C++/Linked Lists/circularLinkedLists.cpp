#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
    Node *head;

public:
    LinkedList() {
        head = nullptr;
    }

    void push_front(int val) {
        Node *newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void cycle(int pos) {
        if (head == nullptr) return;

        Node *temp = head;
        Node *cycleStart = nullptr;
        int count = 0;

        while (temp->next != nullptr) {
            if (count == pos) {
                cycleStart = temp;
            }
            temp = temp->next;
            count++;
        }

        if (cycleStart != nullptr) {
            temp->next = cycleStart;
        }
    }

    bool hasCycle() {
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    void removeCycle() {
        Node *slow = head;
        Node *fast = head;
        bool cycle = false;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cycle = true;
                break;
            }
        }
        if (!cycle) {
            cout << "No cycle found" << endl;
        } else {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            cout << "Starting point of cycle is " << slow->data << endl;
            while (fast->next != slow) {
                fast = fast->next;
            }
            fast->next = nullptr;
            cout << "Removed Cycle Successfully" << endl;
        }
    }

    void display() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    ll.display();
    ll.cycle(3);
    cout << ll.hasCycle() << endl;
    ll.removeCycle();
    ll.display();
}
