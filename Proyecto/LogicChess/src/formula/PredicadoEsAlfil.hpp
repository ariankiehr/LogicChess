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
#ifndef PREDICADOESALFIL_H
#define PREDICADOESALFIL_H

#include "Predicado.hpp"

/**
 * Clase que describe el comportamiento del predicado esAlfil
 */

class PredicadoEsAlfil : public Predicado {
public:
    /**
     * @param args Lista de terminos que representa los argumentos del predicado
     */
    PredicadoEsAlfil(list<Termino*> args);
    virtual ~PredicadoEsAlfil();
    /**
     * @param mod Modelo en el que se va a evaluar la formula
     * @return True si es alfil la ficha especificada
     */
    bool getValor(Modelo mod);
    /**
     * Muestra esAlfil seguido de sus argumentos
     */
    void mostrar();
};


#endif // PREDICADOESALFIL_H
