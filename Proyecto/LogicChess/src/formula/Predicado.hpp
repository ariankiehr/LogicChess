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
#ifndef PREDICADO_H
#define PREDICADO_H

#include "Formula.hpp"
#include "termino/Termino.hpp"
#include<list>
#include<cmath>
#include<sstream>
#include<stdlib.h>

/**
 * Clase que engloba el comportamiendo de todos los predicados
 */

class Predicado : public Formula {
public:
    /**
     * @param args Lista de terminos que representa los argumentos del predicado
     */
    Predicado(list<Termino*> args);
    virtual ~Predicado();
    /**
     * @param mod Modelo en el que se va a evaluar el predicado
     * @return true Si el predicado es valido en el modelo
     */
    virtual bool getValor(Modelo mod) = 0;
    /**
     * Muestra el predicado seguido de sus paramatros
     */
    virtual void mostrar() = 0;
    /**
     * Asigna a una variable en el predicado un valor constante dado
     * @param idVariable Identificador de la variable
     * @param idConstante Identificador de la constante
     */
    void setVariable(string idVariable, string idConstante);
protected:
    /** Lista donde se almacenan los paramatros de los predicados */
    list<Termino*> argumentos;
    /** Se encarga de mostrar los parametros de un predicado */
    void mostrarArgs();
};

#endif
