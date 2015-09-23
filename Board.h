#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <time.h>

class Board
{
private:
	const int NUM_BALLS = 20;//scalable except for display
	std::vector<int> m_balls;//List of ball values
	void swap(int,int);//swaps balls at index p1, p2
	void shuffle(int);//Does n random moves on *this
	int m_hueristic = 0;
public:
	int huer;
	Board();
	Board(const Board& b);
	Board(int);//Constructor
	int findBall(int);//Returns index of ball with # = paramter
	const int getHueristic();

	void computeHueristic();//Computes huerstic value of board and stores in m_hueristic
	
	void moveForward();//Rotates this->balls clockwise
	void moveBackwards();//Rotates this->balls counter-clockwise
	void rotate();//Rotates spinner

	void display();//Outputs Board to stdout
};

#endif
