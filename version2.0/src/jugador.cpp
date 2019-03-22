#include "jugador.h"
#include "tablero.h"

#include <string.h>
#include <cstdlib>
#include <ctime>

using namespace std;

      Jugador::Jugador(){
         puntuacion = 0;
         victorias = 0;
         srand (time(0));
      }
      Jugador::Jugador(char nombrecito[], int turnito)
      {  int i=0;
         while(nombrecito[i] != '\0')
            ++i;
         char *aux = new char[i+1];
         for(int j=0; j<i; ++j)
            aux[j] = nombrecito[j];
         aux[i] = '\0';
         nombre = aux; 
         turno = turnito;
         puntuacion = 0;
         victorias = 0;
         srand (time(0));
      }
      Jugador& Jugador::operator=(const Jugador& j){
         if (this!=&j){
            turno=j.turno;
            puntuacion=j.puntuacion;
            victorias=j.victorias;
            int i=0;
            while(j.nombre[i] != '\0')
               ++i;
            char *aux = new char[i+1];
            for(int k=0; k<i; ++k)
               aux[k] = j.nombre[k];
            aux[i] = '\0';
            nombre = aux;
            }
         return *this;
      }
      bool Jugador::escogeColumna(Tablero &tablero){
         bool exito = false;
         int columna;
         char letra, ficha;
         bool aleatorio = false;
         
         if (nombre[0] == '@'){
            double u= rand() / (RAND_MAX+1.0);
            columna = tablero.getColumnas() * u;
            aleatorio = true;
         }
         else{
         tablero.prettyPrint();
         
         if (turno == 1)
            ficha = 'x';
         else 
            ficha = 'o';

         letra = 'a' + tablero.getColumnas() -1;

         cout << "Turno: jugador " << turno << ": (" << ficha << ")\n"; 
         cout << nombre << ", escoja una columna (letra a - " << letra << ") para la ficha " << tablero.getFichasInsertadas()+1 << " de " << tablero.getFichasTurno() << ": ";
         cin >> letra;
         columna = letra - 'a';
         }
         if (tablero.comprobarElementio(0,columna,0)){
            exito = true;
            tablero.insertar(columna);
         }
         else
            if (aleatorio){
               exito = true;  
            }
         return exito;
      }
      void Jugador::nuevaVictoria(Tablero &tablero){
	 victorias++;
	 puntuacion+=tablero.puntuacion();
      }
      void Jugador::mostrarPuntuacion(){
	 cout << nombre << ": " << victorias << " ganadas que acumulan " << puntuacion << " puntos\n";
      }

      ostream& operator<<(ostream &flujo, const Jugador &j){
	 flujo << '\n' << j.nombre << '\n' << j.turno <<
         ' ' <<  j.puntuacion << ' ' << j.victorias;
         return flujo;
      }
      
      istream& operator>>(istream &flujo, Jugador &j){
         char nombre[256];
         int turno, puntuacion, victorias;
	 flujo.ignore(1000,'\n');
         flujo.getline(nombre, 256);
         flujo >> turno >> puntuacion >> victorias;

         Jugador j2(nombre,turno);

         j2.puntuacion = puntuacion;
         j2.victorias = victorias;

         j=j2;

         return flujo;
      }
      
