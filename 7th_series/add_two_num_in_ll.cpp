#include <iostream>
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

// Function to add two numbers represented by linked lists
node* addTwoNum(node* n1, node* n2) {
    node* dummy = new node(-1);
    node* curr = dummy;
    int carry = 0;
    int sum = carry;

    while (n1 != NULL || n2 != NULL || carry != 0) {
        sum = carry;
        if (n1 != NULL) {
            sum = sum + n1->data;
            n1 = n1->next;
        }
        if (n2 != NULL) {
            sum = sum + n2->data;
            n2 = n2->next;
        }
        node* newnode = new node(sum % 10);
        curr->next = newnode;
        curr = curr->next;
        carry = sum / 10;
    }
    return dummy->next;
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

// Helper function to print linked list
void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* num1 = NULL;
    node* num2 = NULL;

    int n1, n2, val;

    cout << "Enter number of digits in first number: ";
    cin >> n1;
    cout << "Enter digits (in reverse order, least significant first): ";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        insertAtEnd(num1, val);
    }

    cout << "Enter number of digits in second number: ";
    cin >> n2;
    cout << "Enter digits (in reverse order, least significant first): ";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        insertAtEnd(num2, val);
    }

    cout << "First number (LL): ";
    printList(num1);

    cout << "Second number (LL): ";
    printList(num2);

    node* result = addTwoNum(num1, num2);

    cout << "Sum (LL): ";
    printList(result);

    return 0;
}
