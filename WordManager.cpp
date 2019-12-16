#include "WordManager.h"


WordManager::WordManager(std::string PATH){
	m_PATH = PATH;
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
		m_word_to_guess.push_back('_');
	}

	m_toGuess = m_word_to_guess.size();
}


void WordManager::randomize_word_index(const int range){
	m_index = rand()%range;
}

std::string WordManager::get_word(const int index){
	return m_words[index];
}
