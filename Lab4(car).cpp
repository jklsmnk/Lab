#include<iostream>

using namespace std;

const int N = 10;
const int M = 10;

class Car
{
public:
	Car()
	{

	}

	void SetModel(char* s)
	{
		strcpy(model, s);
	}

	void SetColour(char* s)
	{
		strcpy(colour, s);
	}

	void SetSerialNumber(int serialNumber)
	{
		this->serialNumber = serialNumber;
	}
	void SetRegistrationNumber(int registrationNumber)
	{
		this->registrationNumber = registrationNumber;
	}

	void SetYearOfIssue(int yearOfIssue)
	{
		this->yearOfIssue = yearOfIssue;
	}
	void SetYearOfInspection(int yearOfInspection)
	{
		this->yearOfInspection = yearOfInspection;
	}

	void SetPrice(int price)
	{
		this->price = price;
	}

	void SetCar(char* c1, char* c2, int d1, int d2, int d3, int d4, int d5)
	{
		SetModel(c1);
		SetColour(c2);
		SetSerialNumber(d1);
		SetRegistrationNumber(d2);
		SetYearOfIssue(d3);
		SetYearOfInspection(d4);
		SetPrice(d5);
	}


	char* GetModel()
	{
		return model;
	}

	char* GetColour()
	{
		return colour;
	}

	int GetSerialNumber()
	{
		return serialNumber;
	}

	int GetYearOfIssue()
	{
		return yearOfIssue;
	}

	int GetRegistrationNumber()
	{
		return registrationNumber;
	}

	int GetYearOfInspection()
	{
		return yearOfInspection;
	}

	int GetPrice()
	{
		return price;
	}

	void DisplayCar()
	{
		cout << endl << model << ",\t" << endl;;
		cout.precision();
		cout << colour << " ,\t" << serialNumber << " ,\t" << yearOfIssue << " ,\t" << registrationNumber << ",\t" << yearOfInspection << ",\t" << price << " ,\t";
	}

private:
	char model[N], colour[N];
	int serialNumber, registrationNumber, yearOfIssue, yearOfInspection, price;
};

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
	cout << " The list of Cars:";
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