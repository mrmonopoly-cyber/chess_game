CXXFLAGS= -Wall -Wextra -O0

.PHNOY: all

all : test_bakcand Piece.o Board.o Player.o test_file.o

test_bakcand : Piece.o Board_cell.o Board.o Player.o  test_file.o
	g++ $(optimization) -g  Piece.o Board_cell.o Board.o Player.o test_file.o -o test_bakcand

Piece.o : Piece.cpp
	g++ $(optimization) -c -g Piece.cpp

Board_cell.o : Piece.cpp
	g++ $(optimization) -c -g Board_cell.cpp

Board.o : Board.cpp
	g++ $(optimization) -c -g Board.cpp

Player.o : Player.cpp
	g++ $(optimization) -c -g Player.cpp

test_file.o : test_file.cpp
	g++ $(optimization) -c -g test_file.cpp


clean : 
	rm  Piece.o Board_cell.o Board.o Player.o test_file.o test_bakcand
