CXXFLAGS= -Wall -Wextra -O0

.PHNOY: all

all : test_bakcand Board_cell.o Piece.o Pawn.o Knight.o Bishop.o Rook.o Queen.o King.o Game.o test_file.o

test_bakcand : Piece.o generic_chess_piece.o Board_cell.o Board_move_log.o Game.o Pawn.o Knight.o Bishop.o Rook.o Queen.o King.o test_file.o
	g++ $(optimization) -g  Piece.o generic_chess_piece.o Board_cell.o Board_move_log.o Pawn.o Knight.o Bishop.o Rook.o Queen.o King.o Game.o test_file.o -o test_bakcand

Piece.o : include/framework/Piece.cpp
	g++ $(optimization) -c -g include/framework/Piece.cpp

Board_move_log.o : include/framework/Board_move_log.cpp
	g++ $(optimization) -c -g include/framework/Board_move_log.cpp

Board_cell.o : include/framework/Piece.cpp
	g++ $(optimization) -c -g include/framework/Board_cell.cpp

generic_chess_piece.o : include/chess_game/backand/generic_chess_piece.cpp
	g++ $(optimization) -c -g include/chess_game/backand/generic_chess_piece.cpp

Game.o : include/chess_game/backand/Game.cpp
	g++ $(optimization) -c -g include/chess_game/backand/Game.cpp

Pawn.o : include/chess_game/backand/Pawn.cpp  
	g++ $(optimization) -c -g include/chess_game/backand/Pawn.cpp 

Knight.o : include/chess_game/backand/Knight.cpp  
	g++ $(optimization) -c -g include/chess_game/backand/Knight.cpp 

Bishop.o : include/chess_game/backand/Bishop.cpp  
	g++ $(optimization) -c -g include/chess_game/backand/Bishop.cpp 

Rook.o : include/chess_game/backand/Rook.cpp  
	g++ $(optimization) -c -g include/chess_game/backand/Rook.cpp 

Queen.o : include/chess_game/backand/Queen.cpp  
	g++ $(optimization) -c -g include/chess_game/backand/Queen.cpp 

King.o : include/chess_game/backand/King.cpp  
	g++ $(optimization) -c -g include/chess_game/backand/King.cpp 

test_file.o : test_file.cpp
	g++ $(optimization) -c -g test_file.cpp


clean : 
	rm  Piece.o generic_chess_piece.o Board_cell.o Board_move_log.o Pawn.o Knight.o Bishop.o Rook.o Queen.o King.o Game.o test_file.o test_bakcand
