#include "Point.h"
#include "Direction.h"
Point Point::getAdjacentPoint(Direction d){
	if (d.getType() == Direction::Type::up) --m_x;
	else if (d.getType() == Direction::Type::down) ++m_x;
	else if (d.getType() == Direction::Type::right) ++m_y;
	else if (d.getType() == Direction::Type::left) --m_y;	
	else throw std::runtime_error("Invalid direction, Point cannot be modified");
	return *(this);
}
bool Point::operator==(const Point& p2){
	return this->m_x == p2.m_x && this->m_y == p2.m_y;
}
bool Point::operator!=(const Point& p2){
	return !((*this) == p2);
}
