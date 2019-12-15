#pragma once
#include <iostream>
#include <string>
#include <vector>

class Hangman{

public:
	Hangman() : m_BOARD_HEIGHT(6), m_BOARD_WIDTH(10), m_current_mistakes(0) { }

	void set_start_board(const char); // sets starts board with char
	bool update_hangman(const int);


	void hangman_draw(); // draws hangman

private:
	const int m_BOARD_HEIGHT;
	const int m_BOARD_WIDTH;

	int m_current_mistakes;

	std::vector<char> m_gameBoard; // game board
	std::vector<int> hangman_parts; // indexes of hangmans parts
};

