#include <iostream>
#include "Direction.h"

std::ostream& operator<<(std::ostream& out, const Direction& d){
	switch(d.m_command){
		case Direction::DirectionType::up:
		       	out << "up"; 
			break;
		case Direction::DirectionType::down: 
			out << "down";
		        break;	
		case Direction::DirectionType::left: 
			out << "left";
			break;
		case Direction::DirectionType::right: 
			out << "right";
			break;
		default: 
			out << "Invalid direction";
			break;
	}
	return out;
}
