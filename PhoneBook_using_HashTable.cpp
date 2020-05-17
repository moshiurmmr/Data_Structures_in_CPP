/* 
This program implements a simple phone book with name and phone number using a Hash Table.
It has the following APIs (functionalities):
- insertData: to insert (name and phone number) pair
- deleteData: to delete a phone book entry
- printHashTable: to print the phone book

Author: Moshiur Rahman
*/

#include <iostream>
#include <list>

using namespace std;

#define TABLE_SIZE  10;



// HasTable class
class  HashTable
{
private:
    list< pair <string, int> > *table; // table is a pointer to the hash table
    //int total_elements; // total elements in the Hash Table
    /*
    // hash function to convert key to indices of the hash table
    int hashFun(int key){
        return key % total_elements;
    }
    */

public:
 
    // constructor for the HashTable
    HashTable(){
        int total_elements = TABLE_SIZE;
        table = new list< pair <string, int> > [total_elements];
        //cout << "inside the constructor" << endl;
    }

    // hash function
    int hashFun(const char * str) {
        int hash_i = 565;

        while (*str != '\0') {
            hash_i = ((hash_i << 6) + (int)(*str)) % TABLE_SIZE;
            str++;
        }
        //cout << "insided hashFun " << endl;
        return hash_i % TABLE_SIZE;
}

    // insert data to the hash table
    void insertData (const char *name, int phone_number){
        //cout << "insering a new item in the hash table" << endl;
        // get index
        int index = hashFun(name);
        //cout << "index is " << index << endl;
        table[index].push_back(make_pair(name, phone_number));
        //cout << "insertion of the item finished" << endl;
        
    }


    // delete a data from the hash table
    void deleteData(const char *name){
        // get index
        int index = hashFun(name);
        list<pair <string, int> >::iterator it; // it is the iterator of the list
        // iterator through the list at the index of the hash table
        for(it = table[index].begin(); it != table[index].end(); it++){
            if (it->first == name)
            break;
        }
        // if the name is found delete the (name, phone_number) pair
        if (it != table[index].end())
            table[index].erase(it);
    }

    // print the hash table
    void printHashTable(){
        cout << "\t\t Phone Book \t \t" << endl;
        cout << "Index" << "\t" << "Name" << "\t" << "Phone Number" << endl;
        int table_length = TABLE_SIZE;
        for (int i = 0; i < table_length; i++){
            cout << i << ": \t";
            // loop through each element of the list of the element

            // iterator for the list
            list<pair <string, int> >::iterator it;
            // loop through the indices of the hash table
            
            for (it = table[i].begin(); it != table[i].end(); it++){
                //cout << "inside printHashTable for loop" << endl;
                cout << "\t" << it->first << "\t" << it->second;
            }
            cout << endl;



        }

    }
};


int main(){
    HashTable myHashtable;
    myHashtable.insertData("bidyut", 212);
    myHashtable.insertData("moshiur", 343);
    myHashtable.insertData("moshiur", 613);
    myHashtable.insertData("raman", 723);
    myHashtable.printHashTable();
    cout << "delete entry for bidyut " << endl;
    myHashtable.deleteData("bidyut");
    myHashtable.printHashTable();
    return 0;
}