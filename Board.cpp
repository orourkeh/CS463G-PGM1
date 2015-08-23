#include <iostream>
#include <algorithm>
#include <vector>

class Board
{
private:
	const int NUM_BALLS = 20;
	std::vector<int> m_balls;
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
		for (int i = 1; i <= NUM_BALLS; i++)//fill ball vector with 1 - 20
		{
			m_balls.push_back(i);
		}
		//this->shuffle();
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
	void shuffle()
	{
		std::random_shuffle(m_balls.begin(), m_balls.end());//randomly shuffle all balls with algorithm
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