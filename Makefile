CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

main: tictac.o board.o main.o
	$(CC) $(CFLAGS) -o main tictac.o board.o main.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
tictac.o: tictac.cpp 
	$(CC) $(CFLAGS) -c tictac.cpp

board.o: board.cpp 
	$(CC) $(CFLAGS) -c board.cpp

clean:
	rm -f *.o tictac