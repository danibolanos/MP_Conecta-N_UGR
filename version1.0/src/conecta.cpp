#include<iostream>
#include<string.h>

#include "matriz.h"
#include "tablero.h"
#include "jugador.h"

using namespace std;

int main(){
   char nom1[50], nom2[50]; 
   char seguir = 'S';
   int filas=0, columnas=0, fichas=0, empates=0; 
   
   while(filas<4 || filas>20){
      cout << "Introduzca filas(4-20): ";
      cin >> filas;
   }
   while(columnas<4 || columnas>20){
      cout << "Introduzca columnas(4-20): ";
      cin >> columnas;
   }
   while(fichas<3 || fichas>20){
      cout << "Introduzca fichas a alinear(3-20): ";
      cin >> fichas;
      cin.ignore(1000,'\n');
   }   

  
   Tablero tablero(filas, columnas, fichas);
   
   cout << "Introduzca el nombre del primer jugador: ";
   cin.getline(nom1, 50);
      
   
   cout << "Introduzca el nombre del segundo jugador: ";
   cin.getline(nom2, 50);
   
   cout << "\n";

   Jugador jug1(nom1, 1);
   Jugador jug2(nom2, 2);
   
   while(seguir == 'S' || seguir == 's'){
   while( !tablero.finalizado() && !tablero.empate()){
      if (tablero.getTurno() == 1)
         jug1.escogeColumna(tablero);
      else
         jug2.escogeColumna(tablero);
   }
   
   cout << "\n";
   tablero.prettyPrint();
   cout << "\n";
   
   cout << "Partida finalizada. Ganador: ";
   if (tablero.ganador() == 1){
      cout << "jugador 1";
      jug1.nuevaVictoria(tablero);
   }
   else{
      if (tablero.ganador() == 2){
         cout << "jugador 2";
         jug2.nuevaVictoria(tablero);
      }
      else{
         cout << "Empate";
         empates++;
      }
    }
    cout << "\nResultados tras esta partida: \n";
    jug1.mostrarPuntuacion();
    jug2.mostrarPuntuacion();
    
    tablero.vaciar();
    
    cout << "¿Jugar de nuevo(S/N)?: ";
    cin >> seguir;
    }
    cout << "\nResultados finales: \n";
    jug1.mostrarPuntuacion();
    jug2.mostrarPuntuacion();
    cout << empates << " empatadas\n";
}
