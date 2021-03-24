#include <iostream>
using namespace std;

class Money{
	public:
		Money(float cash, float ccard, float dcard){
			this->cash=cash;
			this->ccard=ccard;
			this->dcard=dcard;
		}
		float getCash(){
			return cash;
		}
		float getCcard(){
			return ccard;
		} 
		float getDcard(){
			return dcard;
		}
		int getPin(){
			return pin=rand()%10000+1000;
		}
		float cashWallet(float a){
			cash=cash+a;
		}
		void pay(int a){
			if(cash==0)
			cout<<"No money";
			else cash=cash-a;
		}
		void payCcard(float a){
			if(ccard==0)
			cout<<"no money";
			else ccard=ccard-a;
		}
		void payDcard(float a){
			if(dcard==0)
			cout<<"no money";
			else dcard=dcard-a;
		}
		private:
			float cash;
			float ccard;
			float dcard;
			int pin;
};

int main(){
	float dcard, ccard, money;
	cin>>dcard>>ccard>>money;
	Money a(money,ccard,dcard);
	cout<<a.getPin()<<"";
	float p1,p2,p3;
	cin>>p1;
	a.pay(p1);
	cout<<a.getCash();
	cin>>p2;
	a.payDcard(p2);
	cout<<a.getDcard();
	cin>>p3;
	a.payCcard(p3);
	cout<<a.getCcard();
	int b;
	cin>>b;
	a.cashWallet(b);
	cout<<a.getCash();
	int c;
	cout<<endl;
	cout<<"Introduce pin";
	cin>>c;
	if(a.getPin()==c) cout<<"correct";
	else cout<<"wrong";
	return 0;
}