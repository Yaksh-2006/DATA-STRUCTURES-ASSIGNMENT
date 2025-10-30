#include <iostream>
using namespace std;

// Node for Circular Singly Linked List
class CSNode {
public:
    int data;
    CSNode* next;
    CSNode(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to display circular linked list
void displayCircularList(CSNode* head) {
    if (!head) { 
        cout << "List is empty.\n"; 
        return; 
    }
    CSNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Function to split circular linked list into two halves
void splitCircularList(CSNode* head, CSNode*& head1, CSNode*& head2) {
    if (!head || head->next == head) {
        head1 = head;
        head2 = nullptr;
        return;
    }
    CSNode* slow = head;
    CSNode* fast = head;
    // Using slow and fast pointers to find midpoint
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // For even nodes, fast->next->next == head, move fast one step to last node
    if (fast->next->next == head)
        fast = fast->next;
    // Set heads of the two halves
    head1 = head;
    head2 = slow->next;
    // Make first half circular
    slow->next = head1;
    // Make second half circular
    fast->next = head2;
}
int main() {
    // Creating a circular linked list: 1->2->3->4->5->1
    CSNode* head = new CSNode(1);
    CSNode* node2 = new CSNode(2);
    CSNode* node3 = new CSNode(3);
    CSNode* node4 = new CSNode(4);
    CSNode* node5 = new CSNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = head;

    cout << "Original Circular Linked List: ";
    displayCircularList(head);

    CSNode* head1 = nullptr;
    CSNode* head2 = nullptr;

    splitCircularList(head, head1, head2);

    cout << "First Half: ";
    displayCircularList(head1);

    cout << "Second Half: ";
    displayCircularList(head2);

    return 0;
}