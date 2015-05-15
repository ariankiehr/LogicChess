/*  LogicChess: Herramienta didactica para el aprendizaje practico de la Logica de Primer Orden
 *  Copyright (C) 2011  Arian Kiehr, Matias Ariel Re Medina
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MODELO_H
#define MODELO_H

#include "Ficha.hpp"
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <map>
#include <list>

#define EoF "eof"
#define POSTIPO 0
#define POSCOLOR 1
#define POSX 2
#define POSY 3
#define POSNOMBRE 4
#define VACIO ""
#define ERR -1
#define MAXNUMERO 7
#define MINNUMERO 0
#define NUMCOORDENADAS 2

#define CHARTOINT(a) (int)a-48;


/**
 * Clase que representa el modelo, guarda la informacion de todos
 * los elementos del mismo y permite obtener cualquier dato
 * de cada uno de ellos.
*/

class Modelo {
public:
    /**
     * Crea un modelo nuevo a partir de los datos
     * que contiene el archivo que require el main
     * @param nombreArchivo El nombre del archivo donde se encuentra el modelo que se va a utilizar
     */
    Modelo( char nombreArchivo[] );

    virtual ~Modelo();

    /**
     * @param nombreFicha identificador de la ficha
     * @return true si la ficha se encuentra en el tablero
     */
    bool estaFichaEnTablero( string nombreFicha );
    /**
     * @param coox Coordenada en X de la ficha
     * @param cooy Coordenada en Y de la ficha
     * @return true si la ficha se encuentra en el tablero
     */
    bool estaFichaEnTablero( int coox, int cooy );
    /**
     * @param nombreFicha identificador de la ficha
     * @return Tipo de ficha
     */
    int getTipo( string nombreFicha );
    /**
     * @param nombreFicha identificador de la ficha
     * @return Color de ficha
     */
    bool getColor( string nombreFicha );
    /**
     * @param nombreFicha identificador de la ficha
     * @return Posicion en X de la ficha
     */
    int getPosX( string nombreFicha );
    /**
     * @param nombreFicha identificador de la ficha
     * @return Posicion en Y de la ficha
     */
    int getPosY( string nombreFicha );
    /**
     * @param coox Coordenada X de la ficha
     * @param cooy Coordenada Y de la ficha
     * @return Identificador de la ficha
     */
    string getFicha( int coox, int cooy );
    /**
     * @return Lista con los identificadores de todas las fichas del tablero
     */
    list<string> getFichas();
    /**
     * @return Lista con todos los numeros que se pueden usar
     */
    list<string> getNumeros();
private:
    map < string, Ficha > fichasEnTablero;
    string int2string(int);
};

#endif // MODELO_H
