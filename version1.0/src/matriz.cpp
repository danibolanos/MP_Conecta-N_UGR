#include "matriz.h"

      Matriz::Matriz (int fils, int cols){
      filas = fils;
          columnas = cols;
      for (int i=0; i < fils; ++i)
         for (int j=0; j < cols; ++j)
            datos[i][j]=0;
      }
      int Matriz::getFilas()const{
          return filas;
      }
      int Matriz::getColumnas()const{
          return columnas;
      }
      int Matriz::getElementio(int fils, int cols)const{
          return datos[fils][cols];
      }
      void Matriz::setElementio(int elementio, int fils, int cols){
          datos[fils][cols] = elementio;
      }
