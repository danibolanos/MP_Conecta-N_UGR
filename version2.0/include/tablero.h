#ifndef _TABLERO_H_
#define _TABLERO_H_

#include "matriz.h"

class Tablero{
   Matriz matrixilla;
   int fichas;
   int fich_turno;
   int fich_insertada;
   int turno;
   bool finalizada;
   int ult_fil, ult_col;
   int movimientos;
   
   public:
      Tablero();
      Tablero(int filas, int columnas, int fichillas, int num);      
      int getFilas()const;
      int getColumnas()const;
      int getFichas()const;
      int getFichasTurno()const;
      int getFichasInsertadas()const;
      bool empate();
      int elementio(int fils, int cols);
      bool comprobarElementio(int fils, int cols, int elemento);
      bool finalizado();
      int getTurno();
      int ganador();
      int puntuacion();
      void insertar(int col);
      void vaciar();
      void prettyPrint(std::ostream& os = std::cout);
      friend std::ostream& operator<<(std::ostream &flujo, const Tablero &t);
      friend std::istream& operator>>(std::istream &flujo, Tablero &t);
};


#endif
