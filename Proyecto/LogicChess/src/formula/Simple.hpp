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
#ifndef SIMPLE_H
#define SIMPLE_H

#include "Formula.hpp"

/**
 * Clase abstracta que engloba la operacion unaria de negacion
 * y los cuantificadores (que tienen en comun que afectan a una
 * unica formula)
 */

class Simple : public Formula {
public:
    /**
     * @param form Formula a la derecha de la operacion simple
     */
    Simple(Formula* form);
    virtual ~Simple();
    /**
     * @param mod Modelo en el que se va a evaluar la formula
     * @return true Si la operacion con esa formula es valida
     */
    virtual bool getValor(Modelo mod) = 0;
    /**
     * Muestra una formula por pantalla despues de la operacion simple
     */
    virtual void mostrar() = 0;
    /**
     * Asigna a una variable en la formula un valor constante dado
     * @param idVariable Identificador de la variable
     * @param idConstante Identificador de la constante
     */
    void setVariable(string idVariable, string idConstante);
protected:
    /** Formula a continuacion la la operacion simple */
    Formula *form;
};

#endif
