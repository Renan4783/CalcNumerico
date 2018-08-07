/*
 * MIL.c
 *
 *  Created on: 2 de nov de 2015
 *      Author: Renan
 */

float funcao(float x);
float qfuncao(float x);
float dfuncao(float x);

void MIL(float x, float prec, int k) {
	float fx;
	fx = qfuncao(x);
	if (((fx < prec) || ((fx - x) < prec)) && (k < 100)) {
		printf("Valor (MIL): %f\n", fx);
	} else {
		MIL(fx, prec, k + 1);
	}
}

void bissecao(float a, float b, float prec, int k) {
	float meio, fmeio;
	meio = (a + b) / 2;
	fmeio = funcao(meio);
	if (((b - a) < prec) && (k < 100)) {
		printf("Valor (Bisseçao): %f\n", meio);
	} else {
		if ((fmeio) > 0) {
			bissecao(a, meio, prec, k + 1);
		} else {
			bissecao(meio, b, prec, k + 1);
		}
	}
}

void NewtonRhapson(float x, float prec, int k) {
	float fx, dfx, qx;
	fx = funcao(x);
	if ((abs(fx) > prec)) {
		dfx = dfuncao(x);
		qx = (x * dfx - fx) / dfx;
		fx = funcao(qx);
		while ((abs(fx) > prec) && (abs((fx - x)) > prec) && (k < 100)) {
			fx = funcao(x);
			dfx = dfuncao(x);
			qx = x - (fx / dfx);
			fx = funcao(qx);
		}
		printf("Valor (Newton-Rhapson): %f\n", qx);
	} else {
		printf("Valor (Newton-Rhapson): %f\n", x);
	}
}

void Secante(float x0, float x1, float prec, int k) {
	float x2;
	if (funcao(x0) < prec) {
		printf("Valor (Secante): %f\n", x0);
	} else {
		if ((funcao(x1) < prec) || (x1 - x0) < prec) {
			printf("Valor (Secante): %f\n", x1);
		} else {
			x2 = x1 - (((funcao(x0)) * (x1 - x0)) / funcao(x1) - funcao(x0));
			if (((funcao(x2) < prec) || (x2 - x1) < prec) || k < 100) {
				printf("Valor (Secante): %f\n", x2);
			} else {
				Secante(x1, x2, prec, k + 1);
			}
		}
	}
}

void RegulaFalsi(float x, float y, float prec1, float prec2, int k) {
	float m, aux;
	if ((y - x) < prec1) {
		printf("Valor (RegulaFalsi): %f", x);
	} else if ((funcao(x) < prec2) || (funcao(y) < prec2)) {
		printf("Valor (RegulaFalsi): %f", x);
	} else {
		m = funcao(x);
		aux = (x * (funcao(x)) - y * (funcao(x))) / (funcao(y) - funcao(x));
		if ((funcao(aux) < prec2) || (k < 100)) {
			printf("Valor (RegulaFalsi): %f", aux);
		} else {
			if ((aux * (funcao(x))) > 0) {
				x = aux;
				if ((m*(y - x)) < prec1) {
					printf("Valor (RegulaFalsi): %f", x);
				} else {
					RegulaFalsi(x, y, prec1, prec2, k + 1);
				}
			} else {
				y = aux;
				if ((m*(y - x)) < prec1) {
					printf("Valor (RegulaFalsi): %f", x);
				} else {
					RegulaFalsi(x, y, prec1, prec2, k + 1);
				}
			}
		}
	}

}
