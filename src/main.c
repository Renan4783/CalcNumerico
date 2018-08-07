/*
 * main.c
 *
 *  Created on: 2 de nov de 2015
 *      Author: Renan
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "MetodosZero.h"

int main (void){
	//bissecao(0, 2, 0.1, 0);
	//MIL(0.5, 0.1, 0);
	//NewtonRhapson(0.5, 0.1, 0);
	//Secante (0, 0.5, 0.1, 0);
	RegulaFalsi (0, 0.5, 0.1, 0.1, 0);
	return 0;
}

float funcao (float x){
	return (x*x)+x+1;
}

float qfuncao (float x){
	return sqrt(-(x+1));
}

float dfuncao (float x){
	return (2*x)+1;
}
