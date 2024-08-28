#include <iostream>
#include "Board.h"
#include "Point.h"
#include <array>
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
Tile& Board::getTile(const std::size_t& r, const std::size_t& c){
	return this->array[r][c];
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
