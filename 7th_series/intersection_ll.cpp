#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// insert at end
void insertATEnd(node* &head, int data){
    node* newnode = new node(data);
    if(head == NULL){
        head = newnode;
    } else {
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// print linked list
void printList(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// function to get intersection node
node* getIntersectionNode(node* headA, node* headB)
{
    node* t1 = headA;
    node* t2 = headB;

    while(t1 != t2)
    {
        if(t1 == NULL)
            t1 = headB;
        else
            t1 = t1->next;

        if(t2 == NULL)
            t2 = headA;
        else
            t2 = t2->next;
    }

    return t1;
}

int main(){
    // Example: create two linked lists with intersection
    node* headA = NULL;
    node* headB = NULL;

    // First list: 1 -> 2 -> 3 -> 4 -> 5
    insertATEnd(headA, 1);
    insertATEnd(headA, 2);
    insertATEnd(headA, 3);

    // Second list: 9 -> 10
    insertATEnd(headB, 9);
    insertATEnd(headB, 10);

    // Create intersection manually
    node* common = new node(4);
    common->next = new node(5);

    // attach to list A
    node* temp = headA;
    while(temp->next != NULL) temp = temp->next;
    temp->next = common;

    // attach to list B
    temp = headB;
    while(temp->next != NULL) temp = temp->next;
    temp->next = common;

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    node* inter = getIntersectionNode(headA, headB);
    if(inter != NULL)
        cout << "Intersection at node with value: " << inter->data << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}
