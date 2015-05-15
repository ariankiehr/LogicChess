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
#include "PredicadoCaminoLibre.hpp"

#define libre(a,b,c,d,e) for(int i=a; i<b-c; i++) {\
                            if(mod.estaFichaEnTablero( d , e )) { \
                                return false; \
                            } \
                         } \

PredicadoCaminoLibre::PredicadoCaminoLibre(list<Termino*> args) : Predicado(args) {
}

PredicadoCaminoLibre::~PredicadoCaminoLibre() {}

bool PredicadoCaminoLibre::getValor(Modelo mod) {

    Termino *ficha1 = argumentos.front(),
            *ficha2 = *++argumentos.begin();

    if(!mod.estaFichaEnTablero(ficha1->getValor(mod)) || !mod.estaFichaEnTablero(ficha2->getValor(mod)))
        return false;

    int col1 = mod.getPosX( ficha1->getValor(mod) ),
        col2 = mod.getPosX( ficha2->getValor(mod) ),
        fil1 = mod.getPosY( ficha1->getValor(mod) ),
        fil2 = mod.getPosY( ficha2->getValor(mod) ),
        x = abs( col1 - col2 ),
        y = abs( fil1 - fil2 );

    //misma columna
    if(col1 == col2) {

        //voy desde el menor hasta el mayor revisando
        int posin = min( fil1, fil2 ),
            posfi = max( fil1, fil2 );

        libre( posin+1, posfi, 0, col1, i);
        return true;
    }

    //misma fila
    else if(fil1 == fil2) {

        //voy desde el menor hasta el mayor revisando
        int posin = min(col1, col2),
            posfi = max(col1, col2);

        libre( posin+1, posfi, 0, i, fil1 );
        return true;
    }

    //misma diagonal
    else if( x == y ) {

        //ficha1 esta mas arriba que ficha2
        if(fil1 < fil2) {
            //ficha1 esta mas a la izquierda que ficha2
            if(col1 < col2)
                libre(1, col2, col1, col1+i, fil1+i)
            else
                libre(1, col1, col2, col1-i, fil1+i );

        }

        //ficha2 esta mas arriba que ficha1
        else {
            //ficha2 esta mas a la izquierda que ficha1
            if(col1 < col2)
                libre(1, col2, col1, col1+i, fil1-i )
            else
                libre(1, col1, col2, col1-i, fil1-i );
        }
        return true;
    }
    return false; //No esta en fila columna o diagonal
}

void PredicadoCaminoLibre::mostrar() {
    cout << "CaminoLibre( ";
    mostrarArgs();
    cout<<")";
}
