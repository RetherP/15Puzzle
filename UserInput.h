#ifndef USERINPUT_H
#define USERINPUT_H
#include "Direction.h"
namespace UserInput{
	char getCommandFromUser();
	bool isValid(char c);
	Direction charToDirection(char c);
}

#endif
