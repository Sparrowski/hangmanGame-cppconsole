#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>

class WordManager{
public:
	WordManager(std::string PATH);

	int LoadWordsFromFile();
	void make_word_to_guess();

	void randomize_word_index(const int range);
	
	
	std::string get_word(const int index);

	int get_WordsVector_size() {return m_words.size();}

private:
	std::string m_PATH;
	std::vector<std::string> m_words;

	std::vector<char> m_word_to_guess;
	int m_toGuess;

	int m_index;
};
