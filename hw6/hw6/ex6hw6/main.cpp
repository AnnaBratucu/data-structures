#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

template<typename T> struct list_elem {
    T info;
    struct list_elem<T> *next, *prev;
};

template <typename T> class LinkedList {
    public:
        struct list_elem<T> *pfirst, *plast;
void addFirst(T x) {
            struct list_elem<T> *paux;

            paux = new struct list_elem<T>;
            paux->info = x;
            paux->prev = NULL;
            paux->next = pfirst;

            if (pfirst != NULL) pfirst->prev = paux;
            pfirst = paux;

            if (plast==NULL) plast=pfirst;
        }

        void addLast(T x) {
            struct list_elem<T> *paux;

            paux = new struct list_elem<T>;
            paux->info = x;
            paux->prev = plast;
            paux->next = NULL;

            if (plast != NULL) plast->next = paux;
            plast = paux;
            if (pfirst == NULL) pfirst = plast;
        }
void removeFirst() {
            struct list_elem<T>* paux;

            if (pfirst != NULL) {
                paux = pfirst->next;
                if (pfirst == plast) plast = NULL;
                delete pfirst;
                pfirst = paux;
                if (pfirst != NULL) pfirst->prev = NULL;
            }
            else cout<<"The list is empty"<<endl;
		}

	void removeLast() {
            struct list_elem<T> *paux;

            if (plast != NULL) {
                paux = plast->prev;
                if (pfirst == plast) pfirst = NULL;
                delete plast;
                plast = paux;
                if (plast != NULL) plast->next = NULL;
            }
            else cout<<"The list is empty"<<endl;
        }




int isEmpty() {
            return (pfirst == NULL);
        }

    LinkedList() {
        pfirst = plast = NULL;
    }

 void printList()
  {
	struct list_elem<T> *p;

	p = pfirst;
	while (p != NULL)
	{
		printf("%d\n", p->info);
		p = p->next;
	}
  }

};
template<typename T> class Stack {
    private:
        LinkedList<T> ll;
    public:
        void push(T x) {
            ll.addLast(x);
        }

        T pop() {
            if (isEmpty()) {
	T x;
                      return x;
            }

            T x = ll.plast->info;
            ll.removeLast();
            return x;
        }
        T peek() {
            if (isEmpty()) {
	T x;
                	return x;
            }

            return ll.plast->info;
        }

        int isEmpty() {
            return (ll.isEmpty());
	}
	int deleteFirst(){
        if (isEmpty()) {
	T x;
                      return x;
            }
            T x = ll.plast->info;
            ll.removeFirst();
            return x;
	}
	int display(){
        ll.printList();
	}
};



int main()
{

	Stack<int> l;
	l.push(89);
	l.push(34);
	l.pop();
	l.push(55);
	l.push (40);
	l.push(65);
	l.pop();

	l.deleteFirst();
	return l.display();

      //  cout<<l.peek()<<"\n";







	return 0;
}
