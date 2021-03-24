#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#define SIZE_KEY       16
#define SIZE_VALUE1    64
#define SIZE_VALUE2    16
#define DEFAULT_TABLESIZE    101
using namespace std;

struct NODE
{
   NODE(const char* Key1 = "\0", const char* fName = "\0",
         const char *tele ="\0", const double sal = 0.0 )
   {
      strcpy(Key, Key1);
      strcpy(FullName, fName);
      strcpy(Tele_No, tele);
      Salary = sal;
      Tax = 0.005 * Salary;
      next = NULL;
   }
   char Key[SIZE_KEY];
   char FullName[SIZE_VALUE1];
   char Tele_No[SIZE_VALUE2];
   double Salary;
   double Tax;
   NODE *next;
};

class Hashtable
{
   private:
      int table_size;
      NODE** table;
      int size;
      long hashString(char* Key);
      NODE* find(char* Key);
      NODE* current_entry;
      int current_index;
   public:
      Hashtable(int T = DEFAULT_TABLESIZE);//constructor
      virtual ~Hashtable();//destructor
      bool put(NODE *);
      bool get(NODE *);
      bool contains(char* Key);
      bool remove(char* Key);
      void removeAll();
      int getSize();
      void initIterator();
      bool hasNext();
      void getNextKey(char* Key);
      friend void disp(NODE *);
};

Hashtable::Hashtable(int T)
{
   size = 0;
   table_size = T;
   table = new NODE*[table_size];
   for(int i=0; i<table_size; i++)
   {
      table[i] = NULL;
   }
}

Hashtable::~Hashtable()
{
   removeAll();
   delete[] table;
}

void disp(NODE *N1)
{
 cout << "\nKey:      " << N1->Key << "\nFullName: "
      << N1->FullName << endl;
}

bool Hashtable::put(NODE *N)
{//start put
   if(find(N->Key) != NULL)
   {
      return false;
   }
   NODE* entry = new NODE(N->Key, N->FullName,N->Tele_No, N->Salary);
   int bucket = hashString(N->Key);
   entry->next = table[bucket];
   table[bucket] = entry;
   size++;
   return true;
}//end put


bool Hashtable::get(NODE* N)
{//start get
   NODE* temp = find(N->Key);
   if(temp == NULL)
   {
      N->FullName[0] = '\0';
      return false;
   }
   else
   {
      strcpy(N->FullName, temp->FullName);
      strcpy(N->Tele_No, temp->Tele_No);
      N->Salary = temp->Salary;
      N->Tax = temp->Tax;
      return true;
   }
}//end get

bool Hashtable::contains(char* Key)
{//start contains
   if(find(Key) == NULL)
   {
      return false;
   }
   else
   {
      return true;
   }
}//end contains


bool Hashtable::remove(char* Key)
{//start remove
   int bucket = hashString(Key);
   NODE* temp = table[bucket];
   if(temp == NULL)
   {
      return false;
   }
   else if(strcmp(Key, temp->Key) == 0)
   {
      table[bucket] = temp->next;
      delete temp;
      size--;
      return true;
   }
   else
   {
      NODE* temp_next = temp->next;
      while(temp_next != NULL)
      {
         if(strcmp(Key, temp_next->Key) == 0)
         {
            temp->next = temp_next->next;
            delete temp_next;
            size--;
            return true;
         }
         temp = temp->next;
         temp_next = temp_next->next;
      }
   }
   return false;
}//end remove


void Hashtable::removeAll()
{//start removeAll
   for(int i=0; i<table_size; i++)
   {
      NODE* temp = table[i];
      while(temp != NULL)
      {
         NODE* next = temp->next;
         disp(temp);
         delete temp;
         temp = next;
      }
   }
   size = 0;
}//end removeAll

int Hashtable::getSize()
{
   return size;
}

NODE* Hashtable::find(char* Key)
{ //start find
   int bucket = hashString(Key);
   NODE* temp = table[bucket];
   while(temp != NULL)
   {
      if(strcmp(Key, temp->Key) == 0)
      {
         return temp;
      }
      temp = temp->next;
   }
   return NULL;
}//end find



long Hashtable::hashString(char* Key)
{//start hashString
   int n = strlen(Key);
   long h = 0;
   for(int i=0; i<n; i++)
   {
      //To get almost fair distributions of nodes over the array
      h = (h << 3) ^ Key[i];
   }
    return abs(h % table_size );
}//end hashString

