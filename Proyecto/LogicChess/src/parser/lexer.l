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
%option noyywrap

%{
    #include "parser.h"
    #include<iostream>
%}

NUMERO [0-7]
FICHA [c][a-z0-9]
VARIABLE [v][a-z0-9]
SEPARADOR ([ \t""])+

%%

{SEPARADOR} {}

{NUMERO} {
    yylval.term = new string(yytext);
    return NUMERO;
    }

{FICHA} {
    yylval.term = new string(yytext);
    return FICHA;
    }

{VARIABLE} {
    yylval.term = new string(yytext);
    return VARIABLE;
    }

"&"|"y"|"and" {
    return OPERADORAND;
    }

"|"|"o"|"or" {
    return OPERADOROR;
    }

">"|"implica"|"->" {
    return OPERADORIM;
    }

"!"|"no"|"not"|"¬" {
    return OPERADORUNARIO;
    }

"(" {
    return PARENTESISI;
    }

")" {
    return PARENTESISD;
    }

"," {
    return COMA;
    }

"#"|"@"|"existe"|"paratodo"|"ex"|"pt" {
    yylval.term = new string(yytext);
    return CUANTIFICADOR;
    }

"getficha" {
    yylval.term = new string(yytext);
    return FUNCION;
    }

"espeon"|"esalfil"|"estorre"|"escaballo"|"esreina"|"esrey"|"esblanca"|"esnegra" {
    yylval.term = new string(yytext);
    return PREDICADOUNARIO;
    }

"estavacia" {
    return PREDICADOESVACIA;
    }

"mismafila"|"mismacolumna"|"mismadiagonal"|"estaenl"|"caminolibre" {
    yylval.term = new string(yytext);
    return PREDICADOBINARIO;
    }

"distancia" {
    return PREDICADODISTANCIA;
    }

. {}

%%
