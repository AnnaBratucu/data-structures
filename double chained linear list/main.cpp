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
void addFirst(/*T x*/) {
    int ok=0;
            struct list_elem<T> *paux,*c;

            paux = new struct list_elem<T>;
            //paux->info = x;
            cin>>c->info;
            plast->next=c;
            plast=c;
            plast->next=NULL;


           // paux->prev = NULL;
           // paux->next = pfirst;


            c=pfirst;
            while(c){
                if(paux->info==c->info)
                    ok=1;
                c=c->next;
            }
            if(ok==0){

            if (pfirst != NULL) pfirst->prev = paux;
            pfirst = paux;

            if (plast==NULL) plast=pfirst;}

            c=pfirst;
            int ord, aux;
            do{
                c=pfirst;
                ord=1;
                while(c->next)
                {
                    if(c->info>c->next->info){
                        aux=c->info;
                        c->info=c->next->info;
                        c->next->info=aux;
                        ord=0;
                    }
                    c=c->next;
                }
                }while(ord==0);



        }

        void div(int z){
            int cont=0;
            struct list_elem<T> *paux,*c;
             c=pfirst;

            while(c){
                if(c->info%z==0)
                    cont++;
                c=c->next;
            }
           cout<<cont;
        }
        void great(){
            int cont=0;
            struct list_elem<T> *paux,*c;
            c=pfirst;
            while(c){

                if(c->info>pfirst->info)
                    cont++;
                c=c->next;
            }
                       cout<<cont;
        }
        void occur(int y){
            int cont=0;
            struct list_elem<T> *paux,*c;
            c=pfirst;
            while(c){

                if(c->info==y)
                    cont++;
                c=c->next;
            }
                       cout<<cont;
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
struct list_elem<T>* findFirstOccurrence(T x) {
            struct list_elem<T> *paux;

            paux = pfirst;
            while (paux != NULL) {
                if (paux->info == x)
                    return paux;
                paux = paux->next;
            }
            return NULL;
        }

        struct list_elem<T>* findLastOccurrence(T x) {
            struct list_elem<T> *paux;

            paux = plast;
            while (paux != NULL) {
                if (paux->info == x)
                    return paux;
                paux = paux->prev;
            }

            return NULL;
        }
void removeFirstOccurrence(T x) {
            struct list_elem<T> *px;

            px = findFirstOccurrence(x);

            if (px != NULL) {
                if (px->prev != NULL)
                    px->prev->next = px->next;
                if (px->next != NULL)
                    px->next->prev = px->prev;

                if (px->prev == NULL) // px == pfirst
                    pfirst = px->next;

                if (px->next == NULL) // px == plast
                    plast = px->prev;

                delete px;
            }
        }

  void removeLastOccurrence(T x) {
            struct list_elem<T> *px;

            px = findLastOccurrence(x);

            if (px != NULL) {
                if (px->prev != NULL)
                    px->prev->next = px->next;
                if (px->next != NULL)
                    px->next->prev = px->prev;

                if (px->prev == NULL) // px == pfirst
                    pfirst = px->next;

                if (px->next == NULL) // px == plast
                    plast = px->prev;

                delete px;
            }
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

int main()
{
	LinkedList<int> l;

	l.addFirst(89);
	l.addFirst(34);
	l.addFirst(79);
	l.addFirst(34);
	l.addFirst(2);
	l.addFirst(89);

        l.printList();
        l.div(2);
        cout<<endl;
        l.great();
        cout<<endl;
        l.occur(89);
       // l.removeLastOccurrence(89);
	//l.printList();

    //    l.removeLast();
	//l.removeFirst();
	//l.printList();

	return 0;
}
