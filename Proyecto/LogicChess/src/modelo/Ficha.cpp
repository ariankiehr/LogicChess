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
#include "Ficha.hpp"

Ficha::Ficha(int tipo, bool color, string nombre, int posx, int posy) {
    this->tipo = tipo;
    this->color = color;
    this->nombre = nombre;
    this->posx = posx;
    this->posy = posy;
}

Ficha::~Ficha() {}

int Ficha::getTipo() {
    return tipo;
}

bool Ficha::getColor() {
    return color;
}

string Ficha::getNombre() {
    return nombre;
}

int Ficha::getPosX(){
    return posx;
}

int Ficha::getPosY() {
    return posy;
}

bool Ficha::operator==(Ficha ficha) {
    return (this->tipo == ficha.tipo &&
            this->color == ficha.color &&
            this->nombre == ficha.nombre &&
            this->posx == ficha.posx &&
            this->posy == ficha.posy
            );
}
