CXXFLAGS= -Wall -Wextra -O0

.PHNOY: all

all : test_bakcand Piece.o Board.o Player.o test_file.o

test_bakcand : Piece.o Board_cell.o Board.o Player.o  test_file.o
	g++ $(optimization) -g  Piece.o Board_cell.o Board.o Player.o test_file.o -o test_bakcand

Piece.o : include/framework/Piece.cpp
	g++ $(optimization) -c -g include/framework/Piece.cpp

Board_cell.o : include/framework/Piece.cpp
	g++ $(optimization) -c -g include/framework/Board_cell.cpp

Board.o : include/framework/Board.cpp
	g++ $(optimization) -c -g include/framework/Board.cpp

Player.o : include/framework/Player.cpp
	g++ $(optimization) -c -g include/framework/Player.cpp

test_file.o : test_file.cpp
	g++ $(optimization) -c -g test_file.cpp


clean : 
	rm  Piece.o Board_cell.o Board.o Player.o test_file.o test_bakcand
