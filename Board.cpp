#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <time.h>
const int NUM_BALLS =20;
class Board
{
private:
	std::vector<int> m_balls;
	Board* forwardChild;
	Board* backwardChild;
	Board* rotateChild;
	int m_predicted;
	int m_hueristic = 0;
	void swap(int a, int b)
	{
		int tmp = m_balls[a];
		m_balls[a] = m_balls[b];
		m_balls[b] = tmp;
	}
	//end extra variables
public:

	//get balls
	Board(int cost)
	{
		srand(time(NULL));
		for (int i = 1; i <= NUM_BALLS; i++)//fill ball vector with 1 - 20
		{
			m_balls.push_back(i);
		}
		m_predicted = cost;//cost should be = to the depth of this node
		this->shuffle(m_predicted);
	}
	int getHueristic()
	{
		//code to find value of huerstic
		for(int i = 0; i < m_balls.size(); i++)
		{
			int leftNeighbor;
			int rightNeighbor;
			if(m_balls[i] == 1)
			{
				leftNeighbor = 20;
				rightNeighbor = 2;
			}
			else if(m_balls[i] == 20)
			{
				leftNeighbor = 19;
				rightNeighbor = 1;
			}
			else
			{
				leftNeighbor = m_balls[i] - 1;
        	                rightNeighbor = m_balls[i] + 1;
			}
			m_hueristic += *(std::find(m_balls.begin(), m_balls.end(), leftNeighbor));// find returns iterator for integer
			m_hueristic += *(std::find(m_balls,being(),
		}
		
		return m_hueristic;
	}
	void moveForward()
	{
		std::rotate(m_balls.begin(), m_balls.end()-1, m_balls.end());
	}
	void moveBackwards()
	{
		std::rotate(m_balls.begin(), m_balls.begin() + 1, m_balls.end());
	}
	void rotate()
	{
		this->swap(12, 15);
		this->swap(13, 14);
	}
	Board* getForwardChild()
        {
                return forwardChild;
        }
        Board* getBackwardChild()
        {
                return backwardChild;
        }
        Board* getRotateChild()
        {
                return rotateChild;
        }

	void shuffle(int numMoves)
	{
		int count = 0;
		int lastMove = -1;
		while(count <= numMoves)
		{
			int random = rand()%3;
			lastMove = random;
			switch (random)
			{
				case 0:
					if(lastMove != 1)
					{
						this->moveForward();
						count++;
					}
				case 1:
					if(lastMove != 0)//stops undoing moves
					{
						this->moveBackwards();
						count++;
					}
				case 2:
						this->rotate();
						count++;
						//will be undone if repeated 20 but that is an unlikly case
			}
		}
		//reset stats for a new board
	}
	void display()
	{
		for (int i = 0; i < 8; i++)//top row
		{
			std::cout << m_balls[i] << "\t";
		}
		std::cout << std::endl << m_balls[19] << "\t\t\t\t\t\t\t" << m_balls[8] << std::endl;
		std::cout << m_balls[18] << "\t\t\t\t\t\t\t" << m_balls[9] << std::endl;
		for (int i = 17; i >= 10; i--)//bottom row
		{
			std::cout << m_balls[i] << "\t";
		}
	}

};
