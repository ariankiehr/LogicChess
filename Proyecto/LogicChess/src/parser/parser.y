/*  LogicChess: Herramienta didactica para el aprendizaje práctico de la Logica de Primer Orden
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
%{
    #include "scanner.h"
    #include "../formula/And.hpp"
    #include "../formula/Not.hpp"
    #include "../formula/Or.hpp"
    #include "../formula/Implica.hpp"
    #include "../formula/PredicadoEsTorre.hpp"
    #include "../formula/PredicadoEsPeon.hpp"
    #include "../formula/PredicadoEsAlfil.hpp"
    #include "../formula/PredicadoEsCaballo.hpp"
    #include "../formula/PredicadoEsRey.hpp"
    #include "../formula/PredicadoEsReina.hpp"
    #include "../formula/PredicadoEsBlanca.hpp"
    #include "../formula/PredicadoEsNegra.hpp"
    #include "../formula/PredicadoMismaFila.hpp"
    #include "../formula/PredicadoMismaColumna.hpp"
    #include "../formula/PredicadoMismaDiagonal.hpp"
    #include "../formula/PredicadoEstaEnL.hpp"
    #include "../formula/PredicadoEstaVacio.hpp"
    #include "../formula/PredicadoCaminoLibre.hpp"
    #include "../formula/PredicadoDistancia.hpp"
    #include "../formula/termino/Termino.hpp"
    #include "../formula/termino/Constante.hpp"
    #include "../formula/termino/Variable.hpp"
    #include "../formula/termino/FuncionGetFicha.hpp"
    #include "../formula/Existe.hpp"
    #include "../formula/ParaTodo.hpp"
    #include <map>

	//cualquier error deriva aca
    int yyerror( const char* msg ) {
        //printf("%s\n",msg);
        return 1;
    }

    //formulaRetorno en la estructura donde se carga la formula para que se pueda calcular
    Formula* formulaRetorno;

	//metodo llamado desde la clase parser
    Formula* getFormula() {
        return formulaRetorno;
    }

    list<Termino*> args,  //args es una lista que va a guardar los parametros de los predicados
                   argsfun; // argsfun va a guardar los parametros de la funcion

    //variable definidas es un map que se usa para llevar cuenta de las variables que estan en la formula
    //sirve para saber si hay variables sin cuantificar o cuantificadores que cuantifican variables que no estan
    map<string , int> variablesDefinidas; //0 no existe, 1 ficha, 2 numerica

	//Todas las cadenas que hay que comparar
    string
        cuantificadorExistenial = "#",
        cuantificadorExistenial1 = "existe",
        cuantificadorExistenial2 = "ex",
        cuantificadorUniversal = "@",
        cuantificadorUniversal1 = "paratodo",
        cuantificadorUniversal2 = "pt",
        funcionGetFicha = "getficha",
        predicadoEsPeon = "espeon",
        predicadoEsAlfil = "esalfil",
        predicadoEsTorre = "estorre",
        predicadoEsCaballo = "escaballo",
        predicadoEsReina = "esreina",
        predicadoEsRey = "esrey",
        predicadoEsBlanca = "esblanca",
        predicadoEsNegra = "esnegra",
        predicadoMismaFila = "mismafila",
        predicadoMismaColumna = "mismacolumna",
        predicadoMismaDiagonal = "mismadiagonal",
        predicadoEstaEnL = "estaenl",
        predicadoCaminoLibre = "caminolibre",
        predicadoEstaVacia = "estavacia";
%}
// Para manejar C++ y la Formula
%require "2.5"
%code requires {
    #include "../formula/Formula.hpp"
}
/**
 * Union que representa el tipo de datos con el que se trabaja
*/
%union {
    string *term;
    Formula *form;
}

/**
 * tokens sin un tipo de dato asosiado
 */
%token OPERADORAND OPERADOROR OPERADORIM OPERADORUNARIO PARENTESISI PARENTESISD
%token PREDICADODISTANCIA COMA PREDICADOESVACIA
/**
 * tokens que representan terminos
 */
%token <term> FICHA PREDICADOUNARIO PREDICADOBINARIO NUMERO VARIABLE CUANTIFICADOR FUNCION

/**
 * Pasos que construyen una formula
 */
%type <form> sentencia
%type <form> sentenciaAtomica
%type <form> sentenciaAnd
%type <form> sentenciaOr
%type <form> sentenciaUnica

%start input

%%

input: sentencia {
    formulaRetorno = $1; //se guarda la formula generada
    //si el finalizar el AST quedaron variables libres
    if(!variablesDefinidas.empty()) {
        return yyerror("syntax error. Una variable no tiene cuantificador?");
    }
	//se liberan todas las estructuras
    args.clear();
    argsfun.clear();
    variablesDefinidas.clear();
}

sentencia: sentenciaOr
        | sentencia OPERADORIM sentenciaOr { $$ = new Implica($1 , $3); }
;

sentenciaOr: sentenciaAnd
        | sentenciaOr OPERADOROR sentenciaAnd { $$ = new Or($1 , $3); }
