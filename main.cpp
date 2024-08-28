#include <iostream>
#include "Tile.h"
#include "Board.h"
#include "UserInput.h"
#include "Direction.h"
#include "Point.h"
#include "Random.h"
#include <stdexcept>

int main(){
	try{
		Board board{};
		board.RandomizeBoard();
		std::cout << board;

		std::cout << "Generating random direction... " << Direction::getRandomDirection() << '\n';
		std::cout << "Generating random direction... " << Direction::getRandomDirection() << '\n';
		std::cout << "Generating random direction... " << Direction::getRandomDirection() << '\n';
		std::cout << "Generating random direction... " << Direction::getRandomDirection() << "\n\n";

		while (!board.isFinished())
    		{
        		char ch{ UserInput::getCommandFromUser() };

		        // Handle non-direction commands
		        if (ch == 'q')
		        {
		        	std::cout << "\n\nBye!\n\n";
		            	return 0;
	        	}	

	        	// Handle direction commands
		        Direction dir{ ch };
				
		        std::cout << "You entered direction: " << dir << '\n';
				board.moveTile(dir);
				std::cout << board;
			}
		std::cout << "You won!!!";
	}
	catch(std::runtime_error& err){
		std::cout << "Ran into the following runtime error: " << err.what();
	}
	return 0;
}
