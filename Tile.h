#ifndef TILE_H
#define TILE_H
#include <iostream>
class Tile{
	private:
		int m_num{0};
	public:
		explicit Tile(int num) : m_num{num} {}
		Tile() = default;
		constexpr bool isEmpty() const {return m_num==0;}
		friend std::ostream& operator<<(std::ostream& out, const Tile& t);
		constexpr int getNum() const{return m_num;}
		friend bool operator==(const Tile& t1, const Tile& t2);
};
#endif
