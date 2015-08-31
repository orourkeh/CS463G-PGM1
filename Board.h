#include <iostream>
#include <algorithm>
#include <vector>

class Board
{
private:
	const int NUM_BALLS = 20;
	int numForwards = 0;
        int numBackwards = 0;
        int numRotate = 0;
	std::vector<int> m_balls;
public:
	Board(){};
	void moveForward(){};
	void moveBackwards(){};
	void rotate(){};
	void shuffle(int){};
	void display(){};
};
