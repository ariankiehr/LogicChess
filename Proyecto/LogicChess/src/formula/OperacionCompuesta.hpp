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
#ifndef OPERACION_H
#define OPERACION_H
#include "Formula.hpp"

/**
 * Clase Abstracta que engloba los operadores binarios
 */

class OperacionCompuesta : public Formula {
public:
    /**
     * @param izq Formula que se encuentra a la izquierda del operador
     * @param der Formula que se encuentra a la derecha del operador
     */
    OperacionCompuesta(Formula* izq, Formula* der);
    virtual ~OperacionCompuesta();
    /**
     * @param mod Modelo en el que se va a evaluar la formula
     * @return true Si la operacion entre las dos formulas es valida
     */
    virtual bool getValor(Modelo mod) = 0;
    /**
     * Muestra una formula por pantalla el operador en medio de las dos formulas
     */
    virtual void mostrar() = 0;
    /**
     * Asigna a una variable en las formulas un valor constante dado
     * @param idVariable Identificador de la variable
     * @param idConstante Identificador de la constante
     */
    void setVariable(string idVariable, string idConstante);
protected:
    /** Formula a la izquierda del operador */
    Formula *izq;
    /** Formula a la derecha del operador */
    Formula *der;
};
#endif
