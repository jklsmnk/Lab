#include<iostream>
#include "Header.h"

using namespace std;

	Car::Car()
	{

	}

	void Car::SetModel(char* c)
	{
		strcpy(model, c);
	}

	void Car::SetColour(char* c)
	{
		strcpy(colour, c);
	}

	void Car::SetSerialNumber(int serialNumber)
	{
		this->serialNumber = serialNumber;
	}
	void Car::SetRegistrationNumber(int registrationNumber)
	{
		this->registrationNumber = registrationNumber;
	}

	void Car::SetYearOfIssue(int yearOfIssue)
	{
		this->yearOfIssue = yearOfIssue;
	}
	void Car::SetYearOfInspection(int yearOfInspection)
	{
		this->yearOfInspection = yearOfInspection;
	}

	void Car::SetPrice(int price)
	{
		this->price = price;
	}

	void Car::SetCar(char* c1, char* c2, int d1, int d2, int d3, int d4, int d5)
	{
		SetModel(c1);
		SetColour(c2);
		SetSerialNumber(d1);
		SetRegistrationNumber(d2);
		SetYearOfIssue(d3);
		SetYearOfInspection(d4);
		SetPrice(d5);
	}


	char* Car::GetModel()
	{
		return model;
	}

	char* Car::GetColour()
	{
		return colour;
	}

	int Car::GetSerialNumber()
	{
		return serialNumber;
	}

	int Car::GetYearOfIssue()
	{
		return yearOfIssue;
	}

	int Car::GetRegistrationNumber()
	{
		return registrationNumber;
	}

	int Car::GetYearOfInspection()
	{
		return yearOfInspection;
	}

	int Car::GetPrice()
	{
		return price;
	}

	void Car::DisplayCar()
	{
		cout << endl << model << ",\t" << endl;;
		cout.precision();
		cout << colour << " ,\t" << serialNumber << " ,\t" << yearOfIssue << " ,\t" << registrationNumber << ",\t" << yearOfInspection << ",\t" << price << " ,\t";
	}





