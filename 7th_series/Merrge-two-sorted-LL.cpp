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
// print
void printList(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
// Helper function to insert at end
void insertAtEnd(node* &head, int data) {
    node* newnode = new node(data);
    if (head == NULL) {
        head = newnode;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
node* MergeTwoNum(node* &head1, node* &head2){
    node* dummy=new node(-1);
    node* tail=dummy;
    node* l1=head1;
    node* l2=head2;
    while(l1!=NULL && l2!=NULL){
        if(l1->data<=l2->data){
            tail->next=l1;
           
            l1=l1->next;
        }
        else{
            tail->next=l2;
           
            l2=l2->next;
        }
         tail = tail->next;
    }
   if (l1 != NULL) tail->next = l1;
        if (l2 != NULL) tail->next = l2;
   return dummy->next;
}
int main() {
    node* num1 = NULL;
    node* num2 = NULL;

    int n1, n2, val;

    cout << "Enter number of digits in first number: ";
    cin >> n1;
    cout << "Enter digits (in sorted order): ";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        insertAtEnd(num1, val);
    }

    cout << "Enter number of digits in second number: ";
    cin >> n2;
    cout << "Enter digits (in sorted order): ";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        insertAtEnd(num2, val);
    }

    cout << "First number (LL): ";
    printList(num1);

    cout << "Second number (LL): ";
    printList(num2);

    node* result = MergeTwoNum(num1, num2);

    cout << "Sum (LL): ";
    printList(result);

    return 0;
}
