/*
 * Game.cpp
 *
 *  Created on: Apr 6, 2018
 *      Author: David (GitHub: DPigeon)
 */

#include <iostream>
#include "Board.h"
#include "Player.h"

using namespace std;

int main(){
	//Variables
	Board tic("Tic Tac Toe");
	Board Bcheck("");
	string p1, p2, coords;
	int i = 0; //for turns
	cout<<"Welcome to the Tic Tac Toe game !"<<endl;
	cout<<"Enter Player 1's name: ";
	cin>>p1;
	Player P1(p1);
	cout<<"Enter Player 2's name: ";
	cin>>p2;
	Player P2(p2);
	cout<<P1.getName()<<" has O's and "<<P2.getName()<<" has X's. "<<P1.getName()<<" begins by entering a coordinate (ex: A1)."<<endl;
	cout<<endl;
	tic.Display(); //display the board at beginning
	do{ // While nobody won the game, play
		Bcheck = tic; //putting the board checking as same as original board
		if(i%2 == 0){ //p1 plays first every even numbers
			tic.whichPlayerPlaying(1); // says which player is playing to the board
			cout<<"It is "<<P1.getName()<<"'s turn !"<<endl;
		} else {
			tic.whichPlayerPlaying(2);
			cout<<"It is "<<P2.getName()<<"'s turn !"<<endl;
		}
		cin>>coords; //reads coordinates for O or X
		tic.play(coords);
		if(tic != Bcheck) //if the board is not the same as previous one, change turn
			i++;
	} while(!tic.threeIdentical()); //loop until there is 3 matching X or O on the same row, column or diagonal
	if(i%2 != 0) // if player 1 played last
		cout<<P1.getName()<<" won ! Congratulations."<<endl;
	else
		cout<<P2.getName()<<" won ! Congratulations."<<endl;
}


