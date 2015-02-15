/*
 ============================================================================
 Name        : Laba-1.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define A 2.0
#define B 8.0
#define E 0.0001

void method_right_rectangle();
void method_left_rectangle();
void method_middle_rectangle();
void method_trapeze();
void method_simpson();
double f(double);

int main(void) {

	method_right_rectangle();
	method_left_rectangle();
	method_middle_rectangle();
	method_trapeze();
	method_simpson();

	return EXIT_SUCCESS;

}

void method_right_rectangle() {

	FILE * file;
	int n = 10; // начальное количество разбиений
	double h = (B - A) / n; // шаг
	double S1 = 0;
	double S2 = 0;
	int i = 0;
	file = fopen("temp.txt", "a");
	fprintf(file, "Метод правых прямоугольников:\n%-10c%-10c%-15cS1 - S2\n", 'n', 'h', 'S');
	do {
		S1 = 0;
		for (i = 0; i <= n; i++)
			S1 += h * f(A + (i + 1) * h);
		fprintf(file, "n = %-10d%-10lf%-10lf", n, h, S1);
		n *= 2;
		h = (B - A) / n;
		S2 = 0;
		for (i = 0; i <= n; i++)
			S2 += h * f(A + (i + 1) * h);
		fprintf(file, "%-10lf\n", fabs(S1 - S2));
	} while (fabs(S1 - S2) >= E);
	fprintf(file, "n = %-10d%-10lf%-10lf\n\n", n, h, S2);
	fclose(file);

}

void method_left_rectangle() {

	FILE * file;
	int n = 10;
	double h = (B - A) / n;
	double S1 = 0;
	double S2 = 0;
	int i = 0;
	file = fopen("temp.txt", "a");
	fprintf(file, "Метод левых прямоугольников:\n%-10c%-10c%-15cS1 - S2\n", 'n', 'h', 'S');
	do {
		S1 = 0;
		for (i = 0; i < n; i++)
			S1 += h * f(A + i * h);
		fprintf(file, "n = %-10d%-10lf%-10lf", n, h, S1);
		n *= 2;
		h = (B - A) / n;
		S2 = 0;
		for (i = 0; i < n; i++)
			S2 += h * f(A + i * h);
		fprintf(file, "%-10lf\n", fabs(S1 - S2));
	} while (fabs(S1 - S2) >= E);
	fprintf(file, "n = %-10d%-10lf%-10lf\n\n", n, h, S2);
	fclose(file);

}

void method_middle_rectangle() {

	FILE * file;
	int n = 10;
	double h = (B - A) / n;
	double S1 = 0;
	double S2 = 0;
	int i = 0;
	file = fopen("temp.txt", "a");
	fprintf(file, "Метод средних прямоугольников:\n%-10c%-10c%-15cS1 - S2\n", 'n', 'h', 'S');
	do {
		S1 = 0;
		for (i = 0; i < n; i++)
			S1 += h * f(A + (((2 * i + 1) * h) / 2));
		fprintf(file, "n = %-10d%-10lf%-10lf", n, h, S1);
		n *= 2;
		h = (B - A) / n;
		S2 = 0;
		for (i = 0; i < n; i++)
			S2 += h * f(A + (((2 * i + 1) * h) / 2));
		fprintf(file, "%-10lf\n", fabs(S1 - S2));
	} while (fabs(S1 - S2) >= E);
	fprintf(file, "n = %-10d%-10lf%-10lf\n\n", n, h, S2);
	fclose(file);

}

void method_trapeze() {

	FILE * file;
	int n = 10;
	double h = (B - A) / n;
	double S1 = 0;
	double S2 = 0;
	int i = 0;
	file = fopen("temp.txt", "a");
	fprintf(file, "Метод трапеций:\n%-10c%-10c%-15cS1 - S2\n", 'n', 'h', 'S');
	do {
		S1 = 0;
		for (i = 0; i < n; i++)
			S1 += (f(A + i * h) + f(A + (i + 1) * h)) / 2 * h;
		fprintf(file, "n = %-10d%-10lf%-10lf", n, h, S1);
		n *= 2;
		h = (B - A) / n;
		S2 = 0;
		for (i = 0; i < n; i++)
			S2 += (f(A + i * h) + f(A + (i + 1) * h)) / 2 * h;
		fprintf(file, "%-10lf\n", fabs(S1 - S2));
	} while (fabs(S1 - S2) >= E);
	fprintf(file, "n = %-10d%-10lf%-10lf\n\n", n, h, S2);
	fclose(file);

}

void method_simpson() {

	FILE * file;
	int n = 10;
	double h = (B - A) / (2 * n);
	double S1 = 0;
	double S2 = 0;
	int i = 0;
	file = fopen("temp.txt", "a");
	fprintf(file, "Метод симпсона:\n%-10c%-10c%-15cS1 - S2\n", 'n', 'h', 'S');
	do {
		S1 = 0;
		for (i = 0; i < n; i++)
			S1 += h / 3 * (f(A + i * h) + 4 * f(A + (i + 1) * h) + f(A + (i + 2) * h));
		fprintf(file, "n = %-10d%-10lf%-10lf", n, h, S1);
		n *= 2;
		h = (B - A) / (2 * n);
		S2 = 0;
		for (i = 0; i < n; i++)
			S2 += h / 3 * (f(A + i * h) + 4 * f(A + (i + 1) * h) + f(A + (i + 2) * h));
		fprintf(file, "%-10lf\n", fabs(S1 - S2));
	} while (fabs(S1 - S2) >= E);
	fprintf(file, "n = %-10d%-10lf%-10lf\n\n", n, h, S2);
	fclose(file);

}

double f(double x) {

	return 1 / sqrt(3 * x * x + 2);

}
