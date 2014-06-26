/*********************************************************************
** Program Filename: game.cpp
** Author: Helena Bales
** Date: 04/23/2014
** Description: game class
** Input: none
** Output: none
********************************************************************/

#include"./game.h"

/*********************************************************************
** Function: game::game
** Description: the default constructor for the game class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the number of players is set to 2 and the game
** 		is set up for two players and the deck is initialized to 0
********************************************************************/ 

game::game() {

   numplayers = 2;

   players = new player[2];
   for(int i = 0; i < numplayers; i++) {
      players[i].num = (i+1);
      players[i].score = 0;
   }

   for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 13; j++) {
	 deck[i][j].held = 0;
	 deck[i][j].rank = j+1;
	 deck[i][j].suit = i+1;
      }
   }

}

/*********************************************************************
** Function: game::game
** Description: the non-default constructor for the game class
** Parameters: number of players from the user
** Pre-Conditions: num_players is in range
** Post-Conditions: game is set up for the number of players defined
**		by the user, and the board is initialized
********************************************************************/ 

game::game(int num_players) {

   numplayers = num_players;

   players = new player[numplayers];
   for(int i = 0; i < numplayers; i++) {
      players[i].num = (i+1);
      players[i].score = 0;
   }

   for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 13; j++) {
	 deck[i][j].held = 0;
	 deck[i][j].suit = i+1;
	 deck[i][j].rank = j+1;
      }
   }

}

/*********************************************************************
** Function: game::game
** Description: copy constructor for the game class
** Parameters: const game, passed by reference
** Pre-Conditions: the game that is passed already exists
** Post-Conditions: the two things of type game are equal
********************************************************************/ 

/*game::game(const game &g) {

   numplayers = g.numplayers;

   players = new player[numplayers];
   for(int i = 0; i < numplayers; i++) {
      players[i].num = g.players[i].num;
      players[i].score = g.players[i].score;
   }

   for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 13; j++) {
	 deck[i][j].held = g.deck[i][j].held;
	 deck[i][j].suit = g.deck[i][j].suit;
	 deck[i][j].rank = g.deck[i][j].rank;
      }
   }

}*/

/*********************************************************************
** Function: game::~game
** Description: deconstructor for game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the player array on the heap is freed
********************************************************************/ 

game::~game() {

   if(players != NULL)
      delete [] players;

}

/*********************************************************************
** Function: game::operator =
** Description: operator overload for equals
** Parameters: const game, passed by reference
** Pre-Conditions: the game passed by reference exists
** Post-Conditions: the two games are equal
********************************************************************/ 

/*game::operator = (game &other) {


}*/

/*********************************************************************
** Function: game::pscores
** Description: calculates the player's score
** Parameters: int playernum, the character that identifies the
** 		player as holding a certain card in the deck
** Pre-Conditions: playernum contains a valid number in range
** Post-Conditions: the score of the player is returned (in num suit
** 		matches
********************************************************************/ 

int game::pscores(int playernum) {
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
** Function: game::draw
** Description: draws a random card from the draw pile and assigns it
** 		to the player passed into the function
** Parameters: playernum
** Pre-Conditions: playernum contains a number
** Post-Conditions: deck.held at a random location has been assigned
** 		playernum
********************************************************************/ 

card game::draw(int playernum) {
   card newcard;
   int x, y;

   do{
	   //selects a random number between 0 and 3 for the suit
	   //selects a random number between 0 and 12 for the rank
      x = rand()%4;
      y = rand()%13;
      //repeats this loop if that selected card is
      //being held by a player
   }while(deck[x][y].held != 0);

	//sets the cards "held" property to the player number
   deck[x][y].held = playernum;

   newcard.suit = x+1;
   newcard.rank = y+1;

   return newcard;
}

/*********************************************************************
** Function: game::printd
** Description: for debugging; prints the contents of the deck
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
********************************************************************/ 

void game::printd() {

   for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 13; j++) {
	 cout << deck[i][j].held << "  ";
      }
      cout << endl;
   }

}

/*********************************************************************
** Function: game::printhand
** Description: prints the cards held by the player passed in
** Parameters: int playernum, the number of the player to print
** Pre-Conditions: playernum contains a number
** Post-Conditions: none
********************************************************************/ 

void game::printhand(int playernum) {

   for(int j = 0; j < 13; j++) {
      for(int i = 0; i < 4; i++) {
	 if(deck[i][j].held == playernum && !(deck[0][j].held == playernum && deck[1][j].held == playernum && deck[2][j].held == playernum && deck[3][j].held == playernum)) {
	    cout << deck[i][j].rank << " of ";
	    //this switch statement turns the number suits to strings
	    switch(deck[i][j].suit) {
			case 1: cout << "hearts" << endl; break;
			case 2: cout << "clubs" << endl; break;
			case 3: cout << "spades" << endl; break;
			case 4: cout << "diamonds" << endl; break;
		}
	 }
      }
   }

}

/*********************************************************************
** Function: game::printmatches
** Description: prints the player's matches
** Parameters: int playernum, the number of the player whose matches
** 		will be printed
** Pre-Conditions: playernum contains a number
** Post-Conditions: none
********************************************************************/ 

void game::printmatches(int playernum) {
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
** Function: game::setup
** Description: sets up the game by drawing 7 cards per player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: each player has 7 cards in their hand
********************************************************************/ 

void game::setup() {

   for(int i = 0; i < numplayers; i++) {
	   //for each player, run draw 7 times
      for(int j = 0; j < 7; j++)
		draw(i+1);
   }

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

bool game::guess(int playernum) {
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
** Function: game::checkguess
** Description: checks if the player guessed has the card guessed
** Parameters: int rank (guessed in "guess"), int p (guessed in
**		"guess"), int playernum, the number of the player guessing
** Pre-Conditions: all contain numbers
** Post-Conditions: 1 is returned if right, 0 if wrong
********************************************************************/ 

bool game::checkguess(int rank, int p, int playernum) {
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
** Function: game::won
** Description: checks if someone has won the game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: 1 is returned if someone won, else 0 is returned
********************************************************************/ 

bool game::won() {
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
