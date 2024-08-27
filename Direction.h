#ifndef DIRECTION_H
#define DIRECTION_H
#include <string>
#include <iostream>
#include <stdexcept>
#include "Random.h"
class Direction{
	public:
		enum Type{up, down, left, right, max}; 
	private:
		Type m_command{};
		Type convertToCommand(char c) {
			switch(c){
				case 'w' : return Type::up;
				case 's': return Type::down;
				case 'd': return Type::right;
				case 'a': return Type::left;
				case 'q': return Type::max;
				default: throw std::runtime_error("Invalid input failed to convert a char to a Direction");
			}	 
		}
	public:
		Direction() = default;
		Direction(Type c) : m_command{c} {}
		Direction(char c) : m_command{convertToCommand(c)} {}
		Direction operator-() const {
			if(m_command ==  Type::up)return Direction {Type::down};
			else if(m_command == Type::down) return Direction{Type::up};
			else if(m_command == Type::left) return Direction {Type::right};
			else if(m_command == Type::right) return Direction{Type::left};
			else return Direction{Type::max};
		}
		friend std::ostream& operator<<(std::ostream& out, const Direction& d); 
		static Direction getRandomDirection(){
			return Direction{static_cast<Type>(Random::get(0,3))};
		}
		Type getType() {return m_command;}
};
#endif
