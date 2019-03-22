#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include "tablero.h"

class Jugador{
   char *nombre;
   int turno;
   int puntuacion;
   int victorias;

   public:
      Jugador();
      Jugador(char nombrecito[],int turnito);
      ~Jugador(){
         delete[]nombre;
         puntuacion = 0;
         victorias = 0;
      }
      Jugador& operator=(const Jugador& j);
      bool escogeColumna(Tablero &tablero);
      void nuevaVictoria(Tablero &tablero);
      void mostrarPuntuacion();   

      friend std::ostream& operator<<(std::ostream &flujo, const Jugador &j);
      friend std::istream& operator>>(std::istream &flujo, Jugador &j);   
};

#endif
