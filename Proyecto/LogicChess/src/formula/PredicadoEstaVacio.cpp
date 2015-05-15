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
#include "PredicadoEstaVacio.hpp"


PredicadoEstaVacio::PredicadoEstaVacio(list<Termino*> args) : Predicado(args) {
}

PredicadoEstaVacio::~PredicadoEstaVacio(){}


bool PredicadoEstaVacio::getValor(Modelo mod) {
    Termino *coox = argumentos.front(),
            *cooy = *++argumentos.begin();
    if(mod.estaFichaEnTablero( atoi(coox->getValor(mod).c_str()), atoi(cooy->getValor(mod).c_str()) )) {
        return false;
    }
    return true;
}

void PredicadoEstaVacio::mostrar() {
    cout << "estaVacia( ";
    mostrarArgs();
    cout<<")";
}
