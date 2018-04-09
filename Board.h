/*
 * Board.h
 *
 *  Created on: Apr 6, 2018
 *      Author: David (GitHub: DPigeon)
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <string>

using namespace std;

class Board {
private:
	string name; // Name of the board
	static const int size = 3; //Max of game 3x3
	char tBoard[size][size]; // Array of the game
public:
	Board();
	Board(string); //initializing the board with a name
	Board(Board&); //copies the board
	bool threeIdentical(); //if a player wins
	void play(string); //plays a O or X
	bool existAtCoords(int, int); //if the O or X already exists on board
	void whichPlayerPlaying(int); //who is currently playing?
	int charToInt(char); //converts the letters to numbers
	bool operator==(const Board&) const; // equality assignment ==
	bool operator!=(const Board&) const; // not equal !=
	void Display() const; //displays the board
	int getSize(); //gets the size
	~Board();
};

#endif /* BOARD_H_ */
