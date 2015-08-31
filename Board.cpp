#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <time.h>
class Board
{
private:
	const int NUM_BALLS = 20;
	std::vector<int> m_balls;
	int numForwards = 0;
	int numBackwards = 0;
	int numRotate = 0;
	void swap(int a, int b)
	{
		int tmp = m_balls[a];
		m_balls[a] = m_balls[b];
		m_balls[b] = tmp;
	}
public:

	//get balls
	Board()
	{
		srand(time(NULL));
		for (int i = 1; i <= NUM_BALLS; i++)//fill ball vector with 1 - 20
		{
			m_balls.push_back(i);
		}
		this->shuffle(100);
	}
	void moveForward()
	{
		std::rotate(m_balls.begin(), m_balls.end()-1, m_balls.end());
		numForwards++; 
	}
	void moveBackwards()
	{
		std::rotate(m_balls.begin(), m_balls.begin() + 1, m_balls.end());
		numBackwards++;
	}
	void rotate()
	{
		this->swap(12, 15);
		this->swap(13, 14);
		numRotate++;
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
					if(lastMove != 0)
					{
						this->moveBackwards();
						count++;
					}
				case 2:
						this->rotate();
						count++;
			}
		}
		//reset stats for a new board
		numForwards = 0;
		numBackwards = 0;
		numRotate = 0;
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
