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
#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "TerminoSimple.hpp"

/**
 * Clase que describe el comportamiento de una constante
 */

class Constante : public TerminoSimple {
public:
    /**
     * @param ID Identificador de la ficha
     */
    Constante(string ID);
    virtual ~Constante();
    /**
     * @param mod Modelo en el que se va a obtener el termino
     * @return El identificador de la ficha
     */
    string getValor(Modelo mod);
     /**
     * No asigna ningun valor porque no es una variable
     * @param idVariable Identificador de la variable
     * @param idConstante Identificador de la constante
     */
    void setVariable(string idVariable, string idConstante);
};

#endif // CONSTANTE_H
