#include<iostream>
#include<cstdlib>
#include<cstring>

#include"./card.h"
#include"./player.h"

/*********************************************************************
** Program Filename: driver.h
** Author: Helena Bales
** Date: 04/23/2014
** Description: starts the game class
** Input: none
** Output: none
********************************************************************/

using namespace std;

class game {
   public:
      game();
      game(int);
      //game(const game &);
      ~game();
      //void operator =(const game &);

      int pscores(int);
      card draw(int);
      void printd();
      void printhand(int);
      void printmatches(int);
      void setup();
      bool guess(int);
      bool checkguess(int, int, int);
      bool won();

   private:
      card deck[4][13];
      int numplayers;
      player *players;

};

/*********************************************************************
** Function: getnump
** Description: gets the number of players that the user wants to use
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: number of players is returned
********************************************************************/ 

int getnump();

/*********************************************************************
** Function: turn
** Description: runs part of the turn for each player
** Parameters: game gf (the game, passed by reference), bool right
**		(passed by reference), int i (the player who's turn it is)
** Pre-Conditions: game is set up, i is the player who's turn it is
** Post-Conditions: 1 is returned if right is true, 0 is returned
**		if false
********************************************************************/ 

bool turn(game &, bool &, int);

/*********************************************************************
** Function: rightf
** Description: is run if the player's guess is right, does not draw
** 		a new card, just prints the hand
** Parameters: the game board, and the player number
** Pre-Conditions: game is set up, i is the player whose turn it is,
**		and the player's new card is added to their hand
** Post-Conditions: none
********************************************************************/
 
void rightf(game &, int);

/*********************************************************************
** Function: wrong
** Description: is run if the player guesses wrong, draws a new card
** Parameters: game, player number
** Pre-Conditions: game is set up, and the player number is of who's
**		turn it is
** Post-Conditions: the player has a new card, drawn randomly from
**		the deck
********************************************************************/
 
void wrong(game &, int);

/*********************************************************************
** Function: spam
** Description: spams the screen with endl's
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the screen appears blank
********************************************************************/
 
void spam();
