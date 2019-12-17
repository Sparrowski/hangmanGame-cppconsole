/* Hangman cpp game
 * Author: Kamil Wróblewski
 * Date: 15.12.2019
 * ************************************************/
#include <iostream>
#include "Game.h"
#include <string>

int main(){
	Game game("words.txt");

	game.Play();
	return 0;
}
