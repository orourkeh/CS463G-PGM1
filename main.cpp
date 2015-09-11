#include <iostream>
#include <vector>
//#include <queue>

#include "Board.cpp"
int main()
{
	Board myBoard(100);//argument is the number of moves in shuffle
	myBoard.display(); 

//	std::priority_queue<Board> queue;


	//create tree of boards with children containing all possible moves from parent
	//Nodes will have 3 children forward, backward and rotate
	//Moves that would undo last move will be set to NULL
	


return 0;
}
