/*
 * Player.h
 *
 *  Created on: Apr 6, 2018
 *      Author: David (GitHub: DPigeon)
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>

using namespace std;

class Player {
private:
	string name; //Player's name
	bool isPlayer; //Determines who plays
public:
	Player();
	Player(string); //initializing the player with name
	bool isPlayer1(); //looks is player 1 or 2 is currently playing
	string getName();
	~Player();
};

#endif /* PLAYER_H_ */
