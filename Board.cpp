/*
 * Board.cpp
 *
 *  Created on: Apr 6, 2018
 *      Author: David (GitHub: DPigeon)
 */

#include "Board.h"
#include "Player.h"
#include <iomanip>
#include <sstream>

//Global Variables
const int rows[] = {1, 2, 3}; //rows for display
const char cols[] = {'A', 'B', 'C'}; //columns for display
bool player1;

Board::Board(){
}

Board::Board(string n){
	name = n;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			tBoard[i][j] = '-'; //Initializing the board with '-'
		}
}

Board::Board(Board& Board){
	this->name = Board.name;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			tBoard[i][j] = Board.tBoard[i][j];
	}
}

bool Board::threeIdentical(){ //look in "diagonals" left right and "lines" left right
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			if( (tBoard[0][0] == 'O' && tBoard[0][1] == 'O' && tBoard[0][2] == 'O') || (tBoard[0][0] == 'X' && tBoard[0][1] == 'X' && tBoard[0][2] == 'X') ||
				(tBoard[1][0] == 'O' && tBoard[1][1] == 'O' && tBoard[1][2] == 'O') || (tBoard[1][0] == 'X' && tBoard[1][1] == 'X' && tBoard[1][2] == 'X') ||
				(tBoard[2][0] == 'O' && tBoard[2][1] == 'O' && tBoard[2][2] == 'O') || (tBoard[2][0] == 'X' && tBoard[2][1] == 'X' && tBoard[2][2] == 'X') ||
				(tBoard[0][0] == 'O' && tBoard[1][0] == 'O' && tBoard[2][0] == 'O') || (tBoard[0][0] == 'X' && tBoard[1][0] == 'X' && tBoard[2][0] == 'X') ||
				(tBoard[0][1] == 'O' && tBoard[1][1] == 'O' && tBoard[2][1] == 'O') || (tBoard[0][1] == 'X' && tBoard[1][1] == 'X' && tBoard[2][1] == 'X') ||
				(tBoard[0][2] == 'O' && tBoard[1][2] == 'O' && tBoard[2][2] == 'O') || (tBoard[0][2] == 'X' && tBoard[1][2] == 'X' && tBoard[2][2] == 'X') ||
				(tBoard[0][0] == 'O' && tBoard[1][1] == 'O' && tBoard[2][2] == 'O') || (tBoard[0][0] == 'X' && tBoard[1][1] == 'X' && tBoard[2][2] == 'X') ||
				(tBoard[2][0] == 'O' && tBoard[1][1] == 'O' && tBoard[0][2] == 'O') || (tBoard[2][0] == 'X' && tBoard[1][1] == 'X' && tBoard[0][2] == 'X') )
				return true;
	}
	return false;
}

void Board::play(string c){
	//first, let's get the coordinates (example A1)
	char first;
	int second;
	stringstream coord; //using stringstream
	coord<<c; //gets string c
	coord>>first; //gets the first element in the string
	coord>>second; //gets the second element in the string
	int firstConverted = charToInt(first); //convert the char to integer
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			if(!existAtCoords(firstConverted, second-1)){
				if(player1) //if player 1 is playing
					tBoard[firstConverted][second-1] = 'O'; //add O's
				else
					tBoard[firstConverted][second-1] = 'X'; //if not add X's
			}
	}
	Display();
}

bool Board::existAtCoords(int x, int y){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			if(tBoard[x][y] != '-') //if there is a O or X on the (x,y) then it exits
				return true;
	}
	return false;
}

void Board::whichPlayerPlaying(int num){
	if(num == 1){
		player1 = true; //player 1 is currently playing
	} else {
		player1 = false; //player 2 is currently playing
	}
}

int Board::charToInt(char c){
	//convert column chars to integers
	int index;
	for(int i = 0; i < 8; i++){
		if(cols[i] == c)
			index = i;
	}
	return index;
}

bool Board::operator ==(const Board& rightS) const{
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(tBoard[i][j] != rightS.tBoard[i][j]) //looks if they are not the same
				return false;
		}
	}
	return true;
}

bool Board::operator!=(const Board& rightS) const{
	return !(*this == rightS); // invokes == operator
}

void Board::Display() const{
	//Has to display the numbers on row and alphabet on columns
	cout<<"  ";
	for(int i = 0; i < 3; i++)
		cout<<setw(3)<<rows[i];
	cout<<endl;
	int num = 0;
	for(int i = 0; i < size; i++){
		cout<<cols[i]<<" ";
		for(int j = 0; j < size; j++)
			cout<<setw(3)<<tBoard[i][j];
			cout<<endl;
			num++;
			if(num == 3){
				cout<<endl;
				num = 0;
			}
	}
}

int Board::getSize(){
	return size;
}

Board::~Board(){
}

