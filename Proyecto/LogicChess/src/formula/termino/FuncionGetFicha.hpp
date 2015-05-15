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
#ifndef FUNCIONGETFICHA_H
#define FUNCIONGETFICHA_H

#include "Funcion.hpp"


/**
 * Clase que describe el comportamiento de la funcion getFicha
 */

class FuncionGetFicha : public Funcion {
public:
    /**
     * @param args Lista de terminos(numericos) que son parametros de la funcion
     */
    FuncionGetFicha(list<Termino*> args);
    virtual ~FuncionGetFicha();
    /**
     * @param mod Modelo en el que se va a obtener el termino
     * @return El identificador de la ficha que se encuentra en esa posicion
     */
    string getValor(Modelo mod);
    /**
     * Muestra getFicha pantalla y sus argumentos
     */
    void mostrar();
};

#endif // FUNCIONGETFICHA_H
