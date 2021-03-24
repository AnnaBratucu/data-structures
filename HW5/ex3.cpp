#include <iostream>

using namespace std;

int main()
{
   char c1[5];
    c1[0]='a';
    c1[1]='e';
    c1[2]='i';
    c1[3]='o';
    c1[4]='u';
    char c2[5];
    cout<<"Introduce a string here: ";
    cin>>c2;
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){

                if (c2[i]==c1[j]){

                    cout<<c2[i]<<"p"<<c2[i];
                    break;
                    }
                else {
                    cout<<c2[i];
                    break;
                     }
                }
        }
}