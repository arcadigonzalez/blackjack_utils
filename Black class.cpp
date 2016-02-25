#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;





class Card {


	
	public:
	
	//constructor
	Card (int num_in=0);

	//functions
	
	string getnum();
	string getsuit();
	int value();
	int aceCount();
	bool red7();
	int HiLo();
	
	private:
	
	int num;

};
	

int main (){

	int number=0;
while (number!=52*4){

	
	Card one(number);
	string dispnum=one.getnum();
	string dispsuit=one.getsuit();

	cout<<number<<":  "<<dispnum<<dispsuit<<"	"<<one.value()<<"	"<<one.aceCount()<<"	"<<one.red7()<<"	"<<one.HiLo()<<endl;

	number++;
}

return 0;}


Card::Card(int num_in){
num=num_in;}

string Card::getnum()
	{
	int a;
	a=num%13;
	string face[13]={"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
	return (face[a]);
	}
	
string Card::getsuit()
	{
	int a;
	a=num%13;
	a=(num-a)%4;
	string suit[4]={" \x03"," \x04"," \x05"," \x06"};
	return suit[a];
	}


int Card::value()
	{
	int a;
	a=num%13;
	int val[13]={11,2,3,4,5,6,7,8,9,10,10,10,10};
	return (val[a]);
	
	}


int Card::aceCount()
	{
	int a;
	a=num%13;
	int val[13]={1,0,0,0,0,0,0,0,0,0,0,0,0};
	return (val[a]);
	
	}


bool Card::red7()
	{
	int a;
	a=num%13;
	int b;
	b=(num-a)%4;

	return ((a==6)&&(b<2));
	
	
	
	}

int Card::HiLo()
	{
	int a;
	a=num%13;
	if ((a<6)&&(a>0))
		{return (-1);}
	else if ((a>8)||(a==0))
		{return (1);}
	else 
		{return (0);}
	
	}

