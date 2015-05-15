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
#ifndef FICHA_H
#define FICHA_H
#include<string>

#define PEON 1
#define TORRE 2
#define CABALLO 3
#define ALFIL 4
#define REINA 5
#define REY 6
#define BLANCO 0
#define NEGRO 1

using namespace std;

/**
 * Clase que almacena todas los datos necesarios para representar
 * una ficha en el tablero. Provee una interfaz para poder
 * acceder a acada uno de ellos.
*/

class Ficha  {
public:
    /**
      * Crea una nueva ficha
      * @param tipo Tipo de ficha (1.Peon; 2.Torre; 3.Caballo; 4.Alfil; 5.Reina; 6.Rey)
      * @param color Color de ficha (0.Blanco; 1.Negro)
      * @param nombre Identificador de la ficha
      * @param posx Coordenada en X
      * @param posy Coordenada en Y
      */
    Ficha(int tipo, bool color, string nombre, int posx, int posy);

    virtual ~Ficha();

    /**
     * @return Tipo de ficha
    */
    int getTipo();

    /**
     * @return Tipo de color
    */
    bool getColor();

    /**
     * @return Tipo de identificador
    */
    string getNombre();

    /**
     * @return Tipo de posicion X
    */
    int getPosX();

    /**
     * @return Tipo de posicion Y
    */
    int getPosY();

    /**
     * Sobrecarga del operador ==. Dos fichas son iguales si todos
     * sus datos coinciden
     * @param ficha Tipo de dato Ficha
     * @return true si son iguales
    */

    bool operator==(Ficha ficha);

private:
    int tipo;
    bool color;
    string nombre;
    int posx, posy;
};


#endif
