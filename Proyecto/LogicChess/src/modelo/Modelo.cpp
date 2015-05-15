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
#include "Modelo.hpp"

Modelo::Modelo(char nombreArchivo[]) {

    ifstream archivo( nombreArchivo, ifstream::in);
    string auxiliar;

    if( !archivo.is_open() )
        exit( EXIT_FAILURE );

    while ( !archivo.eof() ) {
        getline( archivo, auxiliar );

        if( auxiliar == EoF )
            break;

        int tipo = CHARTOINT( auxiliar[POSTIPO] );
        int color = CHARTOINT( auxiliar[POSCOLOR] );
        int x = CHARTOINT( auxiliar[POSX] );
        int y = CHARTOINT( auxiliar[POSY] );

        string nombre = auxiliar.substr( POSNOMBRE, auxiliar.length());
        string coor = auxiliar.substr(POSX, NUMCOORDENADAS);

        Ficha fic(tipo,(color)?true:false, nombre, x, y);

        fichasEnTablero.insert( pair<string, Ficha>(nombre, fic) );
        fichasEnTablero.insert( pair<string, Ficha>(coor, fic) );

    }

    archivo.close();
}

Modelo::~Modelo() {
        fichasEnTablero.clear();
}

bool Modelo::estaFichaEnTablero( string nombreFicha ) {
    map<string, Ficha>::iterator it = fichasEnTablero.find(nombreFicha);
    if(it != fichasEnTablero.end())
        return true;
    return false;
}

bool Modelo::estaFichaEnTablero( int coox, int cooy ) {

    string coo = int2string(coox) + int2string(cooy);

    map<string, Ficha>::iterator it = fichasEnTablero.find(coo);
    if(it != fichasEnTablero.end())
        return true;
    return false;
}


int Modelo::getTipo( string nombreFicha ) {
    map<string, Ficha>::iterator it = fichasEnTablero.find(nombreFicha);
    if(it != fichasEnTablero.end()) return it->second.getTipo();
    return ERR;

}

bool Modelo::getColor( string nombreFicha ){
    map<string, Ficha>::iterator it = fichasEnTablero.find(nombreFicha);
    if(it != fichasEnTablero.end())
        return it->second.getColor();
    return false;

}

string Modelo::getFicha(int coox, int cooy) {

    string coo = int2string(coox) + int2string(cooy);

    map<string, Ficha>::iterator it = fichasEnTablero.find(coo);
    if(it != fichasEnTablero.end()) return it->second.getNombre();
    return VACIO;
}


int Modelo::getPosX( string nombreFicha ){
    map<string, Ficha>::iterator it = fichasEnTablero.find(nombreFicha);
    if(it != fichasEnTablero.end())
        return it->second.getPosX();
    return ERR;

}


int Modelo::getPosY( string nombreFicha ){
    map<string, Ficha>::iterator it = fichasEnTablero.find(nombreFicha);
    if(it != fichasEnTablero.end()) return it->second.getPosY();
    return ERR;
}


list<string> Modelo::getFichas() {
    list<string> listaRetorno;
    map<string, Ficha>::iterator it;
    for (it = fichasEnTablero.begin(); it != fichasEnTablero.end(); ++it)
        listaRetorno.push_back(it->first);
    return listaRetorno;
}

list<string> Modelo::getNumeros() {
    list<string> listaRetorno;

    for( int i = MINNUMERO; i <= MAXNUMERO; i++ )
        listaRetorno.push_back( int2string(i) );

    return listaRetorno;
}

string Modelo::int2string(int i) {
    stringstream out;
    out << i;
    return out.str();
}

