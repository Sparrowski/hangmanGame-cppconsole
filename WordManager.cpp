#include "WordManager.h"


WordManager::WordManager(std::string PATH){
	m_PATH = PATH;
	m_mistakes = 0;
	isGuessed = false;
	srand(time(nullptr));
}

int WordManager::LoadWordsFromFile(){
	std::fstream file(m_PATH);
	std::string line;

	if(file.is_open()){
		while(getline(file, line)){
			m_words.push_back(line);			   }
	file.close();
	}else{
		std::cout << "Not Found File " << m_PATH << " with words!" << std::endl;
		return -1;
	}

	return 0;

}

void WordManager::make_word_to_guess(){
	for(int i = 0; i < m_words[m_index].length(); ++i){
		m_word_to_guess+="_";
	}

	m_toGuess = m_word_to_guess.size();
	ms_wordToGuess = m_words[m_index];
}


void WordManager::randomize_word_index(const int range){
	m_index = rand()%range;
}

int WordManager::UpdateWord(int index, char c){
	m_word_to_guess[index] = c;
	m_toGuess--;
}

void WordManager::checkWord(char c){

	bool found = false;
	for(int i = 0; i < ms_wordToGuess.length(); ++i){
		if((c == ms_wordToGuess[i]) && (m_word_to_guess[i] != c)){
	      	UpdateWord(i, c);
		found = true;
		}
	}

	if(found == false) m_mistakes++;

	if(m_toGuess == 0){
		isGuessed = true;
		return;
	}
}
