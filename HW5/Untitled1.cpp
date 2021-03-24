#include <iostream.h>


int f(double n){
	int intpart=(int)n;
	double dpart= n-intpart;
	return intpart;
	return dpart;
}
int main(){
	double c=5.2;
	double a;
    a=f(c);
    return a;
}