#ifndef _MATRIZ_H_
#define _MATRIZ_H_

class Matriz{
   static const int MAX = 20; 
   int datos[MAX][MAX];
   int filas, columnas;

   public:
      Matriz (int fils, int cols);
      int getFilas()const;
      int getColumnas()const;
      int getElementio(int fils, int cols)const;
      void setElementio(int elementio, int fils, int cols);
};

#endif
