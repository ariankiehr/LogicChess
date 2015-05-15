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
#ifndef TERMINO_H
#define TERMINO_H

#include<iostream>
#include "../../modelo/Modelo.hpp"
#include<stdlib.h>

using namespace std;

/**
 * Clase abstracta que engloba todos los paramentros que puede tener un predicado
 * @see Predicado
 */

class Termino {
public:
    Termino();
    virtual ~Termino();
    /**
     * @param mod Modelo en el que se va a obtener el termino
     * @return El identificador de la ficha a la que hace referencia el termino
     */
    virtual string getValor(Modelo mod) = 0;
    /**
     * Muestra el termino por pantalla
     */
    virtual void mostrar() = 0;
     /**
     * Asigna a la variable con ID igual al primer parametro, el valor constante del segundo paramatro
     * @param idVariable Identificador de la variable
     * @param idConstante Identificador de la constante
     */
    virtual void setVariable(string idVariable, string idConstante) = 0;
};

#endif // TERMINO_H
