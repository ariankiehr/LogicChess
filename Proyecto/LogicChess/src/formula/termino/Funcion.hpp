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
#ifndef FUNCION_H
#define FUNCION_H

#include "Termino.hpp"

/**
 * Clase abstracta que engloba el comportamiento de las funciones
 */

class Funcion : public Termino
{
public:
    /**
     * @param args Lista de terminos que son parametros de la funcion
     */
    Funcion(list<Termino*> args);
    virtual ~Funcion();
    /**
     * @param mod Modelo en el que se va a obtener el termino
     * @return El identificador del termino que represente la funcion en el modelo
     */
    virtual string getValor(Modelo mod) = 0;
    /**
     * Muestra el nombre de la funcion por pantalla y sus argumentos
     */
    virtual void mostrar() = 0;
    /**
     * Reemplaza todas las ocurrencias de la variable con ID igual al primer paramatro
     * por el valor constante del segundo parametro dentro de la funcion
     * @param idVariable Identificador de la variable
     * @param idConstante Identificador de la constante
     */
    void setVariable(string idVariable, string idConstante);
protected:
    /** Estructura donde se almacenan los argumentos de la funcion*/
    list<Termino*> argumentos;
    /** Se encarga de mostrar los argumentos de las fucniones */
    void mostrarArgs();
};

#endif // FUNCION_H
