#include <iostream>

using namespace std;

double** AllocMemory(int);
void MatrixA(double**, int, double);
void DisplayMatrix(double**, int);
double ElementMatrixA(int, int, double);
double Cosinus(double, double);
double Sinus(double, double);
bool IsDataValid(double, int);
double ElementMatrixB(int, int);
void MatrixB(double**, int);
void DifferenceAB(double**, double**, double**, int);
void FreeMemory(double**, int);
double MaxElement(double**, int);

int main()
{
	int n;
	double eps;
	while (true)
	{
		cout << "Enter size of matrix: ";
		cin >> n;
		cout << endl;
		cout << "Enter epsilon: ";
		cin >> eps;
		if (IsDataValid(eps, n)) break;
		else cout << "INVALID DATA!" << endl;
		system("pause");
		system("cls");
	}
	cout << endl;
	double** a = AllocMemory(n);
	double** b = AllocMemory(n);
	double** k = AllocMemory(n);
	MatrixA(a, n, eps);
	cout << "Matrix A: " << endl;
	DisplayMatrix(a, n);
	cout << endl;
	MatrixB(b, n);
	cout << "Matrix B: " << endl;
	DisplayMatrix(b, n);
	cout << endl;
	DifferenceAB(a, b, k, n);
	cout << "Difference matrix: " << endl;
	DisplayMatrix(k, n);
	cout << endl;
	cout << "Max element of difference matrix: " << MaxElement(k, n) << endl;
	FreeMemory(a, n);
	FreeMemory(b, n);
	FreeMemory(k, n);
	cout << endl;
	system("pause");
	return 0;
}


double** AllocMemory(int n)
{
	double** a = new double*[n];
	for (int i = 0; i < n; i++)
		a[i] = new double[n];
	return a;
}

void MatrixA(double** a, int n, double eps)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = ElementMatrixA(i, j, eps);
		}
	}
}

double ElementMatrixA(int i, int j, double eps)
{
	double pi = 3.1415926535;
	double el = 0;
	if (i == j)
		el = i + j;
	else
	{
		double k = 2 * i, l = 2 * j;
		while (k > pi) k -= 2 * pi;
		while (l > pi) l -= 2 * pi;
		while (k < -pi) k += 2 * pi;
		while (l < -pi) l += 2 * pi;
		el = (2 * Cosinus(2 * i, eps) - Sinus(2 * j, eps)) / ((i + 1)*(i + 1));
	}
	return el;
}

void FreeMemory(double** a, int n)
{
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
}

void DisplayMatrix(double** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(15);
			cout << a[i][j];
		}
		cout << endl;
	}
}

double Cosinus(double a, double eps)
{
	int m = 1;
	double sum = 0.0;
	double yNext = 1.0;
	while (fabs(yNext) >= eps)
	{
		sum += yNext;
		yNext *= (-1.0 * a * a) / ((2 * m - 1)*(2 * m));
		m += 1;
	}
	return sum;
}

double Sinus(double a, double eps)
{
	int m = 1;
	double sum = 0;
	double yNext = a;
	while (fabs(yNext) >= eps)
	{
		sum += yNext;
		yNext *= -1.0*a*a / ((2 * m)*(2 * m + 1));
		m++;
	}
	return sum;
}

bool IsDataValid(double eps, int n)
{
	if ((eps <= 0) || (eps >= 1)) return false;
	if (n <= 0) return false;
	return true;
}

void MatrixB(double** b, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = ElementMatrixB(i, j);
		}
	}
}

double ElementMatrixB(int i, int j)
{
	double el = 0;
	if (i == j)
		el = i + j;
	else
		el = (2 * cos(2 * i) - sin(2 * j)) / ((i + 1)*(i + 1));
	return el;
}

void DifferenceAB(double** a, double** b, double** k, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			k[i][j] = fabs(a[i][j] - b[i][j]);
		}
	}
}

double MaxElement(double** k, int n)
{
	double max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (k[i][j] >max)
			{
				max = k[i][j];
			}
		}
	}
	return max;
}