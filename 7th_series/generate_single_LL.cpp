#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    // default constructor
    node(){
        this->data=0;
        this->next=NULL;
    }
    // parameterized constructor
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

// Linked List print function
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

// Insert at head
void insertAtHead(node* &head, node* &tail, int data){
    // अगर list खाली है
    if(head==NULL){
        node* newnode=new node(data);
        head=newnode;
        tail=newnode;
    }
    else{
        node* newnode=new node(data);
        newnode->next=head;
        head=newnode;
    }
}

// Insert at end
void insertAtEnd(node* &head, node* &tail, int data){
    // अगर list खाली है
    if(head==NULL){
        node* newnode=new node(data);
        head=newnode;
        tail=newnode;
    }
    else{
        node* newnode=new node(data);
        tail->next=newnode;
        tail=newnode;
    }
}

// Length of linked list
int lengthofnode(node* &head){
    node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

// Insert at any position
void insrtatanypos(int data,node* head, node* tail , int position){
    // अगर list खाली है
    if(head==NULL){
        node* newnode=new node(data);
        head=newnode;
        tail=newnode;
    }

    // अगर position 0 है तो head पर insert करो
    if(position==0){
        insertAtHead(head,tail,data);
    }

    int len=lengthofnode(head);

    // अगर position length से बड़ी है तो end पर insert करो
    if(position > len){
        insertAtEnd(head,tail,data);
    }

    // बीच में insert करना
    int i=1;
    node* prev=head;
    while(i<position){
        prev=prev->next;
        i++; // तुम्हारे code में ये missing था
    }
    node* curr=prev->next;
    node* newnode=new node(data);
    newnode->next=curr;
    prev->next=newnode;
}

// Delete node at given position
void deletenode(node* &head,node* tail,int position){
    // अगर list खाली है
    if(head == NULL) return;

    // Case 1: delete head
    if(position==0){
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        if(head == NULL) tail = NULL; // अगर list खाली हो गई
        return;
    }

    // length निकालो
    int len=lengthofnode(head);

    // अगर position invalid है
    if(position >= len) return;

    // Case 2: delete middle या last
    int i = 1;
    node* prev = head;
    while(i < position){
        prev = prev->next;
        i++;
    }
    node* curr = prev->next;
    prev->next = curr->next;

    // अगर last node delete हो रही है
    if(curr == tail){
        tail = prev;
    }

    curr->next = NULL;
    delete curr;
}

int main(){
    node* head=NULL;
    node* tail=NULL;

    // Insert operations
    insertAtHead(head,tail,20);   // 20
    insertAtHead(head,tail,70);   // 70 -> 20
    insertAtEnd(head,tail,90);    // 70 -> 20 -> 90
    print(head);

    // Delete head
    deletenode(head,tail,0);      // delete position 0 (head)
    print(head);                  // 20 -> 90

    // Delete middle
    deletenode(head,tail,0);      // delete again head (20)
    print(head);                  // 90

    // Delete last
    deletenode(head,tail,0);      // delete last (90)
    print(head);                  // empty list
}
