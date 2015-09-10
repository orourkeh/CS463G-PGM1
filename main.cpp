#include <iostream>
#include <vector>
#include "Board.cpp"
int main()
{
	Board myBoard(100);//argument is the number of moves in shuffle
	myBoard.display(); 
	std::cout << myBoard.getHueristic() << std::endl;


	//create tree of boards with children containing all possible moves from parent
	//Nodes will have 3 children forward, backward and rotate
	//Moves that would undo last move will be set to NULL
	
	//To create child copy current Board then ->moveForward
	//Mkae copy constructor jackass.
return 0;
}
