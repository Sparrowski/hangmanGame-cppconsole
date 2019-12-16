#pragma once
#include <iostream>
#include <string>
#include <vector>

class Hangman{

public:
	Hangman(const int HEIGHT, const int WIDTH) : m_BOARD_HEIGHT(HEIGHT), m_BOARD_WIDTH(WIDTH) { m_current_mistakes = 0; }

	void set_start_board(const char); // sets starts board with char
	bool update_hangman(const int); // updates hangman scratch, and also adds one mistake when is used

	friend std::ostream& operator<<(std::ostream& out, Hangman &h);
private:
	const int m_BOARD_HEIGHT;
	const int m_BOARD_WIDTH;

	int m_current_mistakes;

	std::vector<char> m_gameBoard; // game board
	std::vector<int> hangman_parts; // indexes of hangmans parts
};

