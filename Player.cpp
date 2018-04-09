/*
 * Player.cpp
 *
 *  Created on: Apr 6, 2018
 *      Author: David (GitHub: DPigeon)
 */

#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(string n){
	name = n;
}

bool Player::isPlayer1(){
	return isPlayer;
}

string Player::getName(){
	return name;
}

Player::~Player() {
}

