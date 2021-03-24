#include <iostream>
#include<string.h>
#include<cstring>

using namespace std;
#define NMAX 10

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
template<typename T>
class Queue{
private:
    Stack<T> in;
    Stack<T> out;
public:
    void enqueue(T a){
        while(!out.isEmpty()){
            in.push(out.pop());
            cout<<"k"<<endl;
        }
        in.push(a);
    }
    T dequeue(){
        while(!in.isEmpty()){
            out.push(in.pop());
            cout<<"b"<<endl;
        }
        return out.pop();
    }
    T head(){
        if(out.isEmpty()){
            cout<<"nothing here";
        }
        else
        {
            out.peek();
        }
    }
    T tail(){
        while(!out.isEmpty){
            in.push(out.pop());
        }
        return in.peek();
    }
    void display(){
        while(!in.isEmpty()){
            out.push(in.pop());
        }
        while(!out.isEmpty()){
            cout<<out.pop()<<" ";
        }

    }
    Queue(){}
};
int main(){
    Queue<int>a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.enqueue(x);
    }
    a.display();
    a.dequeue();
    cout<<endl;
    a.display();

}