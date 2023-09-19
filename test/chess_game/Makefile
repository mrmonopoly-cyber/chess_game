CXXFLAGS= -Wall -Wextra -O0

.PHNOY: all

all : test_bakcand Board_cell.o Piece.o Player.o Pawn.o Knight.o Game.o test_file.o

test_bakcand : Piece.o Board_cell.o Player.o Game.o Pawn.o Knight.o  test_file.o
	g++ $(optimization) -g  Piece.o Board_cell.o Player.o Pawn.o Knight.o Game.o test_file.o -o test_bakcand

Piece.o : include/framework/Piece.cpp
	g++ $(optimization) -c -g include/framework/Piece.cpp

Board_cell.o : include/framework/Piece.cpp
	g++ $(optimization) -c -g include/framework/Board_cell.cpp

# Board.o : include/framework/Board.cpp
# 	g++ $(optimization) -c -g include/framework/Board.cpp

Player.o : include/framework/Player.cpp
	g++ $(optimization) -c -g include/framework/Player.cpp

Game.o : include/chess_game/Game.cpp
	g++ $(optimization) -c -g include/chess_game/Game.cpp

Pawn.o : include/chess_game/Pawn.cpp  
	g++ $(optimization) -c -g include/chess_game/Pawn.cpp 

Knight.o : include/chess_game/Knight.cpp  
	g++ $(optimization) -c -g include/chess_game/Knight.cpp 

test_file.o : test_file.cpp
	g++ $(optimization) -c -g test_file.cpp


clean : 
	rm  Piece.o Board_cell.o Player.o Pawn.o Knight.o Game.o test_file.o test_bakcand
