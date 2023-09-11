CXXFLAGS= -Wall -Wextra -O0

.PHNOY: all

all : test_bakcand other_pieces.o Piece.o Game.o

test_bakcand : other_pieces.o Piece.o Game.o 
	g++ $(optimization) -g other_pieces.o Piece.o Game.o -o test_bakcand

other_pieces.o : other_pieces.cpp
	g++ $(optimization) -c -g other_pieces.cpp 

Piece.o : Piece.cpp
	g++ $(optimization) -c -g Piece.cpp

Game.o : Game.cpp
	g++ $(optimization) -c -g Game.cpp

clean : 
	rm other_pieces.o Piece.o Game.o test_bakcand
