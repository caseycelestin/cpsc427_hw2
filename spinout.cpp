// Implementation file of Spinout Class

#include "spinout.hpp"

#include <string>
#include <iostream>

using std::cout;
using std::endl;

namespace cs427_527
{
	SpinOut::SpinOut()
	{
		puzzle = "///////";
		total_moves = 0;
	}
	
	SpinOut::SpinOut(std::string& s)
	{
		if (s.length() != SIZE)
		{
			throw std::invalid_argument("Input not 7 characters");
		}
		for (int i = 0; i < SIZE; i++)
		{
			if (s[i] != '-' && s[i] != '/')
			{
				throw std::invalid_argument("Input contains invalid characters (must use '/' or '-')");
			}
		}
		puzzle = s;
		total_moves = 0;
	}
	
	bool SpinOut::isLegalMove(int i)
	{
		bool check = true;
		if ( i >= SIZE || i < 0)
		{
			throw std::invalid_argument("Chosen move out of puzzle board bounds");
		}
		while (++i != SIZE)
		{
			if (check)
			{
				if (puzzle[i] == '-')
				{
					return false;
				}
				check = false;
			} else 
			{
				if (puzzle[i] == '/')
				{
					return false;
				}
			}	
		}
		return true;
	}
	
	void SpinOut::makeMove(int i)
	{
		if(!isLegalMove(i))
		{
			cout << "illegal move" << endl;
		} else {
			if (puzzle[i] == '/')
			{
				puzzle[i] = '-';
			} else {
				puzzle[i] = '/';
			}
		total_moves++;
		}
	}
	
	int SpinOut::totalMoves() const
	{
		return total_moves;	
	}
	
	bool SpinOut::isSolved() const
	{
		if (puzzle.compare("-------") == 0)
		{
			return true;
		}
		return false;
	}
	
	std::string SpinOut::toString()
	{
		return puzzle;
	}
}

