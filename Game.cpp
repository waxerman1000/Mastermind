//Andrew Green
#include "Game.h"
#include "row.h"
#include <vector>
#include <algorithm>
#include <ctime>

Game::Game()
{
}

void Game::doGame()
{
	Row key;
	Row userGuess;
	int tempRand;
	int remainingTurns = 10;
	string keyString = "";
	string userGuessString = "";
	bool gaming = true;

	srand(time(NULL));
	
	//create the key
	for (int i = 0; i < 4; i++) {
		tempRand = (rand() % 8);
		if (tempRand == 0) {}
		else if (tempRand == 0) { keyString.append("r"); } //red
		else if (tempRand == 1) { keyString.append("g"); } //green
		else if (tempRand == 2) { keyString.append("b"); } //blue
		else if (tempRand == 3) { keyString.append("y"); } //yellow
		else if (tempRand == 4) { keyString.append("o"); } //orange
		else if (tempRand == 5) { keyString.append("p"); } //purple
		else if (tempRand == 6) { keyString.append("v"); } //gray
		else if (tempRand == 7) { keyString.append("t"); } //tan
	}
	key.rewrite(keyString);
	
	//The rules
	cout << "Welcome to Mastermind!" << endl;
	cout << "In this game, you are presented with 8 colors, and must try and put four of them together in order to match a key." << endl;
	cout << "The colors you may choose from are red, green, blue, yellow, orange, pink, violet, and tan." << endl;
	cout << "You have 10 chances to correctly guess." << endl;
	cout << "Whenever you guess, you will be given a response to help aide you in your next attempts." << endl;
	cout << "You will be presented with black and white spots." << endl;
	cout << "Black spots determine how many colors you have in the exact spot, while white ones tell you how many colors you" << endl;
	cout << "have correct, but are in an incorrect spot." << endl;
	cout << "To guess, you must input the first letter of the four colors you would like to try." << endl;
	cout << "For example, if you wish to guess blue, green, yellow, yellow, your input would look like:" << endl;
	cout << "bgyy" << endl;
	cout << "Capital letters are not allowed." << endl;
	cout << "Let the games begin." << endl << endl;

	while (gaming) {
		cout << "You have " << remainingTurns << " attempts left." << endl;
		cin >> userGuessString;
		if (userGuess.isValid(userGuessString)) {
			userGuess.rewrite(userGuessString);
			//win condition
			if (userGuess.compareTo(key)) {
				cout << "You win!" << endl << endl;
				gaming = false;
			}
			else { remainingTurns--; }
		}
		else { cout << "There was a problem reading your input, please try again." << endl; }

		//lose condition
		if (remainingTurns == 0) {
			cout << "Hah! You lost!!" << endl;
			cout << "The key was " << key << endl << endl;
			gaming = false;
		}




	}
}
