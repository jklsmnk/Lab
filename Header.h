#pragma once

const int N = 10;
const int M = 10;

class Car
{
public:
	Car();

	void SetModel(char*);
	void SetColour(char*);
	void SetSerialNumber(int);
	void SetRegistrationNumber(int);
	void SetYearOfIssue(int);
	void SetYearOfInspection(int);
	void SetPrice(int);

	void SetCar(char*, char*, int, int, int, int, int);

	void DisplayCar();

	char* GetModel();
	char* GetColour();
	int GetSerialNumber();
	int GetYearOfIssue();
	int GetRegistrationNumber();
	int GetYearOfInspection();
	int GetPrice();

private:
	char model[N], colour[N];
	int serialNumber, registrationNumber, yearOfIssue, yearOfInspection, price;
};