#include <iostream>
#include<string.h>
#include<cstring>
#define NMAX 1000

using namespace std;


template<typename T>
class Stack {
    private:
		// an array of NMAX dimension
		T stackArray[NMAX];

        int topLevel;
    public:
        void push(T x) {

			if (topLevel >= NMAX - 1)
			{
            	cout<<"The stack is full: we have already NMAX elements!\n";
                //exit the function without making anything
				return;
        	}

            stackArray[++topLevel] = x;
        }

        int isEmpty() {

            return (topLevel < 0);
		}
		 T pop() {
        // extracts and element from the stack array and returns the new top
            if (isEmpty()) {
                // the extraction is made only if the array is not empty
               cout<<"The stack is empty! \n";
                T x;
                return x;
            }
            return stackArray[topLevel--];
            }

        T peek() {
             // returns the top of the stack
              if (isEmpty()) {

                 cout<<"The stack is empty! \n";
                 T x;
                 return x;
               }
            return stackArray[topLevel];
        }
        T getTopLevel(){ return topLevel;}

        Stack() {
              topLevel = -1;
            }

        ~Stack() { }
};
int main(){
    Stack <int> b;
    char a[100],c[100];
    int k=0;
    cout<<"a string:";
    cin.get(a,256);
    for(int i=strlen(a)-1;i>=0;i--){
        int m;
        m=int(a[i]);
        b.push(m);
    }
    for(int i=0;i<strlen(a);i++)
    {
        if(char(b.peek())==' ')
        {
            c[k]=' ';
            k++;
            b.pop();
        }
        else
            if(b.peek()==65){
                c[k]='X';
                k++;
                b.pop();
            }
            else
                if(b.peek()==90){
                    c[k]='C';
                    k++;
                    b.pop();
                }
                else
                {
                    int n;
                    n=b.pop()+3;
                    c[k]=char(n);
                    k++;
                }
    }
    cout<<c;
}