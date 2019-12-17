#pragma once

#include "Hangman.h"
#include "WordManager.h"
#include <iostream>
#include <string>

class Game{
public:
	Game(std::string PATH) { board = new Hangman(6,10); wm = new WordManager(PATH); }
	~Game(){ delete board; delete wm; } 

	int Play(); // main game loop
private:
	Hangman *board;
	WordManager *wm;


};
