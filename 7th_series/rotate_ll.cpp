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

// insert at end
void insertATEnd(node* &head, int data){
    node* newnode=new node(data);
    if(head==NULL){
        head=newnode;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

// print
void printList(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* rotateRight(node* head, int k)
{
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    // Step 1: Find length and tail
    int length = 1;
    node* tail = head;

    while(tail->next != NULL)
    {
        tail = tail->next;
        length++;
    }

    // Step 2: Avoid unnecessary rotations
    k = k % length;

    if(k == 0)
        return head;

    // Step 3: Make the list circular
    tail->next = head;

    // Step 4: Find new tail
    int steps = length - k;

    node* newTail = head;

    for(int i = 1; i < steps; i++)
    {
        newTail = newTail->next;
    }

    // Step 5: New head is after new tail
    node* newHead = newTail->next;

    // Step 6: Break the circle
    newTail->next = NULL;

    return newHead;
}

int main(){
    node* num1=NULL;
    int n,val;
    cout << "Enter number of digits in LL number: ";
    cin>>n;
    cout << "Enter digits: ";
    for(int i=0;i<n;i++){
        cin>>val;
        insertATEnd(num1,val);
    }
     int rt;
    cout<<"enter number of times you want rotation ";
    cin>>rt;
    cout << "before rotation (LL): ";
    printList(num1);

    num1=rotateRight(num1,rt);
     
     cout << "after rotation (LL): ";
    printList(num1);
}