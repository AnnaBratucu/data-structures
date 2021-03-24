#include <iostream>
#include <cstring>
#include <string>
#include  <bitset>

using namespace std;
int main(){
	char a[256];
	cin.get(a,256);
	char *point=strtok(a, ".");
	char **b;
	b=&point;
	while(point!=NULL){
		cout<<point<<endl;
		point=strtok(NULL,".");
	}
	union{
		float input;
		int output;
	} data;
	cout<<endl;
	cin>>data.input;
	bitset<sizeof(float) * CHAR_BIT>  bits(data.output);
	cout<<bits<<endl;
}