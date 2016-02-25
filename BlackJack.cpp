#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <ctime>



using namespace std;
int main(){

srand(time(0));

	int i,n;
	int m=0;
	for (m;m<10;m++){
		i=rand()%52;
	//	  cout<<i<<"   ";
	}
string deck[]={"2","2","2","2","3","3","3","3","4","4","4","4","5","5","5","5","6","6","6","6","7","7","7","7","8","8","8","8","9","9","9","9","10","10","10","10","J","J","J","J","Q","Q","Q","Q","K","K","K","K","A","A","A","A",};
int numDeck[52]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51};
int shuffNum[52];
int valueDeck[52]={2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,11,11,11,11};
for (n=0; n<52; n++){
	i=rand()%52;
	
	if (numDeck[i]==-1){
		n--;
		}
	else {
		shuffNum[n]=numDeck[i];
		numDeck[i]=-1;
		}
}
	
n=0;	
for (n=0; n<52; n++){
	cout<<deck[shuffNum[n]]<<" = "<<valueDeck[shuffNum[n]]<<endl;
	}	 	 
vector<string> dealerHand;
int DHvalue;
int STOPPER;
n=0;
for (n=0; n<52; n++){
	
	cout<<deck[shuffNum[n]];
	n++;
	cout<<" "<<deck[shuffNum[n]];
	DHvalue=valueDeck[shuffNum[n-1]]+valueDeck[shuffNum[n]];
	valueDeck[shuffNum[n-2]]=valueDeck[shuffNum[n-1]]=valueDeck[shuffNum[n]]=0;
	if ((DHvalue>21)&&((valueDeck[shuffNum[n]]==11)||(valueDeck[shuffNum[n-1]]==11)))
		{DHvalue-=10;
		valueDeck[shuffNum[n-2]]=valueDeck[shuffNum[n-1]]=valueDeck[shuffNum[n]]=0;}
	
	if (DHvalue<17){
		n++;
		DHvalue=DHvalue+valueDeck[shuffNum[n]];
		cout<<" "<<deck[shuffNum[n]];
		if ((DHvalue>21)&&((valueDeck[shuffNum[n]]==11)||(valueDeck[shuffNum[n-1]]==11)||(valueDeck[shuffNum[n-2]]==11))){DHvalue-=10;valueDeck[shuffNum[n-2]]=valueDeck[shuffNum[n-1]]=valueDeck[shuffNum[n]]=0;}
				
		if (DHvalue<17){
			n++;
			DHvalue=DHvalue+valueDeck[shuffNum[n]];
			cout<<" "<<deck[shuffNum[n]];
			if ((DHvalue>21)&&((valueDeck[shuffNum[n]]==11)||(valueDeck[shuffNum[n-1]]==11)||(valueDeck[shuffNum[n-2]]==11)||(valueDeck[shuffNum[n-3]]==11))){DHvalue-=10;valueDeck[shuffNum[n-2]]=valueDeck[shuffNum[n-1]]=valueDeck[shuffNum[n]]=valueDeck[shuffNum[n-3]]=0;}
							
			if (DHvalue<17){
				n++;
				DHvalue=DHvalue+valueDeck[shuffNum[n]];
				cout<<" "<<deck[shuffNum[n]];
			
				if (DHvalue<17){
					n++;
					DHvalue=DHvalue+valueDeck[shuffNum[n]];
					cout<<" "<<deck[shuffNum[n]];
				
					if (DHvalue<17){
						n++;
						DHvalue=DHvalue+valueDeck[shuffNum[n]];
						cout<<" "<<deck[shuffNum[n]];
					
						if (DHvalue<17){
							n++;
							DHvalue=DHvalue+valueDeck[shuffNum[n]];
							cout<<" "<<deck[shuffNum[n]];
					
							if (DHvalue<17){
								n++;
								DHvalue=DHvalue+valueDeck[shuffNum[n]];
								cout<<" "<<deck[shuffNum[n]];
				
								if (DHvalue<17){
									n++;
									DHvalue=DHvalue+valueDeck[shuffNum[n]];
									cout<<" "<<deck[shuffNum[n]];
								}
							}
						}
					}
				}
			}
		}
	}
   	   
	cout<<"  value: "<<DHvalue<<endl;
		if (n>=45){
	break;}	   
	

	}	 	 




return 0;
}

