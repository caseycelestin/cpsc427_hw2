#include "spinout.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using cs427_527::SpinOut;

void interactive(string* init, int size)
{
	SpinOut game;
	int move = 0;
	string input;

	if (size == 2)
	{
		game = SpinOut{};
		cout << game.toString() << endl;
	} else
	{
		game = SpinOut{init[2]};
		cout << game.toString() << endl;
	}
	
	while(std::getline(cin, input) && input.length() > 0)
	{
		std::istringstream sin{input};
		if(sin >> move)
		{
			game.makeMove(move);
			cout << game.toString() << endl;
			if (game.isSolved())
			{
				cout << game.totalMoves() << " moves" << endl;
				break;
			}
		} else {break;}
	}

}

void non_interactive(string* init, int size)
{
	SpinOut game;
	int index;
	int m = 1;
	if(init[1].find('/') != string::npos || init[1].find('-') != string::npos)
	{
		game = SpinOut{init[1]};
		index = 1;
	} else 
	{
		game = SpinOut{};	
		index = 0;
	}

	while (++index < size) 
	{
		if(!game.isLegalMove(std::stoi(init[index])))
		{
			cout << "Spinout: illegal move " << init[index] << " in position " << m << " for " << game.toString() << endl;
			return;
		} else
		{
			game.makeMove(std::stoi(init[index]));
			m++;
		}
	}

	if (game.isSolved())
	{
		cout << "SOLVED" << endl;
	} else
	{
		cout << game.toString() << endl;
	}
}


int main(int argc, char **argv)
{
	string* input = new string[argc];
	
	for (int i=0; i < argc; i++)
	{
		input[i] = argv[i];
	}

	
	if (input[1].compare("-i") == 0)
	{
		interactive(input, argc);
	} else
	{
		non_interactive(input, argc);
	}

	delete[] input;	
}
