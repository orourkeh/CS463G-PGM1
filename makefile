COMPILER=g++ -std=c++11
SOURCES=main.cpp Board.cpp Board.h
EXEC=program

all: clean build run

build:
	$(COMPILER) $(SOURCES) -o $(EXEC)

clean:
	rm program
run:
	./$(EXEC)

