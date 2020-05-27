/* 
This program implements a simple phone book with name and phone number using a Hash Table.
It has the following APIs (functionalities):
- insertData: to insert (name and phone number) pair
- deleteData: to delete a phone book entry
- printHashTable: to print the phone book

Author: Moshiur Rahman

To do:
- Fix bug in deleteData(). For entries with the same key, it only removes the first entry. 
It should remove all the entries pertaining to a key.
- For insertData() function, it should check if the name for the input (name, phone_number)
is already existing, if so, should print a message notifying the user.
- make the phone book interactive. When run, it should display instructions on how to insert,
delete phone entries, how to display the phone book, etc.
- make a GUI for the phone book! -- stress goal :)
*/

#include <iostream>
#include <list>

using namespace std;

#define TABLE_SIZE  10; // size of the Phone Book



// HasTable class
class  HashTable
{
private:
    list< pair <string, int> > *phoneBook; // phoneBook is a pointer to the phone book hash table

public:
 
    // constructor for the HashTable
    HashTable(){
        int total_elements = TABLE_SIZE;
        phoneBook = new list< pair <string, int> > [total_elements];
    }

    // hash function to convert name to indices of the hash table (phone book)
    int hashFun(const char * str) {
        int hash_i = 565;

        while (*str != '\0') {
            hash_i = ((hash_i << 6) + (int)(*str)) % TABLE_SIZE;
            str++;
        }
        //cout << "insided hashFun " << endl;
        return hash_i % TABLE_SIZE;
}

    // insert a (name, phone_number) pair in the phone book
    void insertData (const char *name, int phone_number){
        // get index
        int index = hashFun(name);
        // insert the (name, phone_number) pair at the tail of the list
        phoneBook[index].push_back(make_pair(name, phone_number));

    }

    // search an entry from the phone book
    int searchData(const char * name){
        // get the index for the name 
        int index = hashFun(name);
        // iterator for traversing the list at the index of the phone book
        list<pair <string, int> >::iterator it;
        cout << "Below is the phone number(s) result for " << name << endl;
        for (it = phoneBook[index].begin(); it != phoneBook[index].end(); it++){
            if (it->first == name){
                {cout << it->second;
                cout << "\t";}
                cout << endl;
            }
            else
                cout << "There is no phone book entry for " << it->first << "\t please check the name";
                     
        }
    }

    // delete an entry from the phone book
    void deleteData(const char *name){
        // get index
        int index = hashFun(name);
        list<pair <string, int> >::iterator it; // it is the iterator of the list
        // iterator through the list at the index of the hash table
        for(it = phoneBook[index].begin(); it != phoneBook[index].end(); it++){
            if (it->first == name)
            break;
        }
        // if the name is found delete the (name, phone_number) pair
        if (it != phoneBook[index].end())
            phoneBook[index].erase(it);
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
            
            for (it = phoneBook[i].begin(); it != phoneBook[i].end(); it++){
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
    cout << "Search phone numbers for moshiur" << endl;
    myHashtable.searchData("moshiur");
    //myHashtable.printHashTable();
    cout << "delete entry for moshiur " << endl;
    myHashtable.deleteData("moshiur");
    myHashtable.printHashTable();
    return 0;
}