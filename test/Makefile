CXXFLAGS= -Wall -Wextra -O0

.PHNOY: all

all : test_bakcand other_pieces.o Piece.o Board.o Player.o Game.o test_file.o

test_bakcand : other_pieces.o Piece.o Board.o Player.o Game.o test_file.o
	g++ $(optimization) -g other_pieces.o Piece.o Board.o Player.o Game.o test_file.o -o test_bakcand

other_pieces.o : other_pieces.cpp
	g++ $(optimization) -c -g other_pieces.cpp 

Piece.o : Piece.cpp
	g++ $(optimization) -c -g Piece.cpp

Board.o : Board.cpp
	g++ $(optimization) -c -g Board.cpp

Game.o : Game.cpp
	g++ $(optimization) -c -g Game.cpp

Player.o : Player.cpp
	g++ $(optimization) -c -g Player.cpp

test_file.o : test_file.cpp
	g++ $(optimization) -c -g test_file.cpp


clean : 
	rm other_pieces.o Piece.o Board.o Player.o Game.o test_file.o test_bakcand
