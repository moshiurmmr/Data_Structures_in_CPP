/* 
This program implements a Hash Table uisng list container. It has the following APIs (functionalities):
- insertData: to insert data to the index determined by the key
- deleteData: to delete data from teh index pointed by the key
- printHashTable: to print the hash table

Author: Moshiur Rahman
*/

#include <iostream>
#include <list>

using namespace std;

// HasTable class
class  HashTable
{
private:
    list<int> *table; // table is a pointer to the hash table
    int total_elements; // total elements in the Hash Table
    
    // hash function to convert key to indices of the hash table
    int hashFun(int key){
        return key % total_elements;
    }

public:
    // constructor for the HashTable
    HashTable(int n){
        total_elements = n;
        table = new list<int>[total_elements];
    }

    // insert data to the hash table
    void insertData (int key){
        // get index
        int index = hashFun(key);
        table[index].push_back(key);
    }
    
    // delete a data from the hash table
    void deleteData(int key){
        // get index
        int index = hashFun(key);
        list<int>::iterator i; // i is the iterator of the list
        // iterator through the list at the index of the hash table
        for(i = table[index].begin(); i != table[index].end(); i++){
            if (*i == key)
            break;
        }
        // if the key is found delete it
        if (i != table[index].end())
            table[index].erase(i);
    }

    // print the hash table
    void printHashTable(){
        // loop through the indices of the hash table
        for (int i=0; i < total_elements; i++){
            cout << "index " << i << ": ";
            // loop through each element of the list of the element
            list<int>::iterator j;
            for (j=table[i].begin(); j != table[i].end(); j++ )
            cout << *j << " => " ;
            cout << endl;
        }

    }
};


int main(){
    // create a hash table with 5 indices
    HashTable myHashTable(5);
    // data to be stored in the hash table
    int arr[] = {1, 8, 5, 5, 6 ,8 ,9, 90, 65, 34};

    // insert the data to the hash table
    for (int i =0; i < 10; i++)
        myHashTable.insertData(arr[i]);
    // display the hash table
    cout << " The Hash Table is " << endl;
    myHashTable.printHashTable();

    // delete an element from the hash table
    cout << "Delete 90 from the hash table " << endl;
    myHashTable.deleteData(90);
    myHashTable.printHashTable();
}