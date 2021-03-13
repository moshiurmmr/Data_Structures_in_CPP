/*

A singlly linked list consists of nodes that points to the next nodes only.
This is a sinlgy linked list for integers.

author: Moshiur Rahman

To do: provision for deleting all the duplicate entries.
*/


#include <iostream>

class Node {
/*
    a Node class for nodes in the linked list. It contains two elements one
    containting the data and the other is a pointer to the next node
*/
    public:
        // data element in the node
        int data;
        Node* next_node; // pointer to the next node

    public:
        // constructor with input data
        Node(int i){
            data = i;
            next_node = NULL;
        }

        // default constructor
        Node(){
            //data = 0;
            next_node = NULL;
        }
        void printNode(){
            std::cout << data << std::endl;
        }
};

// class for a singly linked list

class Linkedlist{
/*
    The Linkedlist class contains a pointer to the head of the list. It also contains the following functions
    - insert() - to insert a new node at the end of the list
    - deleteNode() - to delete a node/data from the list
    - printList() - to print the elements of the list
*/
    private:
        // a pointer to the head of the linked list
        Node* head = NULL;

    public:
        // insert data to the end of the list
        void append(int i){
            if (head == NULL){
                head = new Node(i);
                return;
            }
            // create a new Node
            Node* new_node = new Node(i);
            // a tmp node pointer to traverse the linked list
            Node* tmp;
            tmp = head;
            // check to see if tmp reached the ned of the linked list
            while (tmp->next_node != NULL)
                tmp = tmp->next_node;
            // insert the new node to the end of the linked list
            //tmp->next_node = new Node(i);
            tmp->next_node = new_node;
            //std::cout << "Append " << i <<" to the end of the list" << std::endl;

        }

        // delete node/data from the end of the list
        void deleteNode(int i){
            Node* tmp = head;
            //Node* prior_node;

            // if the data is in the first node
            if (head->data == i){
                head = head->next_node;
                std::cout <<"Deleting " <<i << " from the list." <<std::endl;
                // if it is the only node in the list
                if (head == NULL){
                    std::cout <<"The list empty now." << std::endl;
                }

            }
            // for all other cases
            else {
                while(tmp->next_node != NULL){
                    //prior_node = tmp;
                    if (tmp->next_node->data == i){
                        tmp->next_node = tmp->next_node->next_node;
                        std::cout << "deleting " << i << " from the list" << std::endl;
                        return;
                    }
                    tmp = tmp->next_node;
                }
                // if the data to be delted is not in the list
                if (tmp->next_node == NULL){
                    std::cout << i << " is not in the list" << std::endl;
                    return;
                }

            }

        }

        // print linked list
        void printList(){
            if (head == NULL){
                std::cout << "Nothing to display, the list is empty." << std::endl;
                return;
            }

            // a pointer to traverse the linked list
            std::cout << "Print the data in the linked list: " << std::endl;
            Node* tmp = head;
            //tmp = head;
            while (tmp->next_node !=NULL){
                //std::cout << "inside the while loop" << std::endl;
                std::cout << tmp->data << ' ';
                tmp = tmp->next_node;
            }
            // print the last node
            std::cout << tmp->data << std::endl;
        }

};




int main(){
/*
//test Node class
    Node* node2 = new Node(109);
    Node node1(10);
    node1.printNode();
    node2->printNode();
*/
Linkedlist ll1;
ll1.append(5);
ll1.append(10);
ll1.append(20);
ll1.append(10);
ll1.printList();
ll1.deleteNode(10);
ll1.printList();
ll1.deleteNode(10);
ll1.printList();


//std::cout << "Linked list after deletion " << std::endl;
ll1.deleteNode(22);
ll1.printList();
/*
ll1.deleteNode(10);
ll1.printList();
ll1.deleteNode(20);
//ll1.deleteNode(45);
ll1.printList();
*/
return 0;
}
