#pragma once
#include "Direction.h"
#include "Tile.h"
#include "Point.h"
#include <array>
#include "Random.h"
#include <iostream>
constexpr int g_console_line {30};
class Board{
	private:
		static constexpr std::size_t col {4};
		static constexpr std::size_t row {4};
		std::array<std::array<Tile, 4>, 4> array{{
			{Tile{1}, Tile{2}, Tile{3},Tile {4}}, 
			{Tile{5}, Tile {6} ,Tile {7}, Tile {8}}, 
			{Tile {9} ,Tile {10}, Tile{11}, Tile {12}},
			{Tile{13}, Tile{14}, Tile{15}, Tile {}}	
		}};
	public:
	       	Board() = default;	
		friend std::ostream& operator<<(std::ostream& out, const Board& b);
		constexpr bool moveTile(Direction d){
			std::size_t e_row{};
			std::size_t e_col{};
			Tile& empty {this->findTile(e_row,e_col)};
			Point e {static_cast<int>(e_row), static_cast<int>(e_col)};
			e.getAdjacentPoint(-d);
			Tile& modifiedTile {(Board::getTile(static_cast<std::size_t>(e.m_x),static_cast<std::size_t>(e.m_y)))};
  			if(e.m_x < 0 || e.m_x >=row || e.m_y < 0 || e.m_y >= col  || (modifiedTile.isEmpty())){
				return false;
			}
			std::swap(empty,modifiedTile);
			return true;
		}
		Tile& findTile(std::size_t& row, std::size_t& col);
		Tile& getTile(const std::size_t& row, const std::size_t& col);
		bool isFinished();
		constexpr void RandomizeBoard(){
			for(int i {0}; i<= 100;){
				bool isMoved{moveTile(Direction {static_cast<Direction::DirectionType>(Random::get(0,3))})}; 
				if(isMoved){
						++i;
				}
		}}
};
