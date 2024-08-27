#include <iostream>
#include "Board.h"
#include "Point.h"
#include <stdexcept>
std::ostream& operator<<(std::ostream& out, const Board& b){
	for(int i{0}; i< g_console_line; ++i){
		out << '\n';
	}
	for(std::size_t i {0}; i< b.col; ++i ){
		for(std::size_t j{0}; j<b.row; ++j){
			out << b.array[i][j];
		}
		out << '\n';
	}
	return out;
}
Tile& Board::getTile(std::size_t r, std::size_t c){
	return this->array[r][c];
}
void Board::moveTile(Direction d){
	std::size_t row;
	std::size_t col;
	Tile& empty {this->findTile(row,col)};
	Point e {static_cast<int>(row), static_cast<int>(col)};
	e.getAdjacentPoint(-d);
	if(e.m_x < 0 || e.m_x > 3 || e.m_y < 0 || e.m_y > 3 ||(Board::getTile(static_cast<std::size_t>(e.m_x),static_cast<std::size_t>(e.m_y)).isEmpty())) return;
	std::swap(empty,Board::getTile(static_cast<std::size_t>(e.m_x),static_cast<std::size_t>(e.m_y)));
}
Tile& Board::findTile(std::size_t& row, std::size_t& col){
	Tile empty {0};
	for(std::size_t i {0}; i< this->col; ++i ){
		for(std::size_t j{0}; j<this->row; ++j){
			if(this->array[i][j] == empty){
				row = i;
				col = j;
				return this->array[i][j];
			}
		}
	}
	throw std::runtime_error("There was't any tile with that value");
}
bool Board::isFinished(){
	int c{0};
	for(std::size_t i{0};i< this->col;++i){
		for(std::size_t j{0};j< this->row;++j){
			if((i==0 && j==0) || (i == 3 && j==3 )){
				if(!(this->array[i][j]== Tile{0})) return false;
			}
			else {
				if(!(this->array[i][j]==Tile{c++})) return false; 
			}
		}
	}
	return true;
}
