// Implementation file of Spinout Class

#include "spinout.hpp"

#include <string>

namespace cs427_527
{
	SpinOut::SpinOut(std::string& s)
	{
		puzzle = s;
	}
	
	bool isLegalMove(int i)
	{
		return true;
	}
	
	void makeMove(int i)
	{
		
	}
	
	int totalMoves() const
	{
		return total_moves;	
	}
	
	bool isSolved() const
	{
		if (puzzle.compare("-------") == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	std::string toString()
	{
		return puzzle;
	}
}

