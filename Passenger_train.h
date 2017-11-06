/*
Passenger_train.h
Coursework
Shvets Ju. BS-33
Interface to abstract class "Passenger_train"
*/
#pragma once
#ifndef PASSENGER
#define PASSENGER
#include "Train.h"//підключаємо файл із абстрактним класом Train

class Passenger_train: public Train	//клас-нащадок класу Train
{
	int seats;						//кількість місць у вагоні
	bool dining_truck;				//наявність вагону ресторану
public:
	Passenger_train();				//конструктор по замовчуванню
	Passenger_train(int in_number, string in_route, string in_type, int in_length, int in_seats, bool in_dining_truck, Time in_departure_time, Time in_arrival_time);//конструктор із парамктрами
	void enter();
	void set_seats(int in_seats);	//функція для вводу кількості місць у вагоні
	void set_dining_truck(bool in_dining_truck);//функція для вводу наявості вагону-ресторану
	int get_seats() const;			//функція для отримання кількості місць у вагоні
	bool get_dining_truck() const;	//функція для отримання інформації  про наявність вагону-ресторану
	void print() const;				//друк об'єкта
	friend ostream& operator << (ostream &os, Passenger_train &dt);//перегрузка операції вивода в потік
	friend istream& operator >> (istream &is, Passenger_train &dt);//перегрузка операції ввода з потока
	~Passenger_train();				//деструктор
};
#endif