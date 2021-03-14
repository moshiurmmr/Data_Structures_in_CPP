/*
A doubly linked list cotains data and two pointers -
    - one pointing to the prior node and
    - the other points to the following node.

author: Moshiur Rahman
*/
#include <iostream>

class Node{
/*
The node class consists of three elements:
1. the data
2. a pointer to the previous node
3. a pointer to the next node
*/
    public:
        int data;
        Node* next_node = NULL;
        Node* prev_node = NULL;

        // constructor
        Node(int i){
            data = i;
        }
};

class Linkedlist{
/*
 A doubly linked list consists of the following
 - a pointer to the head of the list
 - append(), a method to insert data to the end of the list
 - appendFront(), a method to insert data to the beginning of the list
 - deleteNode(), a method to remove a data from the list
 - printList(), a method to display the elements of the list
*/
    private:
        Node* head = NULL;
    public:
        void append(int i){
            // if the linked list is empty
            if (head == NULL){
                head = new Node(i);
                return;
            }
            // create a new node
            Node* new_node = new Node(i);
            Node* tmp = head;
            while(tmp->next_node != NULL)
                tmp = tmp->next_node;
            tmp->next_node = new_node;
        }

        void appendFront(int i){
        // append data to the front of the list

            // if the linked list is empty
            if (head == NULL){
                Node* new_node = new Node(i);
                head = new_node;
                return;
            }

            Node* new_node = new Node(i);
            // next_node pointer of the new_node Node points to the head of the linked list
            new_node->next_node = head;
            // new_node becomes the new head of the linked list
            head = new_node;
            //tmp->prev_node = new_node;
            //head = new_node;


        }

        void deleteNode(int i){
        // this method removes a data from the linked list
            Node* tmp = head;

            // if the data is in the head node
            if (head->data == i){
                head = head->next_node;
                std::cout << "Deleting " <<i << " from the head of the list" << std::endl;
                return;
            }

            while(tmp->next_node != NULL){
                if (tmp->next_node->data == i){
                    tmp->next_node = tmp->next_node->next_node;
                    std::cout << "Deleting " << i << " from the list" << std::endl;
                    return;

                }
                tmp = tmp->next_node;
            }
        }

        void printList(){
            std::cout << "The list is: ";
            Node* tmp = head;
            while(tmp->next_node != NULL){
                std::cout << tmp->data << " ";
                tmp = tmp->next_node;
            }
            // print the last node
            std::cout << tmp->data << std::endl;

        }


};

int main(){

    Linkedlist mylist;
    mylist.appendFront(0);
    mylist.append(10);
    mylist.append(20);
    mylist.append(30);
    mylist.appendFront(1);
    mylist.printList();
    mylist.deleteNode(30);
    mylist.printList();


    return 0;
}
