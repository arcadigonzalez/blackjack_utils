#include <iostream>     // std::cout
#include <algorithm>    // std::move_backward
#include <vector>
#include <ctime>        
#include <cstdlib>      


using namespace std;


double randgen (int i) {
srand(time(0));
return (rand())%i;}

int main () {
  
	int deckNumber=8;
	vector <int> CardNum(deckNumber*52);
  
	for (int n=0;n<CardNum.size();n++)
		{CardNum[n]=n;}


cout<<time(0);

cout << "shuffled elements:";
  	for (int n=0;n<CardNum.size();n++) 
	{cout<<CardNum[n]<<" ";}

cout<<endl;
int seed=1;



random_shuffle ( CardNum.begin(), CardNum.end(),randgen);

cout << "shuffled elements:";
  	for (int n=0;n<CardNum.size();n++) 
	{cout<<CardNum[n]<<" ";}

	

  return 0;
}

