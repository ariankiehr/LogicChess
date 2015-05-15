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
#include "ClaseParser.hpp"


extern int yyrestart(FILE* archivo);
extern int yyparse();
extern Formula* getFormula();

Parser::Parser( char nombreArchivo[] ) {
    ifstream archivo( nombreArchivo, ifstream::in );

    if( !archivo.is_open() )
         exit( EXIT_FAILURE );

    getline( archivo, cadena );
    archivo.close();

    //se pasa a minusculas para poder parsear
    transform( cadena.begin(), cadena.end(), cadena.begin(), ::tolower);

}


Parser::~Parser(){}

bool Parser::bienDefinida() {
    //no debe superar la longitud maxima que admite flex
    if( cadena.size() > MAXSIZE ) return 0;

    //se creaun archivo temporal donde guardar el string
    FILE * temp = fopen ("teamporal_file.tmp", "w+");
    //se almacena dicha cadena
    fwrite( cadena.c_str(), sizeof( char ), strlen( cadena.c_str() ), temp );
    //cerramos para abrir con distintos permisos (necesario para que no se rompa)
    fclose( temp );
    fopen ( "teamporal_file.tmp", "r" );
    //se llaman a los analizadores
    yyrestart( temp );
    int ret = yyparse();
    fclose( temp );
    remove( "teamporal_file.tmp" );
    //se retorna el estado de la sentencia
    return ( !ret );
}


Formula * Parser::obtenerFormula() {
    return getFormula();
}


