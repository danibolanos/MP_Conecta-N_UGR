AR = ar
CXX = g++
CXXFLAGS = -Wall -g
BIN = bin
OBJ = obj
INC = include
SRC = src

all : $(BIN)/conectaN

$(BIN)/conectaN : $(OBJ)/conecta.o $(OBJ)/matriz.o $(OBJ)/tablero.o $(OBJ)/jugador.o 
	$(CXX) -o $(BIN)/conectaN $(OBJ)/conecta.o $(OBJ)/matriz.o $(OBJ)/tablero.o $(OBJ)/jugador.o 

$(OBJ)/jugador.o : $(INC)/jugador.h $(SRC)/jugador.cpp
	$(CXX) -I./$(INC) -c -o $(OBJ)/jugador.o $(SRC)/jugador.cpp

$(OBJ)/matriz.o : $(INC)/matriz.h $(SRC)/matriz.cpp
	$(CXX) -I./$(INC) -c -o $(OBJ)/matriz.o $(SRC)/matriz.cpp

$(OBJ)/tablero.o : $(INC)/matriz.h $(INC)/tablero.h $(SRC)/tablero.cpp
	$(CXX) -I./$(INC) -c -o $(OBJ)/tablero.o $(SRC)/tablero.cpp

$(OBJ)/conecta.o : $(INC)/matriz.h $(INC)/tablero.h $(INC)/jugador.h $(SRC)/conecta.cpp
	$(CXX) -I./$(INC) -c -o $(OBJ)/conecta.o $(SRC)/conecta.cpp

clean:
	echo "Limpiando..."
	rm -f $(OBJ)/*.o
mrproper: clean
	rm -f $(BIN)/*
