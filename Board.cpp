
#include "Board.h"
	void Board::swap(int a, int b)
	{
		int tmp = m_balls[a];
		m_balls[a] = m_balls[b];
		m_balls[b] = tmp;
	}
	//end extra variables
	//get balls
	Board::Board()//allows node class to work
	{
	}
	Board::Board(int shuffles)
	{
		srand(time(NULL));
		for (int i = 1; i <= NUM_BALLS; i++)//fill ball vector with 1 - 20
		{
			m_balls.push_back(i);
		}
		this->shuffle(shuffles);
	}

	int Board::findBall(int ball)
	{
		for (int i = 0; i < NUM_BALLS; i++)
		{
			if (m_balls[i] == ball)
			{
				return i;
			}
		}
	}

	int Board::computeHueristic()
	{
		//code to find value of huerstic
		int m = 0;
		for(int i = 0; i < m_balls.size(); i++)
		{
			m += abs(i+1 - findBall(m_balls[i]));
		}
		return floor((m+19)/20);
	}
	void Board::rotate()
	{
		this->swap(2, 5);
		this->swap(3, 4);
	}
	void Board::moveForward()
	{
		int overflow = m_balls[m_balls.size()-1];
		for (int i = m_balls.size() - 1; i > 0; i--)
		{
			m_balls[i] = m_balls[i-1];
		}
		m_balls[0] = overflow;
	}
	void Board::moveBackwards()
	{
		int overflow = m_balls[0];
		for (int i = 0; i < m_balls.size() - 1; i++)
		{
			m_balls[i] = m_balls[i+1];
		}
		m_balls[m_balls.size()-1] = overflow;
	}	
	bool Board::test()
	{
		for(size_t i = 0; i < m_balls.size(); i++)
		{
			if (m_balls[i] != i+1)
			{
				return false;
			}
		}
		return true;
	}
	void Board::shuffle(int numMoves)
	{
		int count = 0;
		int lastMove = -1;
		srand(time(NULL));
		while(count < numMoves)
		{
			int random = rand()%3;
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
			lastMove = random;
		}
	}
	void Board::display()
	{
		/*
			 1  2  3  4  5  6  7  8 
			20	 		  9
			19			  10
			18 17 16 15 14 13 12  11 

		*/
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
		std::cout << std::endl;
	}
