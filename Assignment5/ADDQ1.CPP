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
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

    ListNode* a = headA;
    ListNode* b = headB;
    int lenA = 0, lenB = 0;

    while (a) { lenA++; a = a->next; }
    while (b) { lenB++; b = b->next; }

    a = headA;
    b = headB;

    if (lenA > lenB) {
        int diff = lenA - lenB;
        while(diff--) a = a->next;
    } else {
        int diff = lenB - lenA;
        while(diff--) b = b->next;
    }
    while(a && b) {
        if(a == b) return a;
        a = a->next;
        b = b->next;
    }

    return nullptr;
}
int main() {
    LinkedList l1, l2;

    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);

    l2.insertAtEnd(6);
    l2.insertAtEnd(7);
    l2.head->next->next = l1.head->next; 
    ListNode* inter = getIntersectionNode(l1.head, l2.head);
    if(inter)
        cout << "Intersection at node with value: " << inter->data << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}