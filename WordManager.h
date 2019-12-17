#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>

class WordManager{
public:
	WordManager(std::string PATH);

	int LoadWordsFromFile(); // loads words from PATH file to m_words vector 
	void make_word_to_guess(); // creates vector filled with as many '_' as there is letters in word

	void randomize_word_index(const int range); // set m_index with random number, which will be used to identify word
	
	void checkWord(char); // check if letter is in word
	int UpdateWord(int, char); // updates word to guess

	std::string get_word(const int index) { return m_words[index]; } // return complete word which player has to guess
	std::string get_wordToGuess(){ return m_word_to_guess; }
	int get_WordsVector_size() {return m_words.size();}
	int get_mistakes() { return m_mistakes; }
	bool get_isGuessed() { return isGuessed; }
private:
	std::string m_PATH;
	std::vector<std::string> m_words;

	std::string m_word_to_guess;
	std::string ms_wordToGuess;
	int m_toGuess; // how many letters remainded 
	int m_mistakes;

	bool isGuessed;

	int m_index;
};
