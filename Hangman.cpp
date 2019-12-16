#include "Hangman.h"

void Hangman::set_start_board(char character){

	hangman_parts = {52,54,43,33,23,13,4,5,6,7,18,28,38,37,39,47,49 };

	for(int i=0; i < m_BOARD_HEIGHT*m_BOARD_WIDTH; ++i){
		m_gameBoard.push_back(character);
	}
}

bool Hangman::update_hangman(const int MAX_MISTAKES){
	m_current_mistakes++;	
	if(m_current_mistakes == MAX_MISTAKES+1) return 1;

	char sign;
	if(m_current_mistakes == 1 || m_current_mistakes == 14 || m_current_mistakes == 16) sign = '/';
	else if(m_current_mistakes == 2 || m_current_mistakes == 15 || m_current_mistakes == 17) sign = '\\';
	else if((m_current_mistakes >= 3) && (m_current_mistakes <=6) || m_current_mistakes == 11 || m_current_mistakes == 13) sign = '|';
	else if(m_current_mistakes == 12) sign = 'O';
	else sign = '_';
	m_gameBoard[hangman_parts[m_current_mistakes-1]] = sign;	
}

std::ostream& operator<<(std::ostream& out, Hangman &h){
	
	const int BOARD_SIZE = h.m_BOARD_WIDTH*h.m_BOARD_HEIGHT;

	for(int i = 0; i < BOARD_SIZE; ++i){
		if(i%10 == 0) out << "\n";
		out << h.m_gameBoard[i];
	}

	return out;

}
