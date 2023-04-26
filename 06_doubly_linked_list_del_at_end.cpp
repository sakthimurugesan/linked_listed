#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head;
struct Node *temp;
void insert()
{
    for(int i=1;i<=10;++i)
    {
        Node *new_node=new Node();
        new_node->data=i;
        new_node->prev=0;
        new_node->next=0;
        if(head==0)
        {
            head=new_node;
            temp=new_node;
        }
        else
        {
            new_node->prev=temp;
            temp->next=new_node;
            temp=new_node;
        }
    }
}
void deleteLastNode() {
    if (head == NULL) { // check if list is empty
        return;
    }

    Node* secondLastNode = head;
    Node* lastNode = head->next;

    if (lastNode == NULL) { // list has only one node
        delete head;
        head = NULL;
        return;
    }

    while (lastNode->next != NULL) { // traverse to find second last node
        secondLastNode = lastNode;
        lastNode = lastNode->next;
    }

    secondLastNode->next = NULL; // set second last node's next to NULL
    delete lastNode; // delete last node
}

void display()
{
    Node *temp = head;
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    head = 0;
    insert();
    display();
    deleteLastNode();
    deleteLastNode();
    deleteLastNode();
    display();
    
}

/*

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;


int main() {
    // add some nodes to the linked list
    head = new Node();
    head->data = 1;
    head->next = new Node();
    head->next->data = 2;
    head->next->next = new Node();
    head->next->next->data = 3;
    head->next->next->next = NULL;

    // print the linked list
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    deleteLastNode(); // delete the last node

    // print the linked list again
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}


*/