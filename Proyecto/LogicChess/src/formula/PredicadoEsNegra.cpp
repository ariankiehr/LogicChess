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
#include "PredicadoEsNegra.hpp"

PredicadoEsNegra::PredicadoEsNegra(list<Termino*> args) : Predicado(args) {
}

PredicadoEsNegra::~PredicadoEsNegra() {}


bool PredicadoEsNegra::getValor(Modelo mod) {
    Termino* ficha = argumentos.front();
    if(mod.estaFichaEnTablero(ficha->getValor(mod))) {
        if(mod.getColor(ficha->getValor(mod)) == NEGRO) {
            return true;
        }
    }
    return false;
}

void PredicadoEsNegra::mostrar() {
    cout << "esNegra( ";
    mostrarArgs();
    cout<<")";
}
