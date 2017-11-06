/*
Freight_train.cpp
Coursework
Shvets Ju. BS-33
Implementation to class "Freight_train"
*/
#include "Freight_train.h"

Freight_train::Freight_train()//конструктор по замовчуванню
{
}
//----------------------------------------------------------------
Freight_train::Freight_train(int in_number, string in_route, string in_type, int in_length, int in_cargo_capacity, Time in_departure_time, Time in_arrival_time):Train(in_number, in_route, in_type, in_length, in_departure_time, in_arrival_time), cargo_capacity(in_cargo_capacity)//конструктор із параметрами
{
}
//----------------------------------------------------------------
void Freight_train::enter()
{
	Train::enter();
	cout<<"\nCargo capacity(Т): ";
	cin>>cargo_capacity;//вводимо вантажопідйомність
	set_type("Freight_train");
}
//----------------------------------------------------------------
void Freight_train::set_cargo_capacity(int in_cargo_capacity)//функція для ввода вантажопідйомності вагону
{
	cargo_capacity=in_cargo_capacity;//вводимо вантажопідйомність вагону
}
//----------------------------------------------------------------
int Freight_train::get_cargo_capacity() const//функція для отримання вантажопідйомності вагону
{
	return cargo_capacity;//повертаємо вантажопідьомність вагону
}
//----------------------------------------------------------------
void Freight_train::print() const//функція для друку інформації про потяг
{
	Train::print();//викликаємо функцію друку із базового класу "Train"
	cout<<"Cargo capacity of truck - "<<cargo_capacity<<" T";//виводимо вантажопідйомність вагону
}
//----------------------------------------------------------------
ostream& operator << (ostream &os, Freight_train &dt)//перегрузка операції вивода в потік
{
	os<<2<<endl<<dt.get_number()<<endl<<dt.get_type()<<endl<<dt.get_route()<<endl<<dt.get_length()<<endl<<dt.get_arrival_time().hours<<endl<<dt.get_arrival_time().minutes<<endl<<dt.get_departure_time().hours<<endl<<dt.get_departure_time().minutes<<endl<<dt.cargo_capacity<<endl;//виводимо інформацію про потяг в потік
	return os;//повертаємо потік
}
//----------------------------------------------------------------
istream& operator >> (istream &os, Freight_train &dt)//перегрузка ввода в з потоку
{
	int in_number;//створюємо змінну куди буде записаний номер потяга
	string in_route, in_type, buf;
	os>>in_number;//вводимо з потоку номер потяга
	getline(os, buf, '\n');
	getline(os, in_type, '\n');//вводимо з потоку тип потяга
	getline(os, in_route, '\n');//вводимо з потоку маршрут потяга
	Time in_departure_time, in_arrival_time;//створюємо змінні куди будуть записані час відправлення і час прибуття
	int in_length, in_cargo_capacity;//створюємо змінні куди будуть записані кількість вагонів і вантажопідйомність вагону
	os>>in_length;//вводимо з потоку кількіст  вагонів
	os>>in_arrival_time.hours;//вводимо з потоку часу прибуття (години)
	os>>in_arrival_time.minutes;//вводимо з потоку часу прибуття (хвилини)
	os>>in_departure_time.hours;//вводимо з потоку час відправлення (години)
	os>>in_departure_time.minutes;//вводимо з потоку час відправлення (хвилини)
	os>>in_cargo_capacity;//ввод з потоку вантажопідйомності вагону
	dt.set_type(in_type);//викликаємо функцію для ввода типу потяга
	dt.set_route(in_route);//викликаємо функцію для ввода маршруту
	dt.set_length(in_length);//викликаємо функцію для ввода кількості вагонів
	dt.set_cargo_capacity(in_cargo_capacity);//викликаємо функцію для вводу вантажопідйомності
	dt.set_arrival_time(in_arrival_time);//викликаємо функцію для ввода часу прибуття
	dt.set_departure_time(in_departure_time);//викликаємо функцію для часу відправлення
	dt.set_number(in_number);//викликаємо функцію для номера потяга
	return os;//повертаємо потік
}
//----------------------------------------------------------------
Freight_train::~Freight_train()//деструктор
{
}