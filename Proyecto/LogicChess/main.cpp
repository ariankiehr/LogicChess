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


#include "src/formula/Formula.hpp"
#include "src/parser/ClaseParser.hpp"
#include "src/modelo/Modelo.hpp"


#define ARGC 3
#define ERR -1


int main(int argc, char* argv[]) {

    if( argc != ARGC )
        exit( EXIT_FAILURE );

    Formula *form;
    Modelo mod( argv[1] );
    Parser parser( argv[2] );

    if( parser.bienDefinida() ) {
        form = parser.obtenerFormula();
        cout << form->getValor(mod) << endl;
        form->mostrar();
    }
    else {
        cout << ERR << endl;
    }

    exit( EXIT_SUCCESS );
}