;

sentenciaAnd: sentenciaAnd OPERADORAND sentenciaUnica { $$ = new And($1 , $3); }
        | sentenciaUnica
;

sentenciaUnica:  sentenciaAtomica
        | OPERADORUNARIO sentenciaUnica { $$ = new Not($2); }
        | PARENTESISI sentencia PARENTESISD {
                $$ = $2;
            }
        | CUANTIFICADOR VARIABLE sentenciaUnica {
                int numerica = 0;
                map<string, int>::iterator it = variablesDefinidas.find(*$2);
                if(it != variablesDefinidas.end()){
                    numerica = it->second;
                    variablesDefinidas.erase(it);
                }
                else
                    return yyerror("syntax error. Un cuantificador cuantifica una variable que no existe?");

                if( *$1 == cuantificadorExistenial || *$1 == cuantificadorExistenial1 ||
                        *$1 == cuantificadorExistenial2)
                    $$ = new Existe(Variable(*$2), $3, (numerica==1)?false:true );
                else
                    $$ = new ParaTodo(Variable(*$2), $3, (numerica==1)?false:true );
            }
;

sentenciaAtomica: PREDICADOUNARIO PARENTESISI terminoFicha PARENTESISD {
                                 if( *$1 == predicadoEsTorre )
                                    $$ = new PredicadoEsTorre(args);
                                 else if ( *$1 == predicadoEsPeon )
                                    $$ = new PredicadoEsPeon(args);
                                 else if ( *$1 == predicadoEsAlfil )
                                    $$ = new PredicadoEsAlfil(args);
                                 else if ( *$1 == predicadoEsRey )
                                    $$ = new PredicadoEsRey(args);
                                 else if ( *$1 == predicadoEsReina )
                                    $$ = new PredicadoEsReina(args);
                                 else if ( *$1 == predicadoEsCaballo )
                                    $$ = new PredicadoEsCaballo(args);
                                 else if ( *$1 == predicadoEsBlanca )
                                    $$ = new PredicadoEsBlanca(args);
                                 else
                                    $$ = new PredicadoEsNegra(args);
                                 args.clear(); //se borran los parametros que ya fueron usados
                                }
    | PREDICADOBINARIO PARENTESISI terminoFicha COMA terminoFicha PARENTESISD {
                                if( *$1 == predicadoMismaFila )
                                    $$ = new PredicadoMismaFila(args);
                                else if ( *$1 == predicadoMismaColumna )
                                    $$ = new PredicadoMismaColumna(args);
                                else if ( *$1 == predicadoMismaDiagonal )
                                    $$ = new PredicadoMismaDiagonal(args);
                                else if ( *$1 == predicadoEstaEnL )
                                    $$ = new PredicadoEstaEnL(args);
                                else
                                    $$ = new PredicadoCaminoLibre(args);
                                args.clear(); //se borran los parametros que ya fueron usados
                            }
    | PREDICADOESVACIA PARENTESISI terminoNumero COMA terminoNumero PARENTESISD {
        $$ = new PredicadoEstaVacio(args);
        args.clear(); //se borran los parametros que ya fueron usados
    }
    | PREDICADODISTANCIA PARENTESISI terminoFicha COMA terminoFicha COMA terminoNumero PARENTESISD {
        $$ = new PredicadoDistancia(args);
        args.clear(); //se borran los parametros que ya fueron usados
    }
;

terminoNumero:  NUMERO { args.push_back(new Constante(*$1)); delete($1); }
    | VARIABLE {
        if( variablesDefinidas[*$1] == 0 || variablesDefinidas[*$1] == 2)
            variablesDefinidas[*$1] = 2; //nueva variable definida que debera ser eliminada por un cuantificador
        else
            return yyerror("syntax error. Una variable intenta evaluarse en dos tipos distintos?");
        args.push_back(new Variable(*$1)); //*$1 contiene el String que se usa como identificador
        delete($1); //se libera memoria del puntero a string
    }
;


terminoFicha: FICHA { args.push_back(new Constante(*$1)); delete($1); }
    | VARIABLE {
        if(variablesDefinidas[*$1]== 0 || variablesDefinidas[*$1] == 1 )
            variablesDefinidas[*$1] = 1; //nueva variable definida que debera ser eliminada por un cuantificador
        else
            return yyerror("syntax error. Una variable intenta evaluarse en dos tipos distintos?");
        args.push_back(new Variable(*$1)); //*$1 contiene el String que se usa como identificador
        delete($1); //se libera memoria del puntero a string
    }
    | FUNCION PARENTESISI terminoNumero COMA terminoNumero PARENTESISD {
        //se pasan los ultimos dos elementos de args a argsfun
        argsfun.splice(argsfun.begin(), args, ----args.end(), args.end());
        if( *$1 == funcionGetFicha )
            args.push_back(new FuncionGetFicha(argsfun));
        argsfun.clear(); // se eliminan los parametros que fueron usados en la funcion
    }
;


%%

