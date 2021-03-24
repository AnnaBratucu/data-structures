#include <iostream>
using namespace std;

struct Point {
	public:
	int coord_x,coord_y;
	void reset(){
		coord_x=coord_y=0;
	}
	void moveX(int x){
		coord_x=coord_x+1;
	}
	void moveY(int y){
		coord_y++
	}
	void moveXY(intx, int y){
		coord_x++;
		coord_y++;
	}
	struct Triangle{
		Point a,b,c;
	}	
	void swap(Point &A, Point &B){
		int x=A.oord_x;
		A.coord_x=B.coord_x;
		B.coord_x=x;
		
		int y=A.coord_y;
		A.coord_y=B.coord_y;
		B.coordy=y;
	}
	float Area(float a float b, float c){
		float S,p;
		p=(a+b+c)/2;
		S=sqrt((p*(p-a)*(p-b)*(p-c)));
		retur S;
	}
	float Distance(Point a,Point b){
		float c;
		c=sqrt((b.coord_x-a.coord_x)*b.coord_x-a.coord_x)-b.coord_y-a.coord_y)(bcoord_y-acoord_y));
		return c;
	}
}