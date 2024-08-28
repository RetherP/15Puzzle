#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include "Random.h"
class Direction{
	public:
		enum class DirectionType{up, down, left, right, max}; 
	private:
		DirectionType m_command{};
		DirectionType  convertToCommand(char c) {
			switch(c){
				case 'w' : return DirectionType::up;
				case 's': return DirectionType::down;
				case 'd': return DirectionType::right;
				case 'a': return DirectionType::left;
				case 'q': return DirectionType::max;
				default: throw std::runtime_error("Invalid input failed to convert a char to a Direction");
			}	 
		}
	public:
		Direction() = default;
		constexpr Direction(DirectionType d): m_command{d} {}
		constexpr Direction(char c) : m_command{convertToCommand(c)} {}
		constexpr Direction operator-() const {
			switch(m_command){
				case DirectionType::up:
						return Direction{DirectionType::down};
				case DirectionType::down: 
						return Direction{DirectionType::up};
				case DirectionType::left:
						return Direction{DirectionType::right};
				case DirectionType::right:
					       	return Direction{DirectionType::left};
				default:
					       	return Direction{DirectionType::max};
			}
		}
		friend std::ostream& operator<<(std::ostream& out, const Direction& d); 
		static Direction getRandomDirection(){
			return Direction{static_cast<DirectionType>(Random::get(0,3))};
		}
		constexpr DirectionType getType() const {return m_command;}	
};