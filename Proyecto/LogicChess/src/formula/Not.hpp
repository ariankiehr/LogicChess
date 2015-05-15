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
#ifndef NOT_H
#define NOT_H

#include "Simple.hpp"

/**
 * Clase que describe el comportamiento del operador de negacion logica
 */

class Not : public Simple {
public:
    /**
     * @param form Formula a la deracha del operador
     */
    Not(Formula* form);
    ~Not();
    /**
     * @param mod Modelo en el que se va a evaluar la formula
     * @return true la negacion logica de la formula es valida
     */
    bool getValor(Modelo mod);
    /**
     * Muestra un ! seguido de la formula
     */
    void mostrar();
};


#endif
