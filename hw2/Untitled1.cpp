#include <iostream>
using namespace std;

struct Point {
//public:
int coord_x, coord_y;//the coordinates of a point
void reset() //places the point into the origin
{
coord_x = coord_y = 0;
}
void moveX(int x ) //moves the point horizontally with x positions
{
	coord_x++;
}
void moveY(int y ) // moves the point vertically with y positions
{
	coord_y++;
}
void moveXY(int x , int y )// moves the point horizontally and vertically
{
	coord_x++;
	coord_y++;
}
};

int main(){
	Point a;
	int n;
	cin>>a.coord_x;
	cin>>a.coord_y;
	cin>>n;
	a.reset();	
	for(int i=0;i<n;i++){
		a.moveX(i);
		cout<<a.coord_x<<""<<a.coord_y;
		cout<<endl;
	}
	for(int i=0;i<n;i++){
		a.moveY(i);
		cout<<a.coord_x<<""<<a.coord_y;
		cout<<endl;
	}
	for(int i=0;i<n;i++){
		a.coord_x--;
		cout<<a.coord_x<<""<<a.coord_y;
		cout<<endl;
	}
	for(int i=0;i<n;i++){
		a.coord_y--;
		cout<<a.coord_x<<""<<a.coord_y;
		cout<<endl;
	}
	for(int i=0;i<n-1;i++){
		a.moveXY(i,i);
		cout<<a.coord_x<<""<<a.coord_y;
		cout<<endl;
	}
	return 0;
}