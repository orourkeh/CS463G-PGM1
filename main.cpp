#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <time.h>
#include "Board.h"

const int NUM_BOARDS = 5;
const int RANDOM_LOWER = 10;
const int RANDOM_UPPER = 20;
int exploredNodes = 0;

class Board;//need forward decleration for some reason
class node
{
private:
	
	
	int depth;//depth in tree
	int h;//hueristic

public:
	int lastMove;//  lastMove 0 = forward 1 = backward 2 = rotate
	Board board;
	bool clockwiseChild;
	bool counterChild;
	bool rotateChild;
	node * parent;
	node() {}
	node(int level, Board b, node* p)
	{
		depth = level;
		board = b; 
		rotateChild = false;
		counterChild = false;
		clockwiseChild = false;
		parent = p;
	}
	int getHueristic()
	{
		h = board.computeHueristic();
		return h;
	}
	int getDepth()
	{
		return depth;
	}
	bool solution()
	{
		return board.test();
	}
	node makeChild()
	{
		Board childBoard = board;
		int move;
		if (!clockwiseChild)
		{
			clockwiseChild = true;
			childBoard.moveForward();
			move = 0;
		}
		else if (!counterChild)
		{
			counterChild = true;
			childBoard.moveBackwards();
			move = 1;
		}
		else if (!rotateChild)
		{
			rotateChild = true;
			childBoard.rotate();
			move = 2;
		}
		else if( rotateChild && clockwiseChild && counterChild)
		{
			std::cout << "tried to makechild of full node" << std::endl;
		}
		else
		{

		}
		node childNode(depth + 1, childBoard, this);
		childNode.lastMove = move;
		return childNode;
	}
};

void IMAstar(node, int);
int search(node, int, std::vector<node>&);
void solutionStat(std::vector<node>&, node);
//void SMAstar(node n);
int main()
{
	//Create 5 random boards with = k values
	srand(time(NULL));
	int moves = rand() % RANDOM_UPPER + RANDOM_LOWER;
	moves = 19;
	//std::vector<Board> boardList(5, Board(moves)); causes all boards to be the same
	for(int i = 0; i < NUM_BOARDS; i++)
	{	
		Board b(moves);
		node root(0, b, NULL);//depth 0 board=b parent =NULL
		//root.board.display();
		IMAstar(root, moves);
		std::cout << "Randomizer took: " << moves << " moves.\n\n";
	}
	
	char c;
	std::cin >> c;

	return 0;
}


void IMAstar(node root, int moves)
{
	int bound = root.getHueristic();
	std::vector<node> results;
	while (true)
	{
		results.push_back(root);
		int f = search(root, bound, results);
		if (f ==  -1)//is solution
		{
			return;//return found
		}
		else if (f == std::numeric_limits<int>::max())//no solution
		{
			std::cout << "There is no solution / solution is larger than 32bit int " << std::endl;
			return;
		}
		else
		{
			bound = f;
		}
	}
	

}
void solutionStat(std::vector<node>& results, node solved)
{
	std::vector<int> moveList;
	node* n = &solved;
	while(n != NULL)
	{
		moveList.push_back(n->lastMove);
		n = n->parent;
	}
	std::cout << "Nodes Expanded: " << results.size() << std::endl;
	std::cout << "Solution takes: " << moveList.size() << " moves.\n";
}
int search(node n, int bound, std::vector<node>& results)
{
	int f = n.getHueristic() + n.getDepth();
	if (f > bound)
	{
		return f;
	}
	if (n.solution())
	{
		solutionStat(results, n);
		return -1;//found
	}
	int min = std::numeric_limits<int>::max();
	//make children here
	node children[3];
	node child = n.makeChild();
	children[0] = child; 
	//child.board.display();
	child = n.makeChild();
	children[1] = child; 
	//child.board.display();
	child = n.makeChild();
	children[2] = child; ;
	for (int i = 0; i < 3; i++)
	{
		exploredNodes++;
		int t = search(children[i], bound, results);
		if (t == -1)//found
		{
			results.push_back(children[i]);
			return t;//found
		}
		else if (t < min)
		{
			results.push_back(children[i]);
			min = t;
		}
	}

	return min;
}