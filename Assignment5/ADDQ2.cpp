#include<iostream>
using namespace std;

class ListNode{
public:
    int data;
    ListNode* next;
    ListNode(int v){
        data=v;
        next=nullptr;
    }
};

class LinkedList{
public:
    ListNode* head;
    LinkedList(){
        head=nullptr;
    }
    void display(){
        ListNode* t=head;
        while(t!=nullptr){
            cout<<t->data<<" -> ";
            t=t->next;
        }
        cout<<endl;
    }
    void insertAtEnd(int val){
        ListNode* ln=new ListNode(val);
        if(head==nullptr){
            head=ln;
            return;
        }
        ListNode* t=head;
        while(t->next!=nullptr)
            t=t->next;
        t->next=ln;
        ln->next=nullptr;
    }
};

// -------------------- Solution --------------------
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    int count = 0;

    ListNode* temp = head;
    int nodeCount = 0;
    while (temp && nodeCount < k) {
        temp = temp->next;
        nodeCount++;
    }
    if (nodeCount < k) return head; 

    count = 0;
    curr = head;
    while(curr != nullptr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != nullptr)
        head->next = reverseKGroup(next, k);

    return prev;
}

int main() {
    LinkedList l;

    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(3);
    l.insertAtEnd(4);
    l.insertAtEnd(5);
    l.insertAtEnd(6);
    l.insertAtEnd(7);

    int k = 3;
    l.head = reverseKGroup(l.head, k);

    cout << "Linked List after reversing in groups of " << k << ":\n";
    l.display();

    return 0;
}