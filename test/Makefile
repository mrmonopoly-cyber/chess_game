CXXFLAGS= -Wall -Wextra -O0

.PHNOY: all

all : test_bakcand other_pieces.o Piece.o Board.o

test_bakcand : other_pieces.o Piece.o Board.o 
	g++ $(optimization) -g other_pieces.o Piece.o Board.o -o test_bakcand

other_pieces.o : other_pieces.cpp
	g++ $(optimization) -c -g other_pieces.cpp 

Piece.o : Piece.cpp
	g++ $(optimization) -c -g Piece.cpp

Board.o : Board.cpp
	g++ $(optimization) -c -g Board.cpp

clean : 
	rm other_pieces.o Piece.o Board.o test_bakcand
