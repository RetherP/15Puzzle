#include <iostream>
#include "Tile.h"

std::ostream& operator<<(std::ostream& out, const Tile& t){
	if(t.m_num != 0){
		if(t.m_num>9){
			out << " "  << t.m_num << " " ;
		}
		else{
			out << "  " << t.m_num << " ";
		}	
	}
	else {
		out << "    ";
	}
	return out;
}
bool operator==(const Tile& t1, const Tile& t2){
	return t1.m_num == t2.m_num;
}

