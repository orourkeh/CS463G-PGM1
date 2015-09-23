COMPILER=g++ -std=c++11
SOURCES= Board.h main.cpp Board.cpp
EXEC=program

all: clean build run

build:
	$(COMPILER) $(SOURCES) -o $(EXEC)

clean:
	rm -f program
run:
	./$(EXEC)

