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
#include "Predicado.hpp"

Predicado::Predicado(list<Termino*> args) : Formula() {
    argumentos = args;
}


Predicado::~Predicado() {}

void Predicado::mostrarArgs() {
    list<Termino*>::iterator it = argumentos.begin();
    while(it!=argumentos.end()) {
        (*it)->mostrar();
        cout<<" ";
        it++;
    }
}

void Predicado::setVariable(string var, string str) {
    list<Termino*>::iterator it = argumentos.begin();
    while(it!=argumentos.end()) {
        (*it)->setVariable(var,str);
        it++;
    }
}
