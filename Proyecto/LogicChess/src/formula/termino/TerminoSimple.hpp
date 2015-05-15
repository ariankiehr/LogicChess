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
#ifndef TERMINOSIMPLE_H
#define TERMINOSIMPLE_H

#include "Termino.hpp"

/**
 * Clase abstracta que engloba las variables y constantes
 */

class TerminoSimple : public Termino {
public:
    /**
     * @param ID Identificador del termino simple
     */
    TerminoSimple(string ID);
    virtual ~TerminoSimple();
    /**
     * @param mod Modelo en el que se va a obtener el termino
     * @return El identificador de la ficha a la que hace referencia el termino simple
     */
    virtual string getValor(Modelo mod) = 0;
    /**
     * Muestra por pantalla el ID del termino simple
     */
    void mostrar();
    /**
     * Asigna a la variable con ID igual al primer parametro, el valor constante del segundo paramatro
     * @param idVariable Identificador de la variable
     * @param idConstante Identificador de la constante
     */
    virtual void setVariable(string idVariable, string idConstante) = 0;
    /**
     * @return El identificador del termino simple
     */
    string getID();
protected:
    /** Identificador del termino simple */
    string ID;
    /** Constructor por defecto */
    TerminoSimple();
};

#endif // TERMINOSIMPLE_H
