Assumptions: 
	Board is only solved if in order (one-way) and ball 1 is located at index 0.
Limitations:
	If board is quickly solved ~500 or less nodes expanded then the next board will have the same random seed.
	Large boards with random moves >20 takes a long time to solve.
	Sometimes generates solution > random moves taken.  Could not find out cuase.
Data structure:
	Balls are stored in a vector<int> 
	Boards are stored in class Board
	Nodes contain last moves, parent pointer, board, and flag variables.
	Nodes of current expanded tree are stored in vector<nodes>
	“Bad nodes” are popped off when recursive function search() pops
