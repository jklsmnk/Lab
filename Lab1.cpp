/* example 1
Your array:
59 45 78 36
The new array:
59 45 36
The remainder of the array:
78
*/

/* example 2
Your array:
5 45 11 68 74 37 51 89 101 76 
The new array:
101 89 76 68 51 45 37 11 5
The remainder of the array:
74
*/
#include <iostream>

using namespace std;

int* InputArray(int);
void DisplayArray(int*, int );
void DeleteElement(int*, int, int);
int* Deleting(int*, int&);
void Sort(int*, int);
void Swap(int&, int& );

int main()
{
	int n;
	cout << "Please, enter the number of array elements:\n";
	cin >> n;
	system("cls");
	int* array1 = InputArray(n);
	cout << "Your array:\n";
	DisplayArray(array1, n);
	cout << endl;
	int n1 = n;
	int* array2 = Deleting(array1, n1);
	Sort(array1, n1);
	cout << "The new array:\n";
	DisplayArray(array1, n1);
	cout << endl;
	cout << "The remainder of the array";
	cout << endl;
	DisplayArray(array2, n - n1);
	cout << endl;
	system("pause");
}

int* InputArray(int n)
{
	int* a = new int[n];
	for (int i = 0; i < n; i++) 
	{
		cout << "Enter the " << i + 1 << "'s number\n";
		int b;
		cin >> b;
		a[i] = b;
		system("cls");
	}
	return a;
}

void DisplayArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void DeleteElement(int* a, int n, int b)
{
	for (int i = b; i < n; i++)
	{
		a[i] = a[i + 1];
	}
}

int* Deleting(int* a, int& n)
{
	int* b = new int[n];
	int n1 = -1;
	for (int i = n - 1; i >= 0; i--)
		if (i % 2 == 0 && a[i] % 2 == 0)
		{
			n1++;
			b[n1] = a[i];
			DeleteElement(a, n, i);
			n--;
		}
	return b;
}

void Sort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j - 1] < a[j])
			{
				Swap(a[j], a[j - 1]);
			}
		}
	}
}

void Swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}
