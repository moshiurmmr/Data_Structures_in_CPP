/* 
This program implements a simple linked list with following APIs (functionalities)
- append: inserts a node at the end of the Linked List
- appendAtHead: inserts a node at the head/beginning of the Linked List
- remove: delets a node from the Linked List
- printLL: prints the values stored in the nodes of the Linked List 
*/
# include <iostream>

using namespace std;

// declare a Node class
class Node {
    public:
        int data;
        Node* next; // pointer to next node in the Linked List
        // constructor
        Node(int d){
            data = d;
            next = NULL;
        }
        
};

// declare a Linked List class
class LinkedList {
public:
    
    // head node of the Linked List
    Node* head = new Node(0); // first node data is always this value 0

    // append function to insert a new node at the end of the linkedlist
    void append(int data){
        // if there is no head, make the new node the head of the linkedlist
        // this part needs to be updated, logic is not working
        if (head == NULL){
            head = new Node(data);
            cout << "head data is " << head->data << endl;
            return;
        }
        
        // move to the end of the Linked List
        Node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new Node(data);
        
    }

    // To append a data at the head of the Linked List
    void appendAthead(int data){
        // create a new node
        Node* newNode = new Node(data);
        // make the newNode the head of the Linked List
        newNode->next = head;
        head = newNode;
        return;

    }

    // To delete a node from the Linked List
    void remove(int dataTodel){
        Node* current = head;
         // if the datatodel is in the head node
            if (head->data == dataTodel){
                head = head->next;
                return;
            }
        while(current->next != NULL){
            if (current->next->data == dataTodel){
                // poin to the node just after the node storing the dataTodel
                // this in fact removes the node (with dataTodel) from the linkedlist
                current->next = current->next->next;
                return;
            }
            current = current->next;
        }
        
    }

    // To print the values stored in the nodes of the Linked List 
    void printLL() {
        if (head->next == NULL){
            cout << "The Linked List is empty." << endl;
            cout << "data value is " << head->data;
            return;
        }
        // traverse the Linked List and print data in every node
        cout << "The Linked List is: " ;
        Node* current = head;
        while(current->next != NULL){
            cout << current->data << ' ';
            current = current->next;
        }
        // print the last Node data
        cout << current->data << endl;

    }
};


int main(){
    /*
    // Node class testing
    Node node(10);
    cout << "the data in the node is " << node.data << endl;
    cout << "pointer to the next node is " << node.next << endl; 
    */
   LinkedList ll;
   cout << "Insert nodes to the Linked List" << endl;
   ll.append(5);
   ll.append(10);
   ll.append(15);
   ll.printLL();
   cout << " Delete 15 from the Linked List " << endl;
   ll.remove(15);
   ll.printLL();
   cout << "delete head from the Linked List" << endl;
   ll.remove(0);
   ll.printLL();
   cout << "append 100 at the head of the Linked List " << endl;
   ll.appendAthead(100);
   ll.printLL();
  return 0;
}