/*
A binary search tree is a special form of binary tree where for any sub-tree
left node <= root node
right node >=  root node
left node < any node on the right
*/
#include <iostream>

class Node{
    public:
        int data;
        Node* leftChild;
        Node* rightChild; // the child nodes of a node
    // constructor for Node
    public:

    // constructor for Node
    Node(int i){
        data = i;
        leftChild = NULL;
        rightChild = NULL;

    }

    void insertNode(int val){
        if (val <= data){
            if (leftChild == NULL){
                leftChild = new Node(val);
            }
            else{
                leftChild->insertNode(val); // recursion to add below the left child
            }
        }
        else{
            if(rightChild == NULL){
                rightChild = new Node(val);
            }
            else{
                rightChild->insertNode(val); // recursion to add below the right child
            }
        }


        }

        bool isAvailable(int val){
        std::cout << std::endl;
        // checks if a value is available in the binary search tree
        if(val == data){

            std::cout << val << " is avalable" << std::endl;
            return true;
        }
        else if(val <= data){ //check left nodes
            if(leftChild == NULL){ // if leftChild is empty

                std::cout << val << " is not avalable" << std::endl;
                return false;
            }
            else{
                return leftChild->isAvailable(val); // recursion on leftChild
            }
        }
        else { // check righ child nodes
            if(rightChild == NULL){

                std::cout << val << " is not avalable" << std::endl;
                return false; // if rightChild is empty
            }
            else{
                return rightChild->isAvailable(val); // recursion on rightChild
            }

        }

        }

        int treeLength(){
        // this function calculates the length of the tree i.e., number of nodes in the tree
        int treeLen = 0;
        if(leftChild != NULL){
            leftChild->treeLength();
        }
        treeLen += 1; // count that node
        if(rightChild != NULL){
            rightChild->treeLength();
        }
        treeLen += 1;

        return treeLen;
        }

        void printTreeInorder(){
        // print sequence is: leftChild -> root -> rightChild
        if(leftChild != NULL){ // print leftChild
            leftChild->printTreeInorder();
        }
        std::cout << data <<" "; // print the root
        if(rightChild != NULL){ // print the rightChild
            rightChild->printTreeInorder();
        }

        //std::cout << std::endl;
        }

};

int treeLenDFS (Node* tmp, int treeLen){
    // this function calculates the length of the tree using Depth First Search (DFS) algorithm
        if(tmp->leftChild != NULL){
            treeLenDFS(tmp->leftChild, treeLen);
        }
        treeLen += 1;
        if(tmp->rightChild != NULL){
            treeLenDFS(tmp->rightChild, treeLen);
        }
        //return treeLen;
    }

int main(){
    int treeLen = 0;
    Node binaryTree(4);
    Node* head = &binaryTree;
    binaryTree.insertNode(5);
    binaryTree.insertNode(15);
    binaryTree.insertNode(2);
    binaryTree.insertNode(20);
    binaryTree.printTreeInorder();

    binaryTree.isAvailable(3);
    binaryTree.isAvailable(15);
    //std::length(binaryTree);
    //int treeLen = 0;
    //Node* tmp = &binaryTree(4);
    //std::cout << "The length of the tree is " << treeLenDFS(head, 0) << std::endl;
    //treeLen = treeLenDFS(head, 0);
    //std::cout << "The length of the tree is " << treeLen << std::endl;


    return 0;
}
