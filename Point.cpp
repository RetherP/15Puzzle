#include "Point.h"
#include "Direction.h"
#include <iostream>

bool Point::operator==(const Point& p2){
	return this->m_x == p2.m_x && this->m_y == p2.m_y;
}
bool Point::operator!=(const Point& p2){
	return !((*this) == p2);
}
