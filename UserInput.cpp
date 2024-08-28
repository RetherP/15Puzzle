#include <iostream>
#include <limits>
#include "Direction.h"
#include "UserInput.h"
char UserInput::getCommandFromUser(){
	char in {};
	std::cout << "Enter a command: ";
	do{
		std::cin >> in; 
	}while(!UserInput::isValid(in));
	        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return in;
}
bool UserInput::isValid(const char c){
	return c == 'w' || c == 'a' || c == 's'  || c == 'd' || c == 'q';
}
