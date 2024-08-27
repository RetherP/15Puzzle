#ifndef POINT_H
#define POINT_H
#include "Direction.h"
class Point{
	public: 
		int m_x{0};
		int m_y{0};
		Point(int x, int y) : m_x{x}, m_y{y} {}
		Point() = default;
		Point getAdjacentPoint(Direction d);
		bool operator==(const Point& p2);
		bool operator!=(const Point& p2);
};
#endif
