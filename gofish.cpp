/*********************************************************************
** Program Filename: game.cpp
** Author: Helena Bales
** Date: 04/23/2014
** Description: game class
** Input: none
** Output: none
********************************************************************/

#include"./gofish.hpp"

/*********************************************************************
** Function: gofish::pscores
** Description: calculates the player's score
** Parameters: int playernum, the character that identifies the
** 		player as holding a certain card in the deck
** Pre-Conditions: playernum contains a valid number in range
** Post-Conditions: the score of the player is returned (in num suit
** 		matches
********************************************************************/ 

int gofish::pscores(int playernum) {
   int match = 0;

   players[playernum].score = 0;

   for(int j = 0; j < 13; j++) {
      match = 0;
      for(int i = 0; i < 4; i++) {
	 if(deck[i][j].held == playernum)
	    match += 1;
	 else
	    match = 0;
      }
      if(match == 4) {
	 players[playernum].score += 1;
      }
   }

   return players[playernum].score;
}

/*********************************************************************
** Function: gofish::printmatches
** Description: prints the player's matches
** Parameters: int playernum, the number of the player whose matches
** 		will be printed
** Pre-Conditions: playernum contains a number
** Post-Conditions: none
********************************************************************/ 

void gofish::printmatches(int playernum) {
  bool amatch = 0;

   for(int j = 0; j < 13; j++) {
	   //checks that all the cards in the rank are held by playernum
      if(deck[0][j].held == playernum && deck[1][j].held == playernum && deck[2][j].held == playernum && deck[3][j].held == playernum) {
	 cout << "Match of rank " << deck[0][j].rank << endl;
	 amatch = 1;
      }
   }

	//if there aren't any matches, then this is run
   if(!amatch)
      cout << "no matches... yet!" << endl;

}

/*********************************************************************
** Function: game::guess
** Description: gets the player to guess which card and from which
** 		player
** Parameters: int playernum, the number of the player guessing
** Pre-Conditions: playernum contains a number
** Post-Conditions: a 1 is returned if the player got a card, a 0 is
**		returned if the player guessed wrong
********************************************************************/ 

bool gofish::guess(int playernum) {
   int rank, p;

   cout << "Which card do you want? Enter the rank now: ";
   cin >> rank;
   rank -= 1;
   
   do {
	   cout << "Which player do you want the card from? ";
	   cin >> p;
   }while((p == playernum) && (p < 1) && (p > numplayers));
   
   cout << endl;

   if(checkguess(rank, p, playernum))
      return 1;
   else
      return 0;
}

/*********************************************************************
** Function: gofish::checkguess
** Description: checks if the player guessed has the card guessed
** Parameters: int rank (guessed in "guess"), int p (guessed in
**		"guess"), int playernum, the number of the player guessing
** Pre-Conditions: all contain numbers
** Post-Conditions: 1 is returned if right, 0 if wrong
********************************************************************/ 

bool gofish::checkguess(int rank, int p, int playernum) {
	bool right = 0;

   for(int i = 0; i < 4; i++) {
      if(deck[i][rank].held == p) {
		 deck[i][rank].held = playernum;
		 right = 1;
	  }
   }
   return right;
}

/*********************************************************************
** Function: gofish::won
** Description: checks if someone has won the game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: 1 is returned if someone won, else 0 is returned
********************************************************************/ 

bool gofish::won() {
	bool notwon[numplayers];
	
	for(int p = 0; p < numplayers; p++)
		notwon[p] = 0;
		
		//runs a loop, and if anyone has no cards, it sets their
		//not won to 0, meaning they have won the game
	for(int p = 0; p < numplayers; p++) {
		for(int i = 0; i < 4; i++) {
		   for(int j = 0; j < 13; j++) {
			    if(deck[i][j].held == p+1) {
				    notwon[p] = 1;
			    }
			}
		}
	}
	
	//for debugging
/*	
	for(int i = 0; i < numplayers; i++) {
		cout << notwon[i] << endl;
	}
	*/
	
	//the person that has won is printed out if someone won
	for(int i = 0; i < numplayers; i++) {
		if(notwon[i] == 0) {
			cout << "Player " << i+1 << " has won Go Fish!" << endl;
		}
	}
	
	for(int i = 0; i < numplayers; i++) {
		if(notwon[i] == 0)
			return 1;
		else
			return 0;
	}
}
