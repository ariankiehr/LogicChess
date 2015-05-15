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
#ifndef EXISTE_H
#define EXISTE_H

#include "Cuantificador.hpp"

/**
 * Clase que describe el comportamiento del cuantificador existencial
 */

class Existe : public Cuantificador {
public:
    /**
     * @param var Variable que es cuantificada
     * @param form Formula que se encuentra despues del cuantificador
     * @param esNumerica Indica dominio de la variable dentro del modelo
     */
    Existe(Variable var, Formula* form, bool esNumerica);
    virtual ~Existe();
    /**
     * @param mod Modelo en el que se va a evaluar la formula
     * @return true Si al cuantificar existencialmente esa variable, la formula es valida
     */
    bool getValor(Modelo mod);
    /**
     * Muestra un cuantificador existencial seguido de una variable y luego la formula
     */
    void mostrar();
};

#endif // EXISTE_H
