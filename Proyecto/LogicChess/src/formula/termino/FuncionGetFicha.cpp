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
#include "FuncionGetFicha.hpp"

FuncionGetFicha::FuncionGetFicha(list<Termino*> args) : Funcion(args)  {}

FuncionGetFicha::~FuncionGetFicha() {}

string FuncionGetFicha::getValor(Modelo mod) {
    Termino *t1 = *argumentos.begin();
    Termino *t2 = *++argumentos.begin();
    return mod.getFicha(atoi(t1->getValor(mod).c_str()), atoi(t2->getValor(mod).c_str()));
}

void FuncionGetFicha::mostrar() {
    cout << "getFicha( ";
    mostrarArgs();
    cout<<")";
}
