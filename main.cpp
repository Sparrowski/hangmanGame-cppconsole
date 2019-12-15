/* Hangman cpp game
 * Author: Kamil Wróblewski
 * Date: 15.12.2019
 * ************************************************/
#include <iostream>
#include "Hangman.h"
int main(){
	Hangman h;
	h.set_start_board(' ');
	int i = 0;
	while(i < 18){
		std::cout << "Current mistake: " << i << std::endl;
		h.hangman_draw();
		h.update_hangman(17);
		i++;
	std::cout << std::endl;
	}

	return 0;
}
