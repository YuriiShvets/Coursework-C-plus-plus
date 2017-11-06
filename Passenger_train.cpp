/*
Passenger_train.cpp
Coursework
Shvets Ju. BS-33
Implementation to class "Passenger_train"
*/
#include "Passenger_train.h"

Passenger_train::Passenger_train()//����������� �� ������������
{
}
//----------------------------------------------------------------
Passenger_train::Passenger_train(int in_number, string in_route, string in_type, int in_length, int in_seats, bool in_dining_truck, Time in_departure_time, Time in_arrival_time):Train(in_number, in_route, in_type, in_length, in_departure_time, in_arrival_time), seats(in_seats), dining_truck(in_dining_truck)//����������� �� �����������
{
}
//----------------------------------------------------------------
void Passenger_train::enter()
{
	Train::enter();
	cout<<"\nSeats in the truck: ";
	cin>>seats;//������� ������� ����
	cout<<"\ndining truck (1 - yes, 0 - no)";
	cin>>dining_truck;//������� �������� ������-���������
	set_type("Passenger_train");
}
//----------------------------------------------------------------
void Passenger_train::set_seats(int in_seats)//������� ��� ����� ������� ����
{
	seats=in_seats;//������� ������� ����
}
//----------------------------------------------------------------
void Passenger_train:: set_dining_truck(bool in_dining_truck)//������� ��� ����� ���������� ��� �������� ������-���������
{
	dining_truck=in_dining_truck;//������� ���������� ��� �������� ������-���������
}
//----------------------------------------------------------------
int Passenger_train::get_seats() const//������� ��� ��������� ������� ����
{
	return seats;//��������� ������� ����
}
//----------------------------------------------------------------
bool Passenger_train::get_dining_truck() const//������� ��� ��������� ���������� ��� �������� ������-���������
{
	return dining_truck;//��������� ��� �������� ������-���������
}
//----------------------------------------------------------------
void Passenger_train::print() const//������� ��� ����� ����� ��'����
{
	Train::print();//��������� �� ������� ����� �� �������� ����� "Train"
	cout<<"number of seats in truck - "<<seats<<"\nDining truck: ";	//����� ������� ����
	if(dining_truck==false)
		cout<<"no\n";
	else
		cout<<"yes\n";
}
//----------------------------------------------------------------
ostream& operator << (ostream &os, Passenger_train &dt)//���������� ��������� ������ � ����
{
	os<<1<<endl<<dt.get_number()<<endl<<dt.get_type()<<endl<<dt.get_route()<<endl<<dt.get_length()<<endl<<dt.get_arrival_time().hours<<endl<<dt.get_arrival_time().minutes<<endl<<dt.get_departure_time().hours<<endl<<dt.get_departure_time().minutes<<endl<<dt.seats<<endl<<dt.dining_truck<<endl;//�������� ���� ��� ����� � ����
	return os;//��������� ����
}
//----------------------------------------------------------------
istream& operator >> (istream &is, Passenger_train &dt)//���������� �������� ����� � ������
{
	int in_number;					//��������� ����� ���� ���� �������� ����� ������
	string in_route, in_type, buf;
	is>>in_number;					//������� � ������ ����� ������
	getline(is, buf, '\n');
	getline(is, in_type, '\n');		//������ � ������ ��� ������
	getline(is, in_route, '\n');	//������� � ������ �������
	Time in_departure_time, in_arrival_time;//��������� ���� ���� ������ �������� ��� ����������� � ��� ��������
	int in_length, in_seats;		//��������� ���� ���� ������ �������� ������� ������ � ������� ���� � �����
	is>>in_length;					//������� � ������ ������� ������
	is>>in_arrival_time.hours;		//������� � ������ ��� �������� (������)
	is>>in_arrival_time.minutes;	//������� � ������ ��� �������� (�������)
	is>>in_departure_time.hours;	//������� � ������ ��� ����������� (������)
	is>>in_departure_time.minutes;	//������� � ������ ��� ����������� (�������)
	is>>in_seats;					//���� �� ������ ������� ����
	bool in_dining_truck;			//��������� ����� ���� ���� �������� ���������� ��� �������� ������-���������
	is>>in_dining_truck;			//������� � ������ ���������� ��� �������� ������-���������
	dt.set_type(in_type);			//��������� ������� ����� ��� ���� ������
	dt.set_route(in_route);			//��������� ������� ����� ��� �������� ������
	dt.set_length(in_length);		//��������� ������� ����� ��� ������� ������ ������
	dt.set_dining_truck(in_dining_truck);//��������� ������� ����� ��� ���������� ��� �������� ������-���������
	dt.set_arrival_time(in_arrival_time);//��������� ������� ����� ��� ���� ��������
	dt.set_departure_time(in_departure_time);//��������� ������� ����� ��� ���� �����������
	dt.set_seats(in_seats);			//��������� ������� ����� ��� ������� ���� � �����
	dt.set_number(in_number);		//��������� ������� ����� ��� ������ ������
	return is;						//��������� ����
}
//----------------------------------------------------------------
Passenger_train::~Passenger_train()//����������
{
}