#include <iostream>
#include <fstream>

using namespace std;

int* AllocArray(int);
void DisplayArray(int*, int);
void WriteInNewArray(int*, int*, int);
int QuantityNechIndChetnElement(int*, int);
void ArrayOfRemainingElement(int*, int*, int, int);
void ArrayAfterDivision(int*, int*, int, int);
void Swap(int &, int &);
void BubbleSort(int*, int, int);
void AddFile(char*, int*, int, char*);
void InFile(int*, int*, int, int, char*);
void OnConsole(int*, int*, int, int);

const int N = 7;
const int L = 256;

int main()
{
	int* a = AllocArray(N);
	int* b = AllocArray(N);
	int t, y = 0, p = QuantityNechIndChetnElement(a, N), l = N - p;
	char fileName[L] = "";
	while (y == 0)
	{
		cout << "If you want to save a file, enter 1.\n"
			"If you want to see it on the console, enter 0!\n";
		cin >> t;
		if (t == 1)
		{
			InFile(a, b, p, l, fileName);
		}
		else if (t == 0)
		{
			OnConsole(a, b, p, l);
		}
		cout << "If you want again, enter 0!\n"
			"If you don`t want, enter enother!\n";
		cin >> y;
	}
}

void AddFile(char* fileName, int* arr, int n, char* str)
{
	ofstream streamOut(fileName, ios::app);
	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	streamOut << "\n\n";
	streamOut << str;
	for (int i = 0; i < n; i++)
	{
		streamOut.width(5);
		streamOut << arr[i];
	}
	streamOut.close();
}

int* AllocArray(int N)
{
	int* a = new int[N];
	for (int* p = a; p < (a + N); p++)
	{
		*p = rand() % 100;
	}
	return a;
}

void DisplayArray(int* a, int n)
{
	for (int *i = a; i < a + n; i++)
		cout << *i << " ";
	cout << endl;
}

void WriteInNewArray(int* a, int* b, int N)
{
	int k = 0;
	for (int i = 0; i < N;)
		for (int j = 0; j < N; j++)
		{
			b[j] = a[i];
			i = i + 2;
		}
	for (int i = 0; i < N; i++)
	{
		if ((b[i] % 2) == 0)
		{
			b[k] = b[i];
			k++;
		}
	}
}

int QuantityNechIndChetnElement(int* a, int N)
{
	int p = 0;
	N = N - N / 3;
	for (int i = 0; i < N; i++)
	{
		if ((a[i] % 2) == 0)
			p++;
	}
	return p;
}

void ArrayOfRemainingElement(int* a, int* b, int N, int p)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < p; j++)
		{
			if (a[i] == b[j])
			{
				for (int k = i; k <= N; k++)
					a[k] = a[k + 1];
				N--;
				j--;
			}
		}
}

void ArrayAfterDivision(int* a, int* b, int l, int del)
{
	for (int i = 0; i < l; i++)
	{
		b[i] = a[i] % del;
	}
}

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int *a, int l, int del)
{
	for (int i = 0; i < l - 1; i++)
		for (int j = 0; j < l - i - 1; j++)
		{
			if ((a[j] % del) < (a[j + 1] % del))
				Swap(a[j], a[j + 1]);
		}
}

void InFile(int* a, int* b, int p, int l, char* fileName)
{
	cout << "Enter the name of source file, please: ";
	cin.ignore();
	cin.getline(fileName, L, '\n');
	while (true)
	{
		int del;
		cout << "Enter the divisor: ";
		cin >> del;
		if (del == 0)
		{
			cout << "You enter wrong number!" << endl;
			system("pause");
		}
		else if (del != 0)
		{
			system("cls");
			char* str = " The original array: ";
			AddFile(fileName, a, N, str);
			str = " Array of odd index and even elements: ";
			WriteInNewArray(a, b, N);
			AddFile(fileName, b, p, str);
			str = " Array of remaining elements: ";
			ArrayOfRemainingElement(a, b, N, p);
			AddFile(fileName, a, l, str);
			str = " Elements of array after division: ";
			ArrayAfterDivision(a, b, l, del);
			AddFile(fileName, b, l, str);
			str = " Sorted array: ";
			BubbleSort(a, l, del);
			AddFile(fileName, a, l, str);
			cout << "Information has been successfully added in " << fileName << "!" << endl;
			system("pause");
			return;
		}
	}
}

void OnConsole(int* a, int* b, int p, int l)
{
	while (true)
	{
		int del;
		cout << "Enter the divisor: ";
		cin >> del;
		if (del == 0)
		{
			cout << "You enter wrong number!" << endl;
			system("pause");
		}
		else if (del != 0)
		{
			system("cls");
			cout << " The original array: ";
			DisplayArray(a, N);
			cout << endl;
			cout << "Array of odd index and even elements: ";
			WriteInNewArray(a, b, N);
			DisplayArray(b, p);
			cout << endl;
			cout << " Array of remaining elements: ";
			ArrayOfRemainingElement(a, b, N, p);
			DisplayArray(a, l);
			cout << endl;
			cout << " Elements of array after division: ";
			ArrayAfterDivision(a, b, l, del);
			DisplayArray(b, l);
			cout << endl;
			cout << " Sorted array: ";
			BubbleSort(a, l, del);
			DisplayArray(a, l);
			cout << endl;
			system("pause");
			return;
		}
	}
}