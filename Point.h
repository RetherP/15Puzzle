#pragma once
#include "Direction.h"
struct Point{ 
	int m_x{0};
	int m_y{0};
	constexpr Point(int x, int y) : m_x{x}, m_y{y} {}
	Point() = default;
	constexpr void getAdjacentPoint(const Direction d){
			switch(d.getType()){
					case Direction::DirectionType::up:
							--m_x;
							break;
					case Direction::DirectionType::down:
							++m_x;
							break;
					case Direction::DirectionType::right:
							++m_y;
							break;
					case Direction::DirectionType::left:
							--m_y;
							break;	
					default: 
						throw std::runtime_error("Invalid direction, Point cannot be modified");
			}
	}
	bool operator==(const Point& p2);
	bool operator!=(const Point& p2);
};