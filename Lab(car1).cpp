#include<iostream>
#include "Header.h"

using namespace std;

Car InitCar();
Car* InitArray(int);
void DisplayArray(Car*, int);
void EnterArray(int*, int);
void SortModel(Car*, int);
void Swap(Car&, Car&);

int main()
{
	int n;
	cout << "Enter the number of Car:" << endl;
	cin >> n;
	system("cls");
	Car* cars = InitArray(n);
	if (!cars)
	{
		cout << "Enter erray!" << endl;
		system("pause");
		return 0;
	}

	cout << endl;
	cout << "The list of Cars:";
	DisplayArray(cars, n);
	cout << endl;
	cout << "The sorting list of Cars:";
	SortModel(cars, n);
	DisplayArray(cars, n);
	delete[] cars;
	system("pause");
	return 0;
}

Car InitCar()
{
	char model[N] = "", colour[N] = "";
	int serialNumber, registrationNumber, yearOfIssue, yearOfInspection, price;
	cout << "Enter the model: \n";
	cin.ignore();
	cin.get(model, N, '\n');
	cout << "Enter the colour:\n";
	cin.ignore();
	cin.get(colour, N, '\n');
	cout << "Enter Year Of Issue:\n";
	cin >> yearOfIssue;
	cout << "Enter Year Of Inspection:\n";
	cin >> yearOfInspection;
	cout << "Enter price:\n";
	cin >> price;
	cout << "Enter Serial Number:\n";
	cin >> serialNumber;
	cout << "Enter Registration Number:\n";
	cin >> registrationNumber;
	cout << endl;

	Car car;
	car.SetCar(model, colour, yearOfIssue, yearOfInspection, price, serialNumber, registrationNumber);
	return car;
}

Car* InitArray(int n)
{
	Car* array = new Car[n];
	if (!array)
		return NULL;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the information about " << i + 1 << "'s Car\n" << endl;
		array[i] = InitCar();
	}
	return array;
}

void EnterArray(int* array, int n)
{
	for (int i = 0; i < M; i++)
	{
		cout << "enter A[" << (i + 1) << "] = ";
		cin >> array[i];
	}
}

void DisplayArray(Car* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		array[i].DisplayCar();
	}
	cout << endl;
}

void SortModel(Car* array, int n)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (strcmp(array[j].GetModel(), array[j - 1].GetModel()) < 0)
			{
				Swap(array[j], array[j - 1]);
			}
		}
	}
}

void Swap(Car &a, Car  &b)
{
	Car  t = a;
	a = b;
	b = t;
}
