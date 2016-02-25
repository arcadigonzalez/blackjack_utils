#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>


using namespace std;



int PBC (int P, int D , int S , int E); //player betting chart



double randgen (int i) { 	//random geneator for random_shuffle
srand(time(0));
return (rand())%i;}



class Card {  				//class for card


	
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





int main(){

int Auto;
cout<<"Auto? (YE5 / N0) "<<endl;
cin>>Auto;


clock_t tm;
tm = clock();

for (int tot=0;tot<1;tot++){

int trials=1;
float avg=0;

for (int T=0;T<trials; T++){



//random shuffling deck
int deckamt=8;
vector <int> CardNum(deckamt*52);
  
for (int n=0;n<CardNum.size();n++)
	{CardNum[n]=n;}
	
random_shuffle ( CardNum.begin(), CardNum.end(),randgen);







	
int n=0;

float bankroll=0;
bool blackJack=0;
float originalbet=1;
float bet=originalbet;
int round=0;
	
vector<string> dealerHand (10);
vector<string> playerHand (10);

int DHvalue, DaceCount, DcardNum;

int PHvalue, PaceCount, PcardNum;



for (n=0; n<52*deckamt; n++){   //game loop
	
DHvalue= DaceCount= DcardNum=0;

PHvalue= PaceCount= PcardNum=0;
	
	round++;
	
	
	int DealersFirst=0;
	Card DOne(CardNum[n]);
	
	DHvalue=DOne.value();
if (Auto==0){	 cout<<"Dealer's first card:  "<<DOne.getnum()<<DOne.getsuit();}
	dealerHand[DcardNum]=DOne.getnum()+DOne.getsuit();
	if (DOne.aceCount()==1)
	   {DaceCount=1;}
	
	DealersFirst=DOne.value(); //dealers first card value stored for Basic Strategy
		
	n++;
	
	
	Card DTwo(CardNum[n]);
	DcardNum=1;
	if (DTwo.aceCount()==1)
		{DaceCount+=1;}
	//if (Auto==0){	  cout<<" "<<DTwo.getnum()<<DTwo.getsuit();}
	dealerHand[DcardNum]=DTwo.getnum()+DTwo.getsuit();
	DHvalue=DHvalue+DTwo.value();
	
	if ((DHvalue>21)&&(DaceCount>0)){
		DHvalue-=10;
		DaceCount--;
		}


	n++;
	Card POne(CardNum[n]);
	PcardNum=0;
	PaceCount=0;
	PHvalue=POne.value();
if (Auto==0){	cout<<endl<<"Player hand:  "<<POne.getnum()<<POne.getsuit();}
	playerHand[PcardNum]=POne.getnum()+POne.getsuit();
	if (POne.aceCount()==1)
	   {PaceCount=1;}
		
	n++;
	PcardNum=1;
	Card PTwo(CardNum[n]);
	
	if (PTwo.aceCount()==1)
	   {PaceCount++;}
	
if (Auto==0){	cout<<" "<<PTwo.getnum()<<PTwo.getsuit();}
	playerHand[PcardNum]=PTwo.getnum()+PTwo.getsuit();
	PHvalue=PHvalue+PTwo.value();
	
	if ((PHvalue>21)&&(PaceCount>0)){		//double ace soft proofing
		PHvalue-=10;
		PaceCount--;
		}
		
	
	int Q;
	
	
if (Auto==0){	cout<<endl<<"1 for hit, 2 for double, else for stand:  "<<PBC(PHvalue,DealersFirst,PaceCount,0)<<"  "<<endl;}


if (Auto==5){	Q=PBC(PHvalue,DealersFirst,PaceCount,0); } //action taken from basic strategy formula,      
if (Auto==0){    cin>>Q;}

	if (PHvalue==21){ //player blackjack
		Q=0;
		bet= originalbet + originalbet/2;
		blackJack=1;
		}
		

	if (Q==2)
		{bet*=2;}			//if doubling, bet gets doubled
	
	while ((Q==1)||(Q==2))		//extra cards for player
	{
		n++;
		Card PSubs(CardNum[n]);
		PcardNum++;
		PHvalue=PHvalue+PSubs.value();
		playerHand[PcardNum]=PSubs.getnum()+PSubs.getsuit();
		
		if (PSubs.aceCount()==1)	 //ace counting
			{PaceCount++;}
		
		if ((PHvalue>21)&&(PaceCount>0)){	//hardening hand in case of bust
			PHvalue-=10;
			PaceCount--;
			}
		

if (Auto==0){		cout<<endl<<"You get: "<<PSubs.getnum()<<PSubs.getsuit()<<endl<<"h for hit, else stand:  "<<PBC(PHvalue,DealersFirst,0,0)<<"  "<<endl; }  
if (Auto==5){		Q=PBC(PHvalue,DealersFirst,PaceCount,0);}	   //keep this line commented for manual, keep next line commented for auto 
if (Auto==0){cin>>Q;}
if (Auto==0){		cout<<endl;}
	}
	

	
if (Auto==0){  	  cout<<endl<<"Player hand:  ";}
	for(int h=0;h<PcardNum+1;h++){
if (Auto==0){		cout<<playerHand[h]<<"  ";}
		}
if (Auto==0){	cout<<"  value:  "<<PHvalue;}



	
	
	
	while (DHvalue<17){
		n++;
		Card DSubs(CardNum[n]);
		DcardNum++;
		
 	 if (DSubs.aceCount()==1)
	 		{DaceCount++;}
//if (Auto==0){	  	  cout<<" "<<DSubs.getnum()<<DSubs.getsuit();	} 
		DHvalue=DHvalue+DSubs.value();
		dealerHand[DcardNum]=DSubs.getnum()+DSubs.getsuit();
	if ((DHvalue>21)&&(DaceCount>0)){
		DHvalue-=10;
		DaceCount--;
		}
	}
	

if (Auto==0){	cout<<endl<<"Dealer hand:  "; }
	for(int h=0;h<DcardNum+1;h++){
if (Auto==0){		cout<<dealerHand[h]<<"  "; }
		}


if (Auto==0){	cout<<"	  Value: "<<DHvalue<<endl<<"________________________________________"<<endl<<endl;}
	
	if (blackJack==1){
		bankroll+=bet;
if (Auto==0){		cout<<"21, Blackjack!  ";}
		}
	
	else if (PHvalue>21){
		bankroll-=bet;
if (Auto==0){		cout<<"Busted! You lose.  ";}
		}
		
	else if (DHvalue>21){
		bankroll+=bet;
if (Auto==0){		cout<<"Dealer busted! You win. "; }
		}
		
	else if (PHvalue==DHvalue){
if (Auto==0){		cout<<"Push  ";}
		}
		
	else if (PHvalue>DHvalue){
		bankroll+=bet;
if (Auto==0){		cout<<"You win!  "; }
		}
		
	else if (PHvalue<DHvalue){
if (Auto==0){		cout<<"You lose!  "; }
		bankroll-=bet;
		}
if (Auto==0){	cout<<endl<<"Bankroll: "<<bankroll<<endl<<"________________________________________"<<endl<<endl;	 }

	
if (Auto==0){		cout<<round<<": "<<bankroll/round<<endl; }
	
if (Auto==0){	cout<<"  Ace Count: "<<DaceCount<<endl; }
		DHvalue=0;
		PHvalue=0;
		PcardNum=0;
		bet=originalbet;
		blackJack=0;
		if (n>=(48*deckamt)){
	break;}	   

	}	 	 
avg+=bankroll/round;
cout<<round<<": "<<bankroll/round<<endl<<"Bankroll: "<<bankroll<<endl;	  
}

avg/=trials;
cout<<avg<<endl;
tm=clock()-tm;
cout<<tm<<endl;

}
return 0;
}





//Player Betting Chart.Basic Strategy. P=Player Hand Value (2-21); D=Dealer Card Value (2-11); S= 1 for soft; 0 for hard; E=1 for pairs, 0 for non-pairs
//Return: 0 for stand; 1 for hit; 2 for double 3 for split. No surrender or insurance. European rules dealer stands on soft 17.
int PBC (int P, int D, int S, int E)
{



if ((S==0)&&(E==0))  //hard unpaired hands
	{

	
	if ((P>4)&&(P<9))
		{return (1);}

	
	if (P==9)
		{	 
		if (D<7)
			{return (2);}
		else
			{return (0);}
		}
	
	
	if ((P==11)||(P==10))
		{
		if (D<10)
			{return (2);}
		else
			{return (1);}	 	 
		}


	if (P==12){
		if ((D<4)||(D>6))
			{return (1);}
		else 
			{return (0);}
		}
	

	if ((P>12)&&(P<17))
		{
		if (D<7)
			{return (0);}
		else
			{return (1);}
		}
	

	if (P>16)
		{return (0);} 
	
	
	}


if ((S==1)&&(E==0)) //soft unpaired hands
	{
	
	if (P<18)
		{return (1);}
	
	
	if (P==18)
		{
		if (D<9)
			{return (0);}
		else
			{return (1);}
		}
		
	
	if (P>18)  
		{return (0);}
	
	}


if ((S==0)&&(E==1))  //hard paired hands
	
	{

	if ((P==4)||(P==6))
		{
		
		if ((D<4)||(D>7))
			{return (1);}
		else
			{return (3);}
	
		}
	
	
	if (P==8)
		{return (1);}
	
	
	if (P==10)
		{
		if (D<10)
			{return(2);}
		else
			{return(1);}
		}
	
	
	if (P==12)
		{
		if (D<7)
			{return(3);}
		else
			{return(1);}
		}
		
		   
	if (P==14)
		{
		if (D<8)
			{return(3);}
		else
			{return(1);}
		}


	if (P==16)
		{
		if (D<10)
			{return(3);}
		else
			{return(1);}
		}
	
	
	if (P==18)
		{
		if ((D<7)||(D==8)||(D==9))
			{return(3);}
		else
			{return(0);}
		}
		   
		   	   	      	   	      
	if (P==20)
		{return (0);}
	
	
	}



if ((S==1)&&(E==1))
	{
	if (D==11)
		{return (1);}
	else
		{return (3);}
	}
		




}







Card::Card(int num_in){
num=num_in;}

string Card::getnum()
	{
	int a;
	a=num%13;
	string face[13]={"Ace","2","3","4","5","6","7","8","9","10","Jack ","Queen ","King "};
	return (face[a]);
	}
	
string Card::getsuit()
	{
	int a;
	a=num%13;
	a=(num-a)%4;
	string suit[4]={"\x03","\x04","\x05","\x06"};
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