void Hashtable::initIterator()
{//start initIterator
   current_entry = NULL;
   current_index = table_size;
   for(int i=0; i<table_size; i++)
   {
      if(table[i] == NULL)
      {
          continue;
      }
      else
      {
         current_entry = table[i];
         current_index = i;
         break;
      }
   }
}//end initIterator

bool Hashtable::hasNext()
{
   if(current_entry == NULL)
   {
      return false;
   }
   else
   {
      return true;
   }
}
void Hashtable::getNextKey(char* Key)
{
   if(current_entry == NULL)
   {
      Key[0] = '\0';
      return;
   }
   strcpy(Key, current_entry->Key);
   if(current_entry->next != NULL)
   {
      current_entry = current_entry->next;
   }
   else
   {
     for(int i=current_index+1; i<table_size; i++)
     {
        if(table[i] == NULL)
        {
           continue;
        }
        current_entry = table[i];
        current_index = i;
        return;
     }
     current_entry = NULL;
     current_index = table_size;
   }
}

void dispAll(Hashtable* hashtable);

int main()
{
  /* char temp1[SIZE_KEY];
   Hashtable* hashtable = new Hashtable();

   NODE N1("389","Mariam");

   if(!hashtable->contains(N1.Key))
   {
      cout << "\nAdding node:  ";
      disp(&N1);
      hashtable->put(&N1);
   }

   strcpy(N1.Key, "314");
   strcpy(N1.FullName, "Zeki");

   if(!hashtable->contains(N1.Key))
   {
      cout << "\nAdding node:  ";
      disp(&N1);
      hashtable->put(&N1);
   }

   strcpy(N1.Key, "320");
   strcpy(N1.FullName, "Murad");

   if(!hashtable->contains(N1.Key))
   {
      cout << "\nAdding node:  ";
      disp(&N1);
      hashtable->put(&N1);
   }

   strcpy(N1.Key, "768");
   strcpy(N1.FullName, "Hassan");

   if(!hashtable->contains(N1.Key))
   {
      cout << "\nAdding node:  ";
      disp(&N1);
      hashtable->put(&N1);
   }

   strcpy(N1.Key, "756");
   strcpy(N1.FullName, "Ali");

   if(!hashtable->contains(N1.Key))
   {
      cout << "\nAdding node:  ";
      disp(&N1);
      hashtable->put(&N1);
   }

   dispAll(hashtable);

    strcpy(temp1,"314");
   hashtable->remove(temp1);
   cout << "\n\nAfter removing 314:" << endl;
   dispAll(hashtable);
   cout << "\n\nDestroying hashtable:" << endl;
   delete hashtable;
*/

char temp1[SIZE_KEY];
   Hashtable* hashtable = new Hashtable();
NODE N1;
char *t;

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
            cout<<"Enter name to be inserted: ";
            cin.get(N1.FullName,100);
            //cout<<"Enter password to be inserted: ";
            //cin.get(N1.Key,100);
hashtable->put(&N1);


   /*if(!hashtable->contains(N1.Key))
   {
      cout << "\nAdding node:  ";
      disp(&N1);
      hashtable->put(&N1);
   }*/
            break;
        case 2:
            cout<<"Enter key of the element to be deleted: ";

            cin.get(N1.Key,100);

            hashtable->remove(N1.Key);

            break;


      /* case 3:
            cout<<"Enter key of the element to find: ";
           cin.get(N1.Key,100);
           if(!hashtable->contains(N1.Key)){
                cout<<"Enter password ";
                cin.get(N1.FullName,100);
                strcpy(t,N1.FullName);
char *l, *c;
 strcpy(l,N1.Key);
  strcpy(c,find(l));

                if(strcmp(c,t)!=0)
                    cout<<"Not correct";
           }



            break;*/

        case 4:
            exit(1);
        default:
           cout<<"\nEnter correct option\n";
       }
    }



   return 0;
}

void dispAll(Hashtable *hashtable)
{
        NODE N1;
   cout << "\n\nCurrent nodes in hashtable:" << endl;
   hashtable->initIterator();
   while(hashtable->hasNext())
   {
      hashtable->getNextKey(N1.Key);
      hashtable->get(&N1);
      disp(&N1);
   }
}
