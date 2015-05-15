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
#include "PredicadoEstaEnL.hpp"

PredicadoEstaEnL::PredicadoEstaEnL(list<Termino*> args) : Predicado(args) {
}

PredicadoEstaEnL::~PredicadoEstaEnL() {}



bool PredicadoEstaEnL::getValor(Modelo mod) {
    Termino *ficha1 = argumentos.front(),
            *ficha2 = *++argumentos.begin();
    string f1 = ficha1->getValor(mod),
           f2 = ficha2->getValor(mod);
    return ((mod.getPosX(f1)-1 == mod.getPosX(f2) && mod.getPosY(f1)-2 == mod.getPosY(f2)) ||
            (mod.getPosX(f1)-2 == mod.getPosX(f2) && mod.getPosY(f1)-1 == mod.getPosY(f2)) ||
            (mod.getPosX(f1)+2 == mod.getPosX(f2) && mod.getPosY(f1)-1 == mod.getPosY(f2)) ||
            (mod.getPosX(f1)-1 == mod.getPosX(f2) && mod.getPosY(f1)+2 == mod.getPosY(f2)) ||
            (mod.getPosX(f1)+1 == mod.getPosX(f2) && mod.getPosY(f1)-2 == mod.getPosY(f2)) ||
            (mod.getPosX(f1)-2 == mod.getPosX(f2) && mod.getPosY(f1)+1 == mod.getPosY(f2)) ||
            (mod.getPosX(f1)+2 == mod.getPosX(f2) && mod.getPosY(f1)+1 == mod.getPosY(f2)) ||
            (mod.getPosX(f1)+1 == mod.getPosX(f2) && mod.getPosY(f1)+2 == mod.getPosY(f2)));
}

void PredicadoEstaEnL::mostrar() {
    cout << "estaEnL( ";
    mostrarArgs();
    cout<<")";
}
