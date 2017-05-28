#include <iostream>

using namespace std;

int** AllocMemory(int);
void Matrix(int**, int);
void DisplayMatrix(int**, int);
int MaxElementInUpperTriangle(int**, int, int, int);
int MaxElementInDownTriangle(int**, int, int, int);
int CompareUpAndDown(int**, int, int, int);
void MatrixB(int** b, int** a, int n);
int TestingK(int n, int i, int j);
int TestingIJ(int**a, int n, int i, int j);

int main()
{
	int n;
	cout << "Enter the dimension of matrix: ";
	cin >> n;
	cout << endl;
	int** a = AllocMemory(n);
	int** b = AllocMemory(n);
	Matrix(a, n);
	cout << "Matrix A: " << endl;
	DisplayMatrix(a, n);
	cout << endl;
	MatrixB(b, a, n);
	cout << "Matrix B: " << endl;
	DisplayMatrix(b, n);
	system("pause");
	return 0;
}

int** AllocMemory(int n)
{
	int** a = new int*[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	return a;
}

void Matrix(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 10;
		}
	}
}

void DisplayMatrix(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(4);
			cout << a[i][j];
		}
		cout << endl;
	}
}

int TestingK(int n, int i, int j)
{
	int k = i + j;
	if (k >= n)
		k = n - k;
	else
		k = i + j;
	return k;
}

int MaxElementInUpperTriangle(int** a, int n, int i, int j)
{
	int k = TestingK(n, i, j);
	int max = 0;
	int h = k;
	{
		for (int l = 0; l <= h; l++)
		{
			for (int m = 0; m <= k; m++)
			{
				if (a[l][m] > max)
					max = a[l][m];
				else
					max = max;
			}
			k--;
		}
	}
	return max;
}

int MaxElementInDownTriangle(int** a, int n, int i, int j)
{
	int k = TestingK(n, i, j);
	int max = 0;
	int h = k;
	for (int l = n - 1; l >= n - j; l--)
	{
		if ((n - j) == 0) break;
		else
		{
			for (int m = n - 1; m >= n - l; m--)
			{
				if (a[l][m] > max)
					max = a[l][m];
				else
					max = max;
			}
			j++;
		}
	}
	return max;
}

int CompareUpAndDown(int** a, int n, int i, int j)
{
	int max;
	if (MaxElementInUpperTriangle(a, n, i, j) > MaxElementInDownTriangle(a, n, i, j))
		max = MaxElementInUpperTriangle(a, n, i, j);
	else
		max = MaxElementInDownTriangle(a, n, i, j);
	return max;
}

void MatrixB(int** b, int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (((i == 0) && (j == 0)) || ((i == n - 1) && (j == n - 1)))
				b[i][j] = a[i][j];
			else if (i + j == (n - 1))
				b[i][j] = a[i][j];
			else
				b[i][j] = TestingIJ(a, n, i, j);
		}
	}
}

int TestingIJ(int**a, int n, int i, int j)
{
	int max;
	if (i + j >= n)
	{
		i = n - i - 1;
		j = n - j - 1;
		max = CompareUpAndDown(a, n, i, j);
	}
	else
		max = CompareUpAndDown(a, n, i, j);
	return max;
}