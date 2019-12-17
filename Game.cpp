#include "Game.h"

int Game::Play(){
	
	int choose = 3;

	do{
	system("cls");
	std::cout << "\tHANGMAN" << std::endl;
	std::cout << "================================" << std::endl;

	std::cout << "1. Play" << std::endl;
	std::cout << "2. Exit" << std::endl;
	std::cout << ": ";
	std::cin >> choose;

	}while(choose > 2 || choose < 1);

	if(choose==1){
		char letter;
		int mistakes = wm->get_mistakes();
		system("cls");
		wm->LoadWordsFromFile();
		wm->randomize_word_index(15);
		wm->make_word_to_guess();
		board->set_start_board(' ');

		while(!(wm->get_isGuessed())){					std::cout << *(board) << std::endl;
			std::cout << std::endl;
			std::cout << wm->get_wordToGuess() << std::endl;
		std::cout << "Your letter: ";
		std::cin >> letter;
		wm->checkWord(letter);	
		if(mistakes < wm->get_mistakes()){
			board->update_hangman(17);
			mistakes++;
		}

		if(wm->get_mistakes() == 17){
			std::cout << "Sorry, you lost" << std::endl;
			return EXIT_SUCCESS;
		}

		}
		std::cout << "Congratulation! You guessed!" << std::endl;	
	std::cout << "Word: " << wm->get_wordToGuess() << std::endl;

	}
	else EXIT_SUCCESS;

}
