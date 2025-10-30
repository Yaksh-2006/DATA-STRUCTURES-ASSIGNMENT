#include <iostream>
using namespace std;
// Node class for a doubly linked list
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
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << std::endl;
}
void correctRandomPointer(Node* head) {
    if (head == nullptr || head->next == nullptr) 
        return;
    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->prev != current) {
            current->next->prev = current;
            return; 
        }
        current = current->next;
    }
}

int main() {
    Node* head = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    head->next = node2;
    node2->prev = head;
    node2->next = head; 
    node3->prev = head; 
    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    
    cout << "Initial (Corrupted) List:" << std::endl;
    cout << "1 <-> 2 <-> 1 (Loop) and 3 with prev pointing to 1" << std::endl;
    correctRandomPointer(head);
    cout << "Final (Corrected) List:" << std::endl;
    printList(head);

    return 0;
}