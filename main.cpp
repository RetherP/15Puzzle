#include <iostream>
#include "Tile.h"
#include "Board.h"
#include "UserInput.h"
#include "Direction.h"
#include "Point.h"
#include "Random.h"
#include <stdexcept>

void RandomizeBoard(Board& b){
	for(int i {0}; i<= 100; ++i){
		b.moveTile(Direction {static_cast<Direction::Type>(Random::get(0,3))});
	}
}
int main(){
	try{
		Board board{};
		RandomizeBoard(board);
		std::cout << board;

		std::cout << "Generating random direction... " << Direction::getRandomDirection() << '\n';
		std::cout << "Generating random direction... " << Direction::getRandomDirection() << '\n';
		std::cout << "Generating random direction... " << Direction::getRandomDirection() << '\n';
		std::cout << "Generating random direction... " << Direction::getRandomDirection() << "\n\n";

		while (true)
    		{
        		char ch{ UserInput::getCommandFromUser() };

		        // Handle non-direction commands
		        if (ch == 'q')
		        {
		        	std::cout << "\n\nBye!\n\n";
		            	return 0;
	        	}	

	        	// Handle direction commands
		        Direction dir{ UserInput::charToDirection(ch) };

		        std::cout << "You entered direction: " << dir << '\n';
			board.moveTile(dir);
			std::cout << board;
			if(board.isFinished()) break;
    		}
		std::cout << "You won!!!";
	}
	catch(std::runtime_error& err){
		std::cout << "Ran into the following runtime error: " << err.what();
	}
	return 0;
}
