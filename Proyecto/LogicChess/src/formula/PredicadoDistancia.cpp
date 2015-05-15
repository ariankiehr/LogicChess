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
#include "PredicadoDistancia.hpp"

PredicadoDistancia::PredicadoDistancia(list<Termino*> args) : Predicado(args) {
}

PredicadoDistancia::~PredicadoDistancia() {}

bool PredicadoDistancia::getValor(Modelo mod) {
    Termino *ficha1 = argumentos.front(),
            *ficha2 = *++argumentos.begin(),
            *numero = *++++argumentos.begin();

    int col1 = mod.getPosX(ficha1->getValor(mod));
    int col2 = mod.getPosX(ficha2->getValor(mod));
    int fil1 = mod.getPosY(ficha1->getValor(mod));
    int fil2 = mod.getPosY(ficha2->getValor(mod));

    int x = abs(col1 - col2),
        y = abs(fil1 - fil2);

    if(!mod.estaFichaEnTablero(ficha1->getValor(mod)) || !mod.estaFichaEnTablero(ficha2->getValor(mod)))
        return false;

    if(col1 == col2)
        return( y == atoi(numero->getValor(mod).c_str()) );

    else if(fil1 == fil2)
        return( x == atoi(numero->getValor(mod).c_str()) );

    else if(x==y)
        return (x == atoi(numero->getValor(mod).c_str()));

    return false;
}


void PredicadoDistancia::mostrar() {
    cout << "distancia( ";
    mostrarArgs();
    cout<<")";
}
