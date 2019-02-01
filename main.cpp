#include "spinout.hpp"

#include <string>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using cs427_527::SpinOut;

void interactive(string* init, int size)
{
	SpinOut game;
	int move;

	if (size == 2)
	{
		game = SpinOut{};
		cout << game.toString() << endl;
	} else
	{
		game = SpinOut{init[2]};
		cout << game.toString() << endl;
	}
	
	while(cin >> move)
	{
		game.makeMove(move);
		cout << game.toString() << endl;
		if (game.isSolved())
		{
			cout << game.totalMoves() << " moves" << endl;
			break;
		}
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
	}

	delete[] input;	
}
