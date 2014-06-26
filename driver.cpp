/*********************************************************************
** Program Filename: driver.cpp
** Author: Helena Bales
** Date: 04/23/2014
** Description: runs the game from the game class
** Input: none
** Output: none
********************************************************************/

#include"./game.h"
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int main() {
   int numplayers;
   int cont;
   bool right;

   //seeds the random number generator (only do once)
   srand(time(NULL));

   numplayers = getnump();
   
   game gf(numplayers);
   gf.setup();
   //gf.printd();
   do {
	   for(int i = 0; i < numplayers; i++) {
		   if(!turn(gf, right, i)) {
			   return 0;
		   }
		   if(right) {
			   rightf(gf, i);
           }
           else {
			   wrong(gf, i);
		   }
           cout << "Your matches are: " << endl;
           gf.printmatches(i+1);
           cout << "Player " << i+1 << " please enter 1 to continue (entering 0 will quit the game): ";
           cin >> cont;
           if(cont == 0) {
			   return 0;
		   }
		   if(gf.won())
			  return 0;
       }
	}while(1);

}

int getnump() {
   int nump;

   cout << "How many people want to play go fish? (enter 2-6 now): ";
   cin >> nump;

   if(nump <= 6 && nump >= 2)
      return nump;
   else
      nump = getnump();
   return nump;
}

bool turn(game &gf, bool &right, int i) {
	bool cont;
	
	cout << "It is player " << i+1 << "'s turn." << endl;
	spam();
	cout << "Player " << i+1 << " please enter 1 to continue (entering 0 will quit the game): ";
	cin >> cont;
	if(cont == 0) {
		return 0;
	}
	cout << "Player " << i+1 << " here is your hand: " << endl;
	gf.printhand(i+1);
	right = gf.guess(i+1);
	
	return 1;
}

void rightf(game &gf, int i) {
	
	cout << "You guessed right and now have 1 or more new cards. Here is your new hand: " << endl;
	gf.printhand(i+1);
	//gf.printd();
	
}

void wrong(game &gf, int i) {
	bool cont;
	
	do {
		cout << "You guessed wrong. Press 1 to draw a card: ";
		cin >> cont;
	}while(!cont);
	gf.draw(i+1);
	cout << "You have drawn a new card. Here is your new hand: " << endl;
	gf.printhand(i+1);
	
}

void spam() {
	
	for(int i = 0; i < 100; i++) {
		cout << endl;
	}
	
}
