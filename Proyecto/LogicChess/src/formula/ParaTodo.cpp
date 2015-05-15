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
#include "ParaTodo.hpp"

ParaTodo::ParaTodo(Variable var, Formula* form, bool esNumerica) : Cuantificador(var, form, esNumerica) {}

ParaTodo::~ParaTodo(){}

bool ParaTodo::getValor(Modelo mod) {
    list<string> valores;
    if(esNumerica) {
        valores = mod.getNumeros();
    } else {
        valores = mod.getFichas();
        if(valores.empty()) return false;
    }
    list<string>::iterator it = valores.begin();
    while(it!=valores.end()) {
        form->setVariable(var.getID(),*it);
        if(!form->getValor(mod)){
            return false;
        }
        it++;
    }
    return true;
}

void ParaTodo::mostrar() {
    cout << "( ";
    cout << " @";
    var.mostrar();
    cout << " ";
    form->mostrar();
    cout << " )";
}
