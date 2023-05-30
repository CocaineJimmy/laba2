#include <iostream>
#include <conio.h>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;

struct Car {
	string mark, fuelMark;
	double vBak, vFuel, vOil;
	bool dry;
	Car* next;
};
typedef Car* PCar;
double bank;
void addCar(PCar& startCar, PCar& endCar);
void delCar(PCar& startCar, PCar& endCar);
void seeCars(PCar startCar);
void seeCar(PCar startCar);

string markCar[] = {"Audi", "BMW", "Ford" , "Honda" , "Hyundai" , "Kia" , "Lada" , "Mazda" };
string markFuel[] = {"АИ-80", "АИ-92", "АИ-95", "АИ-95+", "АИ-98", "АИ-100"};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bank = 0;
	PCar startCar = NULL, endCar = NULL;
	int cars = 3 + rand() % (10 - 3);
	for (int i = 0; i < cars;i++) {
		addCar(startCar, endCar);
	}
	string a = "Доброе утро. Время открывать станцию и принимать машины";
	for (int i = 0; i < a.length(); i++) {
		Sleep(25 + rand() % (70 - 25));
		cout << a[i];
	}
	cout << endl<<endl;
	Sleep(700);
	system("pause");
	system("cls");
	Sleep(250);

	while (1) {
		cout << "Заработок: " << bank << endl;
		cout << "Машин: " << cars  << endl << endl;
		cout << "Операции:" << endl;
		cout << "1. Приступить к машине" << endl;
		cout << "2. Вывод информации о машинах" << endl;
		cout << "0. Закончить" << endl;
		switch (_getch())
		{
		case '1':
			cars--;
			delCar(startCar, endCar);
			break;

		case '2':
			seeCars(startCar);
			break;

		case '0':
			return 0;
			break;

		default:
			system("cls");
			break;
		}
	}

	return 0;
}

void addCar(PCar& startCar, PCar& endCar) {
	system("cls");
	PCar adding = new Car;
	adding->next = 0;
	if (!adding) {
		cout << "ERORR" << endl;
		return;
	}
	adding->mark = markCar[0+rand()%7];
	adding->fuelMark = markFuel[0+rand()%5];
	adding->vBak = 45 + rand() % (100-45);
	do
	{
		adding->vFuel = 45 + rand() % (100 - 45);
	} while (adding->vBak <= adding->vFuel);
	adding->vOil = 1+rand()%(2-1);
	adding->dry = 0 + rand() % 1;
	
	if (!startCar) {
		startCar = endCar = adding;
	}
	else {
		endCar->next = adding;
		endCar = adding;
	}
}
void seeCar(PCar startCar) {
	PCar list = startCar;
	if (!list) {
		cout << "Очередь пуста" << endl;
		return;
	}
	cout << "	Марка: " << list->mark << endl;
	cout << "	Марка бензина: " << list->fuelMark << endl;
	cout << "	Объем бака: " << list->vBak << endl;
	cout << "	Бензина сейчас: " << list->vFuel << endl;
	cout << "	Масла сейчас: " << list->vOil << endl;
	cout << "	Грязный: " << list->dry << endl;
	cout << endl << endl;
	
	return;
}
void delCar(PCar& startCar, PCar& endCar) {
	system("cls");
	if (!startCar) {
		cout << "Очередь пуста" << endl;
		return;
	}
	string a = "Мастерская";
	for (int i = 0; i < a.length(); i++) {
		Sleep(15 + rand() % (35 - 15));
		cout << a[i];
	}
	cout << endl << endl;
	Sleep(450);
	bool repair = false;
	PCar save;
	save = startCar;
	while (repair == false) {
		seeCar(save);
		cout << endl << endl;
		cout << "Операции:" << endl;
		cout << "1. Почистить" << endl;
		cout << "2. Пополнить бензин" << endl;
		cout << "3. Заливка масла" << endl;
		cout << "0. Завершить" << endl;
		switch (_getch())
		{
		case '1':
			system("cls");
			if (save->dry == false) {
				save->dry = true;
				cout << "Машина помыта" << endl << endl;
				bank += 200;
			}
			else {
				cout << "Машине не требуется мытье" << endl << endl;
			}
			break;

		case '2':
			system("cls");
			if (save->vBak != save->vFuel) {
				bank += 50 * (save->vBak - save->vFuel);
				save->vFuel = save->vBak;
				cout << "Машина заправлена" << endl << endl;
			}
			else {
				cout << "Машине не требуется пополнение бензина" << endl << endl;
			}
			break;

		case '3':
			system("cls");
			if (save->vOil != 2) {
				bank += 75 * (2 - save->vOil);
				save->vOil = 2;
				cout << "Машина заправлена" << endl << endl;
			}
			else {
				cout << "Машине не требуется заливка масла" << endl << endl;
			}
			break;

		case '0':
			system("cls");
			repair = true;
			break;

		default:
			system("cls");
			break;
		}
	}
	if (startCar == endCar) {
		delete(startCar);
		startCar = endCar = NULL;
		return;
	}
	save = startCar->next;
	delete(startCar);
	startCar = save;
}

void seeCars(PCar startCar) {
	system("cls");
	PCar list = startCar;
	if (!list) {
		cout << "Очередь пуста" << endl;
		return;
	}
	for (int i = 1; list != NULL;i++) {
		cout << "Машина №" << i<<endl;
		cout << "	Марка: " << list->mark << endl;
		cout << "	Марка бензина: " << list->fuelMark << endl;
		cout << "	Объем бака: " << list->vBak << endl;
		cout << "	Бензина сейчас: " << list->vFuel << endl;
		cout << "	Масла сейчас: " << list->vOil << endl;
		cout << "	Грязный: " << list->dry << endl;
		cout << endl;
		list = list->next;
	}
	return;
}