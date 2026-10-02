#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void inserAtEnd(node* &head, int data){
    node* newnode=new node(data);
    if(head==NULL){
        head=newnode;
    } else {
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void printList(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* findloop(node* head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
           slow=head;
           while(fast!=slow){
            slow=slow->next;
            fast=fast->next;
           }
            return slow;
        }
    }
    return NULL;
}
int main(){
     node* head = NULL;

    // Build linked list: 3 -> 2 -> 0 -> -4
    inserAtEnd(head, 3);
    inserAtEnd(head, 2);
    inserAtEnd(head, 0);
    inserAtEnd(head, -4);

     node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    node* cycleNode = head->next; // 2nd node (0-indexed pos=1)
    tail->next = cycleNode;  
    node* result= findloop(head);
    cout<<"starting node is : "<<result->data;
}