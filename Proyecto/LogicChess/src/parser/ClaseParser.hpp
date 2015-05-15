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
#ifndef PARSER_H
#define PARSER_H

#include "../formula/Formula.hpp"
#include <fstream>
#include <algorithm>
#include <string.h>

#define MAXSIZE 280

/**
 * Clase para el manejo del parser y generacion de la Formula
 */

class Parser {
public:
    /**
     * Constructura del parser, guarda la cadena que se quiere analizar
     * @param nombreArchivo El nombre del archivo donde se encuentra la formula que se va a evaluar
     */
    Parser( char nombreArchivo[] );
    virtual ~Parser();
    /**
     * @return La formula que fue parseada por el metodo bienDefinida si fue
     * fbf en un TDA Formula
     * @see bienDefinida
     */
    Formula* obtenerFormula();
    /**
     * @return true si la formula es formula bien definida
     */
    bool bienDefinida();
private:
    /**
     * Cadena extraida del archivo por parametro
     */
    string cadena;
};

#endif // PARSER_H
