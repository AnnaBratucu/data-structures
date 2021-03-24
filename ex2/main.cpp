#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
const int TABLE_SIZE = 128;

/*
 * HashEntry Class Declaration
 */
class HashEntry
{
    public:
        int key;
        int value;
        HashEntry(int key, int value)
        {
            this->key = key;
            this->value = value;
        }
};

/*
 * HashMap Class Declaration
 */
class HashMap
{
    private:
        HashEntry **table;
    public:
        HashMap()
	{
            table = new HashEntry * [TABLE_SIZE];
            for (int i = 0; i< TABLE_SIZE; i++)
            {
                table[i] = NULL;
            }
        }
        /*
         * Hash Function
         */
        int HashFunc(int key)
        {
            return key % TABLE_SIZE;
        }
        /*
         * Insert Element at a key
         */
	void Insert(int key, int value)
	{
            int hash = HashFunc(key);
            while (table[hash] != NULL && table[hash]->key != key)
            {
                hash = HashFunc(hash + 1);
            }
            if (table[hash] != NULL)
                delete table[hash];
            table[hash] = new HashEntry(key, value);
	}
        /*
         * Search Element at a key
         */
        int Search(int key)
	{
	    int  hash = HashFunc(key);
	    while (table[hash] != NULL && table[hash]->key != key)
	    {
	        hash = HashFunc(hash + 1);
	    }
	    if (table[hash] == NULL)
	        return -1;
	    else
	        return table[hash]->value;
        }

        /*
         * Remove Element at a key
         */
        void Remove(int key)
	{
	    int hash = HashFunc(key);
	    while (table[hash] != NULL)
	    {
	        if (table[hash]->key == key)
	            break;
	        hash = HashFunc(hash + 1);
	    }
            if (table[hash] == NULL)
	    {
                cout<<"No Element found at key "<<key<<endl;
                return;
            }
            else
            {
                delete table[hash];
            }
            cout<<"Element Deleted"<<endl;
        }
        ~HashMap()
	{
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                if (table[i] != NULL)
                    delete table[i];
                delete[] table;
            }
        }
};
/*
 * Main Contains Menu
 */
int main()
{
    HashMap hash;
    int key, value;
    int choice;
    while (1)
    {
        cout<<"\n----------------------"<<endl;
        cout<<"Operations on Hash Table"<<endl;
        cout<<"\n----------------------"<<endl;
        cout<<"1.Add new user"<<endl;
        cout<<"2.Login"<<endl;
        cout<<"3.Delete user"<<endl;
        cout<<"4.Update password"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter login ID: ";
            cin>>key;
            cout<<"Enter password: ";
            cin>>value;
            hash.Insert(key, value);
            break;
        case 2:
            cout<<"Enter login ID: ";
            cin>>key;
            if (hash.Search(key) == -1)
            {
	       cout<<"No element found at key "<<key<<endl;
	        continue;}
	       cout<<"Enter password: ";
	       cin>>value;
	       if(hash.Search(key)==value)

           {    cout<<"Correct password";
               continue;}


	    else
	    {

	        cout<<"Not correct!";
	    }
            break;
        case 3:
            cout<<"Enter login ID to be deleted: ";
            cin>>key;
            hash.Remove(key);
            break;
        case 4:
            cout<<"Enter ID of password you want updated: ";
            cin>>key;

            hash.Remove(key);
            cout<<"Put your ID again: ";
            cin>>key;
            cout<<"New password: ";
            cin>>value;
            hash.Insert(key, value);
            break;

        case 5:
            exit(1);
        default:
           cout<<"\nEnter correct option\n";
       }
    }
    return 0;
}
