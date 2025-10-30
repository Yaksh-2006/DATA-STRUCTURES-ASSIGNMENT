#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

Node* reverseKGroup(Node* head, int k) {
    Node* curr = head;
    Node* newHead = nullptr;
    Node* groupPrevTail = nullptr;

    while (curr) {
        Node* groupStart = curr;
        int count = 0;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }

        Node* prev = nullptr;
        Node* temp = groupStart;
        for (int i = 0; i < count; i++) {
            Node* nextNode = temp->next;
            temp->next = prev;
            temp->prev = nextNode;
            prev = temp;
            temp = nextNode;
        }

        if (!newHead) newHead = prev;

        if (groupPrevTail) groupPrevTail->next = prev;
        groupStart->next = temp;
        if (temp) temp->prev = groupStart;

        groupPrevTail = groupStart;
    }

    return newHead;
}

void displayDLL(Node* head) {
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;

    cout << "Original DLL:\n";
    displayDLL(head);

    int k = 3;
    head = reverseKGroup(head, k);

    cout << "DLL after reversing every group of " << k << " nodes:\n";
    displayDLL(head);

    return 0;
}