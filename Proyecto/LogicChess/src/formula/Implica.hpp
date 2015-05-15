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
#ifndef IMPLICA_H
#define IMPLICA_H
#include "OperacionCompuesta.hpp"


/**
 * Clase que contine el comportamiento de la implicacion logica
 */


class Implica : public OperacionCompuesta {
public:
    /**
     * @param izq Formula que se encuentra a la izquierda del operador
     * @param der Formula que se encuentra a la derecha del operador
     */
    Implica(Formula* izq, Formula* der);
    ~Implica();
    /**
     * @param mod Modelo en el que se va a evaluar la formula
     * @return true Si la implicacion logica entre las dos formulas es valida
     */
    bool getValor(Modelo mod);
    /**
     * Muestra una formula por pantalla el operador > en medio de las dos formulas
     */
    void mostrar();
};

#endif
