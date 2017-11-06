/*
Passenger_train.cpp
Coursework
Shvets Ju. BS-33
Implementation to class "Passenger_train"
*/
#include "Passenger_train.h"

Passenger_train::Passenger_train()//конструктор по замовчуванню
{
}
//----------------------------------------------------------------
Passenger_train::Passenger_train(int in_number, string in_route, string in_type, int in_length, int in_seats, bool in_dining_truck, Time in_departure_time, Time in_arrival_time):Train(in_number, in_route, in_type, in_length, in_departure_time, in_arrival_time), seats(in_seats), dining_truck(in_dining_truck)//конструктор із параметрами
{
}
//----------------------------------------------------------------
void Passenger_train::enter()
{
	Train::enter();
	cout<<"\nSeats in the truck: ";
	cin>>seats;//вводимо кількість місць
	cout<<"\ndining truck (1 - yes, 0 - no)";
	cin>>dining_truck;//вводимо наявність вагону-ресторану
	set_type("Passenger_train");
}
//----------------------------------------------------------------
void Passenger_train::set_seats(int in_seats)//функція для ввода кількості місць
{
	seats=in_seats;//вводимо кількість місць
}
//----------------------------------------------------------------
void Passenger_train:: set_dining_truck(bool in_dining_truck)//функція для ввода інформації про наявність вагона-ресторану
{
	dining_truck=in_dining_truck;//вводимо інформацію про наявність вагона-ресторану
}
//----------------------------------------------------------------
int Passenger_train::get_seats() const//функція для отримання кількості місць
{
	return seats;//повертаємо кількість місць
}
//----------------------------------------------------------------
bool Passenger_train::get_dining_truck() const//функція для отримання інформації про наявність вагона-ресторану
{
	return dining_truck;//повертаємо про наявність вагона-ресторану
}
//----------------------------------------------------------------
void Passenger_train::print() const//функція для друку вмісту об'єкту
{
	Train::print();//викликаєть ся функція друку із базового класу "Train"
	cout<<"number of seats in truck - "<<seats<<"\nDining truck: ";	//вивод кількост місць
	if(dining_truck==false)
		cout<<"no\n";
	else
		cout<<"yes\n";
}
//----------------------------------------------------------------
ostream& operator << (ostream &os, Passenger_train &dt)//перегрузка оператора вивода в потік
{
	os<<1<<endl<<dt.get_number()<<endl<<dt.get_type()<<endl<<dt.get_route()<<endl<<dt.get_length()<<endl<<dt.get_arrival_time().hours<<endl<<dt.get_arrival_time().minutes<<endl<<dt.get_departure_time().hours<<endl<<dt.get_departure_time().minutes<<endl<<dt.seats<<endl<<dt.dining_truck<<endl;//виводимо данні про потяг у потік
	return os;//повертаємо потік
}
//----------------------------------------------------------------
istream& operator >> (istream &is, Passenger_train &dt)//перегрузка операції ввода з потока
{
	int in_number;					//створюємо змінну куди буде записано номер потягу
	string in_route, in_type, buf;
	is>>in_number;					//вводимо з потоку номер потяга
	getline(is, buf, '\n');
	getline(is, in_type, '\n');		//водимо з потоку тип потяга
	getline(is, in_route, '\n');	//вводимо з потоку маршрут
	Time in_departure_time, in_arrival_time;//створюємо змінні куди будуть збережені чвс відправлення і час прибуття
	int in_length, in_seats;		//створюємо змінні куди будуть збережені кількість вагонів і кількість місць у вагоні
	is>>in_length;					//вводимо з потоку кількість вагонів
	is>>in_arrival_time.hours;		//вводимо з потоку час прибуття (години)
	is>>in_arrival_time.minutes;	//вводимо з потоку час прибуття (хвилини)
	is>>in_departure_time.hours;	//вводимо з потоку час відправлення (години)
	is>>in_departure_time.minutes;	//вводимо з потоку час відправлення (хвилини)
	is>>in_seats;					//ввод із потоку кількості місць
	bool in_dining_truck;			//створюємо змінну куди буде записана інформація про наявність вагона-ресторана
	is>>in_dining_truck;			//вводимо з потоку інформацію про наявність вагона-ресторана
	dt.set_type(in_type);			//викликаємо функцію ввода для типу потяга
	dt.set_route(in_route);			//викликаємо функцію ввода для маршруту потяга
	dt.set_length(in_length);		//викликаємо функцію ввода для кількості вагонів потяга
	dt.set_dining_truck(in_dining_truck);//викликаємо функцію ввода для інформації про наявність вагона-ресторана
	dt.set_arrival_time(in_arrival_time);//викликаємо функцію ввода для часу прибуття
	dt.set_departure_time(in_departure_time);//викликаємо функцію ввода для часу відправлення
	dt.set_seats(in_seats);			//викликаємо функцію ввода для кількості місць у вагоні
	dt.set_number(in_number);		//викликаємо функцію ввода для номера потяга
	return is;						//повертаємо потік
}
//----------------------------------------------------------------
Passenger_train::~Passenger_train()//деструктор
{
}