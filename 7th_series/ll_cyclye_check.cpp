#include<iostream>
using namespace std;


class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void print(node* &head){
    node* tail=head;
    while(tail!=NULL){
        cout<<tail->data;
        tail=tail->next;
    }
}

bool checkCycle(node* head){
    node* slow=head;
    node* fast=head;
    while(fast != NULL && fast->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        return true;
    }
    return false;
}

void inserAtEnd(node* &head,int data){
    node* newnode=new node(data);
    if(head==NULL)
    {
      
        head=newnode;
    }
    else{
        node* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        
        tail->next=newnode;
    }
}

int main() {
    node* head = NULL;

    // Build linked list: 3 -> 2 -> 0 -> -4
    inserAtEnd(head, 3);
    inserAtEnd(head, 2);
    inserAtEnd(head, 0);
    inserAtEnd(head, -4);

    // Case 1: No cycle
    cout << "Cycle present? " << (checkCycle(head) ? "true" : "false") << endl;

    // Case 2: Create a cycle (tail connects to 2nd node, pos = 1)
    node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    node* cycleNode = head->next; // 2nd node (0-indexed pos=1)
    tail->next = cycleNode;       // create cycle

    cout << "Cycle present after linking? " << (checkCycle(head) ? "true" : "false") << endl;

    return 0;
}
