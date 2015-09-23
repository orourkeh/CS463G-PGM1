#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <stdlib.h>
#include <time.h>
#include "Board.h"

const int NUM_BOARDS = 5;
const int RANDOM_LOWER = 10;
const int RANDOM_UPPER = 100;

class Board;//need forward decleration for some reason
class node
{
	int level, f;
	node* clockwiseChild = NULL;
	node* counterChild = NULL;
	node* rotateChild = NULL;
	public:
	Board board;
	node(int pLevel, Board b)
	{
		level = pLevel;
	//	board = b; need to make assingment constructor
	}
	void updateF()
	{
		f = level + this->board.getHueristic();
	}	
};

bool operator<(const node& a, const node& b)
{
	return a.board.huer < b.board.huer;
}
void SMAstar(node n);
int main()
{
	//Create 5 random boards with = k values
	srand(time(NULL));
	int moves = rand() % RANDOM_UPPER + RANDOM_LOWER;
	std::vector<Board> boardList(5, Board(moves));
		
	for(int i = 0; i < NUM_BOARDS; i++)
	{	
		node root(0, boardList[i]);
		SMAstar(root);
	}

	//std::priority_queue<node> q;
	/*
			bset <- deepest least cost node
			if best ==  solution return success
			child = best->makeCHild
			child.f = max(best.f, child.huer + depth)
			if all best children made backup(best)
			if S(best) all in memory remove best from queue
			used ++
			if used > max
				delet sholloweest, highest f-cost node in queue
				remove it from parent's sucessor list
				insert its parents on quue if needed
				used --
			insert child in queue	
				
		*/
		/*
			BACKUP(node)	

		*/
	
	//create tree of boards with children containing all possible moves from parent
	//Nodes will have 3 children forward, backward and rotate
	//Moves that would undo last move will be set to NULL
	


return 0;
}

void SMAstar(node n)
{
	std::priority_queue<int> q;

}
