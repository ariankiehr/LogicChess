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
#ifndef PREDICADOMISMADIAGONAL_H
#define PREDICADOMISMADIAGONAL_H

#include "Predicado.hpp"

/**
 * Clase que describe el comportamiento de el predicado mismaDiagonal
 */

class PredicadoMismaDiagonal : public Predicado {
public:
    /**
     * @param args Lista de terminos que representa los argumentos del predicado
     */
    PredicadoMismaDiagonal(list<Termino*> args);
    virtual ~PredicadoMismaDiagonal();
        /**
     * @param mod Modelo en el que se va a evaluar el predicado
     * @return true Si las fichas estan en la misma diagonal
     */
    bool getValor(Modelo mod);
    /**
     * Muestra mismaDiagonal seguido de sus paramatros
     */
    void mostrar();
};

#endif // PREDICADOMISMADIAGONAL_H
