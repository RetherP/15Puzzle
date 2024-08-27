#ifndef BOARD_H
#define BOARD_H
#include "Direction.h"
#include "Tile.h"
#include <iostream>
constexpr int g_console_line {30};
class Board{
	private:
		std::size_t col {4};
		std::size_t row {4};
		Tile array[4][4]{
			{Tile{1}, Tile{2}, Tile{3},Tile {4}}, 
			{Tile{5}, Tile {6} ,Tile {7}, Tile {8}}, 
			{Tile {9} ,Tile {10}, Tile{11}, Tile {12}},
			{Tile{13}, Tile{14}, Tile{15}, Tile {}}	
		};
	public:
	       	Board() = default;	
		friend std::ostream& operator<<(std::ostream& out, const Board& b);
		void moveTile(Direction d);
		Tile& findTile(std::size_t& row, std::size_t& col);
		Tile& getTile(std::size_t row, std::size_t col);
		bool isFinished();
};
#endif
