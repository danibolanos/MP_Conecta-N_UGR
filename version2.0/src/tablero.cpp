#include "tablero.h"

using namespace std;

      Tablero::Tablero():matrixilla(){
         fichas = 0;
         fich_turno = 0;
         fich_insertada = 0;
         turno = 0;
         finalizada = false;
         movimientos = 0;
      }
      Tablero::Tablero(int filas, int columnas, int fichillas, int num)
      :matrixilla(filas, columnas){
         fichas = fichillas;
         fich_turno = num;
         fich_insertada = 0;
         turno = 1;
         finalizada = false;
         movimientos = 0;
      }
      int Tablero::getFilas()const{
         return matrixilla.getFilas();
      }
      int Tablero::getColumnas()const{
         return matrixilla.getColumnas();
      }
      int Tablero::getFichas()const{
         return fichas;
      }
      int Tablero::getFichasTurno()const{
         return fich_turno;
      }
      int Tablero::getFichasInsertadas()const{
         return fich_insertada;
      }
      int Tablero::elementio(int fils, int cols){
         return matrixilla.getElementio(fils, cols);
      }
      bool Tablero::empate(){
	 bool empate = true;
	 for(int j=0; j<getColumnas() && empate; ++j){
		if(comprobarElementio(0,j,0))
			empate = false;
	 }
	 return empate;
      }
      bool Tablero::finalizado(){
         bool seguir=true;
         int ficha;
         int linea = 0;
         int f=ult_fil-fichas, c=ult_col-fichas;
         
         if (fich_insertada != 0)
            ficha = turno;
         else{
            if (turno == 2)
               ficha = 1;
            else 
               ficha = 2;
         }

         for(int i=-fichas; i<fichas && linea<fichas; ++i,++f,++c){
            if(comprobarElementio(f,c,ficha))
               ++linea;
            else
               linea = 0;
         }
         if(linea>=fichas)
            finalizada=true;
         else{
            linea=0;
	    f=ult_fil-fichas;
            c=ult_col;
            for(int i=-fichas; i<fichas && linea<fichas; ++i,++f){
               if(comprobarElementio(f,c,ficha))
                  ++linea;
               else
                  linea=0;
            }
            if(linea>=fichas)
               finalizada=true;
            else{
               linea=0;
	       f=ult_fil;
               c=ult_col-fichas;
               for(int i=-fichas; i<fichas && linea<fichas; ++i,++c){
                  if(comprobarElementio(f,c,ficha))
                     ++linea;
                  else
                     linea=0;
               }
               if(linea>=fichas)
                  finalizada=true;
               else{
                  linea=0;
	          f=ult_fil-fichas;
                  c=ult_col+fichas;
                  for(int i=-fichas; i<fichas && linea<fichas; ++i,++f,--c){
                     if(comprobarElementio(f,c,ficha))
                        ++linea;
                     else
                        linea=0;
                  }
                  if(linea>=fichas)
                     finalizada=true;
               }
            }
         }
         return finalizada;
      }
      bool Tablero::comprobarElementio(int fils, int cols, int elemento){
         bool igual = false;
         if (fils>=0 && fils<matrixilla.getFilas())
            if (cols>=0 && cols<matrixilla.getColumnas())
               if (elementio(fils,cols) == elemento)
                  igual = true;
         return igual;
      }
      int Tablero::getTurno(){
         return turno;
      }
      int Tablero::ganador(){
         int ganador;
         if(!finalizada)
	    ganador = 0;
         else{
            if (fich_insertada != 0)
               ganador = turno;
            else{
	       if (turno == 2)
                  ganador = 1;
               else
                  ganador = 2;
            }
         }
         return ganador;
      }
      int Tablero::puntuacion(){
         int puntos;
         puntos = fichas*fichas*fichas + 150 - movimientos*fich_turno;
         return puntos;
      }
      void Tablero::insertar(int col){
         int fil = getFilas()-1;
         while (elementio(fil, col) != 0)
            fil--;
         matrixilla.setElementio(turno, fil ,col);
         ult_fil = fil;
         ult_col = col;
         fich_insertada++;
         if (fich_insertada == fich_turno){
            fich_insertada = 0;
            movimientos++;
            if (turno == 1)
               turno++;
            else
               turno--;
         }
      }
      void Tablero::vaciar(){
         for (int i=0; i < getFilas(); ++i)
            for (int j=0; j < getColumnas(); ++j)
               matrixilla.setElementio(0,i,j);
         finalizada = false;
         fich_insertada=0;
         if (movimientos % 2 == 0){
            if (turno == 1)
               turno = 2;
            else
               turno = 1;
         }
         movimientos = 0;  
      }
      void Tablero::prettyPrint(ostream& os){
         char elemento;
         for (char l='a'; l < 'a'+ getColumnas(); ++l)
         	os << " " << l;
         os << "\n";
         for (int i=0; i < getFilas(); ++i){
            for (int j=0; j < getColumnas(); ++j){
            	if (elementio(i,j) == 0)
            	   elemento = ' ';
            	else{
            		if (elementio(i,j) == 1)
            		   elemento = 'x';
            		else
            		   elemento = 'o';
				}
            	os << "|" << elemento;
			}
            os << "|" << endl;
         }
         for (int k=0; k <= getFilas(); ++k)
         	os << "--";
         os << "\n";
	  }

      ostream& operator<<(ostream &flujo, const Tablero &t){
         flujo << t.matrixilla; 
	 flujo << t.fichas << ' ' << t.fich_turno << ' ' << 
         t.fich_insertada << ' ' << t.turno << ' ' <<
         t.finalizada << ' ' << t.ult_fil << ' ' << t.ult_col 
         << ' ' << t.movimientos << ' ';
         return flujo;
      }
      
      istream& operator>>(istream &flujo, Tablero &t){
         flujo >> t.matrixilla; 
	 flujo >> t.fichas >> t.fich_turno >> 
         t.fich_insertada >> t.turno >> t.finalizada 
         >> t.ult_fil >> t.ult_col >> t.movimientos;
         return flujo;
      }
