/*
This program creates a circular linked list from a singly linked list.
In such a circular linked list, for the last node, the pointer to the next node points to the head of the list.

Author: Moshiur Rahman
*/

#include <iostream>

class Node{
/*
A node contains the data and a pointer to the next node.
*/
    public:
        int data = 0;
        Node* next_node = NULL;

        //constructor
        Node(int i){
            data = i;
        }
};

class Linkdedlist{
    private:
        Node* head = NULL; // head of the list
        Node* tail = NULL; // tail of the list
    public:
        void append(int i){
        // a function to append data to the end of the list
            // if the list is empty
            if(head == NULL){
                Node* new_node = new Node(i);
                head = new_node;
                new_node->next_node = head;
                std::cout << "Inserting the head node " << i << std::endl;

                return;

            }
            // create a new node
            Node* new_node = new Node (i);
            Node* tmp = head;
            while(tmp->next_node != head)
                tmp = tmp->next_node;
            // end of the list is reached. Add new_node to the end of the list
            std::cout << "Inserting " << i << std::endl;
            tmp->next_node = new_node;
            // point next_node of the new_node to the head (hence the list becomes circular!)
            new_node->next_node = head;
            tail = new_node; // new tail of the list
        }

        void printList(){
            std::cout << "The list is: ";
            Node* tmp = head;
            while(tmp->next_node != head){
                //std::cout << "inside while loop in printList()" << std::endl;
                std::cout <<tmp->data << " ";
                tmp = tmp->next_node;
            }
            // print the last node
            tail = tmp;
            std::cout << tail->data << std::endl;
            std::cout <<"Now let's check if the last node points to the head of the linked list" << std::endl;
            std::cout << "head is: " << head << std::endl;
            std::cout << "last node points to: " << tail->next_node << std::endl;
        }

        void removeItem(int i){
            // if the data is in the head
            if(head->data == i){
                // if head node is the only node in the list
                if(head->next_node == head){
                    head = NULL;
                    std::cout<<"Deleting the only node in the list" << std::endl;
                    return;
                }
                std::cout << "Deleting the head node " << i << std::endl;
                head = head->next_node;
                tail->next_node = head;

                return;

            }

            Node* tmp = head;
            Node* tmp_prevNode = NULL;

            while(tmp->next_node != head){
                if(tmp->next_node->data == i){
                    // delete the node containing the data
                    std::cout<<"Deleing " << i << " from the list." << std::endl;
                    tmp->next_node = tmp->next_node->next_node;
                    return;
                }
                tmp_prevNode = tmp;
                tmp = tmp->next_node;
            }
            // if the data is in the last node
            if(tmp->data == i){
                // delete the last node containng the data
                std::cout<<"Deleting the last data " << i << " from the list." << std::endl;
                tmp = tmp_prevNode;
                tmp->next_node = head;
            }

        }
};

int main(){

    Linkdedlist mylist;
    mylist.append(2);
    mylist.append(4);
    //mylist.append(6);
    mylist.printList();
    std::cout<<std::endl;
    std::cout<<std::endl;
    //mylist.removeItem(4); // works
    //mylist.removeItem(6); //works
    mylist.removeItem(2); // bug, head becomes the tail :(
    mylist.printList();


return 0;
}
