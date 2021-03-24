#include <iostream>

using namespace std;
int main(){
	int i,n, v[256];
	for(i=0;i<255;i++)
	v[i]=0;
	char a[256],d[256];
	cin.get(d,256);
	cin.get();
	cin.get(a,256);
	char *e;
	char *point=strtok(a, " .,!?");
	char *p=strtok(d, " .,!?");
	char **b,**c;
	b=&point;
	c=&p;
	while(point!=NULL){
		i=0;
		while(p!=NULL){
			if(strcmp(point,p)==0)
			{v[i]++;
			strcat(e,p);
			strcat(e," ");}
			p=strtok(NULL," .,!?");
		}
		i++;
		
		point=strtok(NULL," .,!?");
	}
	cout<<e<<endl;
	for(i=0;i<255;i++)
	cout<<v[i];
}
	