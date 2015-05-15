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
#ifndef FORMULA_H
#define FORMULA_H
#include<iostream>
#include "../modelo/Modelo.hpp"

using namespace std;

/**
 * Clase abstracta que representa una formula en memoria
 * (TDA Formula) con la capacidad de obtener el valor de verdad
 * de la misma y poder mostrarla por pantalla
 */

class Formula {
public:
    Formula();
    virtual ~Formula();
    /**
     * @param mod Modelo en el que se va a evaluar la formula
     * @return true Si la formula es valida en el modelo
     */
    virtual bool getValor(Modelo mod) = 0;
    /**
     * Muestra una formula por pantalla
     */
    virtual void mostrar() = 0;
    /**
     * Asigna a una variable en la formula un valor constante dado
     * @param idVariable Identificador de la variable
     * @param idConstante Identificador de la constante
     */
    virtual void setVariable(string idVariable, string idConstante) = 0;
};

#endif

