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

void insertATEnd(node* &head, int data){
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

node* deleteMiddle(node* head)
{
    if(head == NULL || head->next == NULL)
        return NULL;

    node* slow = head;
    node* fast = head->next->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    node* middle = slow->next;
    slow->next = slow->next->next;

    delete middle;

    return head;
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

    cout << "First number (LL): ";
    printList(num1);

    deleteMiddle(num1);
    cout << "After deleting middle node: ";
    printList(num1);
}
