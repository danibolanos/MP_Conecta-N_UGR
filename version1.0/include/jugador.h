#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include "tablero.h"


class Jugador{
   static const int TAM_MAX=50;
   char nombre[TAM_MAX];
   int turno;
   int puntuacion;
   int victorias;

   public:
      Jugador(char nombrecito[] ,int turnito);
      void escogeColumna(Tablero &tablero);
      void nuevaVictoria(Tablero &tablero);
      void mostrarPuntuacion();      
};

#endif
