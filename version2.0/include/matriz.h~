#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#include <iostream>

class Matriz{ 
   int *datos;
   int filas, columnas;

   public:
      Matriz();
      Matriz (int fils, int cols);
      ~Matriz(){
         delete[]datos;
         filas = 0;
         columnas = 0;
      }
      Matriz& operator=(const Matriz& m);
      int getFilas()const;
      int getColumnas()const;
      void setFilas(int fils);
      void setColumnas(int cols);
      int getElementio(int fils, int cols)const;
      void setElementio(int elementio, int fils, int cols);

      friend std::ostream& operator<<(std::ostream &flujo, const Matriz &m);
      
      friend std::istream& operator>>(std::istream &flujo, Matriz &m);
};

#endif
