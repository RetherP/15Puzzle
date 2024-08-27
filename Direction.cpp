#include <iostream>
#include "Direction.h"

std::ostream& operator<<(std::ostream& out, const Direction& d){
	if(d.m_command == Direction::Type::up) out << "up"; 
	else if(d.m_command == Direction::Type::down) out << "down"; 
	else if(d.m_command == Direction::Type::left) out << "left";
	else if(d.m_command == Direction::Type::right) out << "right";
	else out << "Invalid direction";
	return out;
}
