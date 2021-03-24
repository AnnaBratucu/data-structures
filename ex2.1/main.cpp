#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;




class LinkedHashEntry {



private:

      char value[100];
      LinkedHashEntry *next;
public:
    char key[100];
      LinkedHashEntry(char key[100], char value[100]) {
           this->key[100] = key[100];
            this->value[100] = value[100];
            this->next = NULL;
      }

      char getKey() {
            return key[100];
      }

      char getValue() {
            return value[100];
      }

      void setValue(char value[100]) {
            this->value[100] = value[100];
      }

      LinkedHashEntry *getNext() {
            return next;
      }

      void setNext(LinkedHashEntry *next) {
            this->next = next;
      }
};

const int TABLE_SIZE = 128;

class HashMap {
private:
      LinkedHashEntry **table;
public:
      HashMap() {
            table = new LinkedHashEntry*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
                  table[i] = NULL;
      }

      int get(char key) {
            int hash = (key % TABLE_SIZE);
            if (table[hash] == NULL)
                  return -1;
            else {
                  LinkedHashEntry *entry = table[hash];
                  while (entry != NULL && entry->getKey() != key)
                        entry = entry->getNext();
                  if (entry == NULL)
                        return -1;
                  else
                        return entry->getValue();
            }
      }

      void put(char key[100], char value[100]) {
            int hash = (key[100] % TABLE_SIZE);
            if (table[hash] == NULL)
                  table[hash] = new LinkedHashEntry(key, value);
            else {
                  LinkedHashEntry *entry = table[hash];
                  while (entry->getNext() != NULL)
                        entry = entry->getNext();
                  if (entry->getKey() == key[100])
                        entry->setValue(value);
                  else
                        entry->setNext(new LinkedHashEntry(key, value));
            }
      }





      void remove(char key) {
            int hash = (key % TABLE_SIZE);
            if (table[hash] != NULL) {
                  LinkedHashEntry *prevEntry = NULL;
                  LinkedHashEntry *entry = table[hash];
                  while (entry->getNext() != NULL && entry->getKey() != key) {
                        prevEntry = entry;
                        entry = entry->getNext();
                  }
                  if (entry->getKey() == key) {
                        if (prevEntry == NULL) {
                             LinkedHashEntry *nextEntry = entry->getNext();
                             delete entry;
                             table[hash] = nextEntry;
                        } else {
                             LinkedHashEntry *next = entry->getNext();
                              delete entry;
                             prevEntry->setNext(next);
                        }
                  }
            }
      }

      ~HashMap() {
            for (int i = 0; i < TABLE_SIZE; i++)
                  if (table[i] != NULL) {
                        LinkedHashEntry *prevEntry = NULL;
                        LinkedHashEntry *entry = table[i];
                        while (entry != NULL) {
                             prevEntry = entry;
                             entry = entry->getNext();
                             delete prevEntry;
                        }
                  }
            delete[] table;
      }
};

int main()
{
  HashMap hash;
    char key[100], value[100];
      cin.get(value,100);
    cin.get();
    cin.get(key,100);
    hash.put(key, value);



    int choice;
    while (1)

    {
        cout<<"\n----------------------"<<endl;
        cout<<"Operations on Hash Table"<<endl;
        cout<<"\n----------------------"<<endl;
        cout<<"1.Insert element into the table"<<endl;
        cout<<"2.Delete element at a key"<<endl;
        cout<<"3.Search element from the key"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter element to be inserted: ";
            cin.get(value,100);

            cout<<"Enter key at which element to be inserted: ";
            cin.get(key,100);
            hash.put(key, value);
            break;
        case 2:
            cout<<"Enter key of the element to be deleted: ";
            cin.get(key,100);
            hash.remove(key[100]);
            break;
        case 3:
            cout<<"Enter ID: ";
             cin.get(key,100);
             cin.get();
             cout<<"Enter password: ";
             cin.get(value,100);
             break;

       /* case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>key;
            if (hash.Search(key) == -1)
            {
	        cout<<"No element found at key "<<key<<endl;
	        continue;
	    }
	    else
	    {
	        cout<<"Element at key "<<key<<" : ";
	        cout<<hash.Search(key)<<endl;
	    }
            break;
        case 3:
            cout<<"Enter key of the element to be deleted: ";
            cin>>key;
            hash.Remove(key);
            break;
        case 4:
            exit(1);
        default:
           cout<<"\nEnter correct option\n";
       }*/
        }

    return 0;




}}
