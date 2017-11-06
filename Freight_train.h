/*
Freight_train.h
Coursework
Shvets Ju. BS-33
Interface to abstract class "Freight_train"
*/
#pragma once
#ifndef FREIGHT
#define FREIGHT
#include "Train.h"//підключаємо файл із абстрактним класом Train

class Freight_train: public Train	//клас-нащадок абстрактного класу Train
{
	int cargo_capacity;				//вантажопідйомність вагону
public:
	Freight_train();				//конструктор по замовчуванню
	Freight_train(int in_number, string in_route, string in_type, int in_length, int in_cargo_capacity, Time in_departure_time, Time in_arrival_time);//конструктор із параметрами
	void enter();
	void set_cargo_capacity(int in_cargo_capacity);//функція для ввода вантажопідьомності вагона
	int get_cargo_capacity() const;	//функція для отримання вантажопідьомності вагону
	void print() const;				// друк об'єкта
	friend ostream& operator << (ostream &os, Freight_train &dt);//перегрузка операції вивода в потік
	friend istream& operator >> (istream &os, Freight_train &dt);//перегрузка операції ввода  з потока
	~Freight_train();				//деструктор
};
#endif