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
#include "PredicadoMismaFila.hpp"

PredicadoMismaFila::PredicadoMismaFila(list<Termino*> args) : Predicado(args) {
}

PredicadoMismaFila::~PredicadoMismaFila() {}


bool PredicadoMismaFila::getValor(Modelo mod) {
    Termino *ficha1 = argumentos.front(),
            *ficha2 = *++argumentos.begin();

    if(!mod.estaFichaEnTablero(ficha1->getValor(mod)) || !mod.estaFichaEnTablero(ficha2->getValor(mod)))
        return false;

    if(mod.getPosX( ficha1->getValor(mod) ) == mod.getPosX( ficha2->getValor(mod) ))
        return true;

    return false;
}

void PredicadoMismaFila::mostrar() {
    cout << "mismaFila( ";
    mostrarArgs();
    cout<<")";
}
