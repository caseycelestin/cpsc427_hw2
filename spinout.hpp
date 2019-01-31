#ifndef __SPINOUT_HPP__
#define __SPINOUT_HPP__

#include <string>

namespace cs427_527
{
	class SpinOut
	{
	public:

		//SpinOut construtor
		// No argument so initialize to "///////"
		SpinOut();
		
		// SpinOut constructor
		// Takes a string pointer from user input
		SpinOut(std::string& s);
		
		// Checks if move is legal
		// Takes int 0 to 6 inclusive, numbered left to right 0123456
		bool isLegalMove(int i);
		
		// Executes move
		// Checks to see if move is legal, then rotates to other orientation
		void makeMove(int i);
		
		// Returns number of legal moves completed
		int totalMoves() const;
		
		// Check to see if puzzle solved
		// Looking for "-------"
		bool isSolved() const;
		
		// Returns string representation of puzzle
		std::string toString(); 
		
	private:
		// Size of puzzle
		static const int SIZE = 7;
		
		// String representation of puzzle
		std::string puzzle;
		
		// Number of moves completed
		int total_moves;
	};
}

#endif
