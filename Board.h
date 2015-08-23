#include <iostream>
#include <algorithm>
#include <vector>

class Board
{
private:
	const int NUM_BALLS = 20;
	std::vector<int> m_balls;
public:
	Board(){};
	void moveForward(){};
	void moveBackwards(){};
	void rotate(){};
	void shuffle(){};
	void display(){};
};