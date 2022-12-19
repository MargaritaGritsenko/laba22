#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

typedef struct P
{
	double x, y;
}Point;

typedef double (*Tfun)(double);

double Y(double);
double S(double);
double V(double);

void Out_rez(Tfun, double, double, double);
double calc_fun(Tfun);
void tab_fun();
void getPoints(Point* point, Tfun f, double a, double b, double h);
void printPoint(Point point);
void listPoints(Point* point, double a, double b, double h);
double dz(Tfun f, double a, double b, double h);

int main()
{
	setlocale(LC_ALL, "RUS");

	double n, k;
	int v = 10, v2 = 10, v3 = 10, v4=10;
	double y, h;
	Point figure[100];
	while (v != 0)
	{
		printf("Меню\n1-Вычислить значение\n2-Табуляция\n3-Массив точек\n4-дз\n0-Выход\n");
		scanf("%d", &v);

		switch (v)
		{
		case 1:
		{
				printf("Выберите функцию:\n1-Y(x)\n2-V(x)\n3-S(x)\n0-выход\n");
				scanf("%d", &v2);
				if (v2=1) printf("y=%lf\n", calc_fun(Y));
				else if (v2=2) printf("y=%lf\n", calc_fun(V));
				else if (v2=3) printf("y=%lf\n", calc_fun(S));
				break;
		}
		case 2:
		{
			tab_fun();
			break;
		}
		case 3:
		{
				printf("Выберите функцию\n1-Y(x)\n2-V(x)\n3-S(x)\n0-выход\n");
				scanf("%d", &v3);

				printf("Введите начальное значение\n");
				scanf("%lf", &n);

				printf("Введите конечное значение\n");
				scanf("%lf", &k);

				printf("Введите шаг\n");
				scanf("%lf", &h);
				if (v3 = 1)
				{
					getPoints(figure, Y, n, k, h);
					listPoints(figure, n, k, h);
				}
				if (v3 = 2)
				{
					getPoints(figure, V, n, k, h);
					listPoints(figure, n, k, h);
				}
				if (v3 = 3)
				{
					getPoints(figure, S, n, k, h);
					listPoints(figure, n, k, h);
				}
		}
		case 4:
		{
			printf("Выберите функцию\n1-Y(x)\n2-V(x)\n3-S(x)\n");
			scanf("%d", &v4);

			printf("Введите начальное значение\n");
			scanf("%lf", &n);

			printf("Введите конечное значение\n");
			scanf("%lf", &k);

			printf("Введите шаг\n");
			scanf("%lf", &h);

			if (v4=1) printf("%lf\n", dz(Y, n, k, h));
			else if (v4=2) printf("%lf\n", dz(V, n, k, h));
			else if (v4=3) printf("%lf\n", dz(S, n, k, h));
			break;
		}
		}
	}
}

double Y(double x)
{
	if (x > 0)return log(fabs(sqrt(pow(x, 3))));
	return -1;
}
double V(double x)
{

	if (x > 1) return sqrt(tanh((x * x - 1.f) / 57));
	else if (x >= 0 && x <= 1) return -2 * x;
	else if (x < 0) return exp(cos(x));
	return -1;
}
double S(double x) {
	return (x - 1) / (x + 1) + 1. / 3 * pow((x - 1) / (x + 1), 3) + 1. / 5 * pow((x - 1) / (x + 1), 5) + 1. / 7 * pow((x - 1) / (x + 1), 7);
}


void Out_rez(Tfun f, double a, double b, double h)
{
	for (double i = a; i <= b; i += h)
		printf("|x = %5.2lf| y = %8.4lf|\n", i, f(i));
}

double calc_fun(Tfun f)
{
	double x;

	printf("Введите значение\n");
	scanf("%lf", &x);

	printf("x=%lf ", x);
	return f(x);
}

void tab_fun()
{
	double a, b, h;

	printf("Введите начальное значение\n");
	scanf("%lf", &a); getchar();

	printf("Введите конечное значение\n");
	scanf("%lf", &b); getchar();

	printf("Введите шаг\n");
	scanf("%lf", &h); getchar();

	printf("\tV(x)\t\n");
	Out_rez(V, a, b, h);

	printf("\tS(x)\t\n");
	Out_rez(S, a, b, h);

	printf("\tY(x)\t\n");
	Out_rez(Y, a, b, h);
}

void getPoints(Point* point, Tfun f, double a, double b, double h) 
{
	int i;
	for (int z = a, i = 0; z<=b,i < (b-a)/h; z+=h, i++)
	{
		point[i].x = z;
		point[i].y = f(z);
	}
}
void printPoint(Point point)
{
	printf("(%lf,%lf)\n", point.x, point.y);
}
void listPoints(Point* point, double a, double b, double h)
{
	int i;
	for (i = 0; i < (b - a) / h; i++) {
		printPoint(point[i]);
	}
}

double dz(Tfun f, double a, double b, double h)
{
	double max = 0;
	for (double i = a; i < b; i += h)
	{
		if (f(i) > max)
			max = f(i);
	}
	return max;
}