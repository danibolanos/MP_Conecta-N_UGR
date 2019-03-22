#include "jugador.h"
#include "tablero.h"
#include <string.h>
#include <iostream>

using namespace std;

      Jugador::Jugador(char nombrecito[], int turnito)
      {  strcpy(nombre, nombrecito);
         turno = turnito;
         puntuacion = 0;
         victorias = 0;
      }
      void Jugador::escogeColumna(Tablero &tablero){
         char columna;
         char ficha;
         
         tablero.prettyPrint();
         
         if (turno == 1)
            ficha = 'x';
         else 
            ficha = 'o';
         
         cout << "Turno: jugador " << turno << ": (" << ficha << ")\n"; 
         cout << nombre << ", escoja una columna: ";
         cin >> columna;
         tablero.insertar(columna-'a');
      }
      void Jugador::nuevaVictoria(Tablero &tablero){
	 victorias++;
	 puntuacion+=tablero.puntuacion();
      }
      void Jugador::mostrarPuntuacion(){
	 cout << nombre << ": " << victorias << " ganadas que acumulan " << puntuacion << " puntos\n";
      }
      
