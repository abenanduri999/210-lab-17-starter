#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
Node * addNodeToHead(Node *);
Node * addNodeToTail(Node *); 
Node * deleteNode(Node *); 
Node * insertNode(Node *); 
void deleteList(Node *); 
 



int main() {
    Node *head = nullptr;
    
    head = addNodeToHead(head); 
    //output(head); 

    head = addNodeToTail(head);
    output(head);

    head = deleteNode(head);
    output(head); 
    
    head = insertNode(head); 
    output(head); 

    deleteList(head); 
    

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    
    int count = 1;
    Node * current = hd;
    while (current != nullptr ) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
    
}

Node * addNodeToHead(Node * head) 
{
// create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    return head; 
}

Node * addNodeToTail(Node * head)
{
    int val = rand() % 100; 
    Node * newNode = new Node; // make a new node
    newNode->value = val; 

    if(!head)   // check to see if list if empty
    {
        head = newNode;
        newNode->next = nullptr; 
    }

    else
    {
        Node * newN = head;
        while(newN->next != nullptr) 
            {
                newN = newN->next;
            } 
    
        newN->next = newNode; 
     
    }

    return head;
}

Node  * deleteNode(Node * head) 
{
     // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    return head;
}

Node * insertNode(Node * head) 
{
     // insert a node
    int entry;
    Node * current = head;
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    Node * prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    return head;
}

void deleteList(Node * head)
{
    Node * current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);
}