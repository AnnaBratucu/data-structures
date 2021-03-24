#include <iostream>
#include<string.h>
#include<cstring>
#include<math.h>

using namespace std;
#define NMAX 100

struct point {

    int coord_x, coord_y;//the coordinates of a point
};

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
        int getTopLevel(){ return topLevel;}

        Stack() {
              topLevel = -1;
            }

        ~Stack() { }
};


float distanta(point a, point b){
    float c;
    c=sqrt((b.coord_x-a.coord_x)*(b.coord_x-a.coord_x)-(b.coord_y-a.coord_y)*(b.coord_y-a.coord_y));
    return c;
}

int main(){
    Stack <point> a,b,c;
    point v[30];
    point m;
    m.coord_x=0; m.coord_y=0;
    cout<<"Number of points: ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<endl<<"x: ";
        cin>>v[i].coord_x;
        cout<<endl<<"y: ";
        cin>>v[i].coord_y;
        a.push(v[i]);
    }
    cout<<endl<<"top level"<<a.getTopLevel();
    for(int i=0;i<n;i++){
        if(b.getTopLevel()==0&&c.getTopLevel()==0){
            point x;
            x=a.pop();
            b.push(x);
            c.push(x);
        }
        if(distanta(m,b.peek())<distanta(m,c.peek())){
            point z,y;
            z=b.pop();
            y=c.pop();
            b.push(y);
            c.push(z);
        }

        if(distanta(m,a.peek())>distanta(m,b.peek())){
            b.push(a.pop());
        }
        else
            if(distanta(m,a.peek())>distanta(m,c.peek()))
            {
                point z;
                z=c.pop();
                point x;
                x=a.pop();
                c.push(x);
                c.push(z);
            }
            else
                c.push(a.pop());
        if(distanta(m,b.peek())==distanta(m,c.peek())){
           c.pop();
        }
    }
    while((c.getTopLevel()!=0)|| (b.getTopLevel()!=0)){
            if(c.getTopLevel()==0){
                point x;
                x=b.pop();
                a.push(x);
            }
            if(distanta(m,b.peek())>distanta(m,c.peek()))
            {
                point x;
                x=b.pop();
                a.push(x);
            }
            else
            {
                point x;
                x=c.pop();
                a.push(c.pop());
            }

    }
    for(int i=0;i<n;i++){
        point x;
        x=a.pop();
        cout<<endl<<"Point: "<<x.coord_x<<" "<<x.coord_y;
    }


}