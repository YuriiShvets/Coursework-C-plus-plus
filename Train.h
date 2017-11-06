/*
Train.h
Coursework
Shvets Ju. BS-33
Interface to abstract class "Train"
*/
#pragma once	
#ifndef TRAIN
#define TRAIN
#include <iostream>	//підлючаємо бібліотнеку для роботи з потоком
#include <conio.h>
#include <string>	//підключаємо бібліотеку для роботи з рядкам
#include <fstream>	//підлючаємо бібліотеку для роботи з файлами
using namespace std;

struct Time
{
	int hours;		//години
	int minutes;	// хвилини
};

class Train					//Абстактний клас
{
	int number;				//номер потяга
	string route;			//маршрут
	string type;			//тип потяга
	int length;				//кількість вагонів
	Time departure_time;	//час відправлення
	Time arrival_time;		//час прибуття
public:
	Train();							//конструктор по замовчуванню
	Train(int in_number, string in_route, string in_type, int in_length,const Time &in_departure_time,const Time &in_arrival_time);//конструктор із параметрами
	void enter();
	void set_number(int in_number);		//функція для ввода номера потяга
	int get_number() const;				//функція для отримання номера потяга
	void set_type(string in_type);		//функція для вводу типу потяга
	string get_type() const;			//функція для отримання типу потяга
	void set_route(const string &in_route);//функція для вводу маршруту потяга
	string get_route() const;			//функція для отримання маршруту потяга
	void set_length(int in_length);		//функція для вводу кількості вагонів
	int get_length() const;				//функція для отримання кількості вагонів
	void set_departure_time(const Time &in_departure_time);//функція для вводу часу відправлення
	Time get_departure_time() const;	//функція для отримання часу відправлення
	void set_arrival_time(const Time &in_arrival_time);//функція для вводу часу прибуття
	Time get_arrival_time() const;		//функція для отримання часу прибуття
	virtual void print()const=0;		//друк об'єкта
	virtual ~Train();					//деструктор
};
#endif