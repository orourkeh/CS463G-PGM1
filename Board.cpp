
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
		srand(time(NULL));
		for (int i = 1; i <= NUM_BALLS; i++)//fill ball vector with 1 - 20
                {
                        m_balls.push_back(i);
                }
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
	Board::Board(const Board &b)
	{
	
	}
	const int Board::getHueristic()
	{
		return m_hueristic;	
	}

	int Board::findBall(int ball)
	{
		for (int i = 0; i < NUM_BALLS; i++)
		{
			if (m_balls[i] = ball)
			{
				return i;
			}
		}
	}
		//code to find value of huerstic
		/*

		 HA Dont have to do this yet
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
			m_hueristic += ;
			m_hueristic += 4;
		}
		*/ 
	void Board::computeHueristic()
	{
		//compute hueristic
	}
	void Board::rotate()
	{
		this->swap(12, 15);
		this->swap(13, 14);
	}
	void Board::moveForward()
	{
		std::rotate(m_balls.begin(), m_balls.end()-1, m_balls.end());
	}
	void Board::moveBackwards()
	{
		std::rotate(m_balls.begin(), m_balls.begin() + 1, m_balls.end());
	}	

	void Board::shuffle(int numMoves)
	{
		int count = 0;
		int lastMove = -1;
		while(count <= numMoves)
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
		//reset stats for a new board
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
