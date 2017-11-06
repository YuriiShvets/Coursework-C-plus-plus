/*
Freight_train.cpp
Coursework
Shvets Ju. BS-33
Implementation to class "Freight_train"
*/
#include "Freight_train.h"

Freight_train::Freight_train()//����������� �� ������������
{
}
//----------------------------------------------------------------
Freight_train::Freight_train(int in_number, string in_route, string in_type, int in_length, int in_cargo_capacity, Time in_departure_time, Time in_arrival_time):Train(in_number, in_route, in_type, in_length, in_departure_time, in_arrival_time), cargo_capacity(in_cargo_capacity)//����������� �� �����������
{
}
//----------------------------------------------------------------
void Freight_train::enter()
{
	Train::enter();
	cout<<"\nCargo capacity(�): ";
	cin>>cargo_capacity;//������� ����������������
	set_type("Freight_train");
}
//----------------------------------------------------------------
void Freight_train::set_cargo_capacity(int in_cargo_capacity)//������� ��� ����� ���������������� ������
{
	cargo_capacity=in_cargo_capacity;//������� ���������������� ������
}
//----------------------------------------------------------------
int Freight_train::get_cargo_capacity() const//������� ��� ��������� ���������������� ������
{
	return cargo_capacity;//��������� ���������������� ������
}
//----------------------------------------------------------------
void Freight_train::print() const//������� ��� ����� ���������� ��� �����
{
	Train::print();//��������� ������� ����� �� �������� ����� "Train"
	cout<<"Cargo capacity of truck - "<<cargo_capacity<<" T";//�������� ���������������� ������
}
//----------------------------------------------------------------
ostream& operator << (ostream &os, Freight_train &dt)//���������� �������� ������ � ����
{
	os<<2<<endl<<dt.get_number()<<endl<<dt.get_type()<<endl<<dt.get_route()<<endl<<dt.get_length()<<endl<<dt.get_arrival_time().hours<<endl<<dt.get_arrival_time().minutes<<endl<<dt.get_departure_time().hours<<endl<<dt.get_departure_time().minutes<<endl<<dt.cargo_capacity<<endl;//�������� ���������� ��� ����� � ����
	return os;//��������� ����
}
//----------------------------------------------------------------
istream& operator >> (istream &os, Freight_train &dt)//���������� ����� � � ������
{
	int in_number;//��������� ����� ���� ���� ��������� ����� ������
	string in_route, in_type, buf;
	os>>in_number;//������� � ������ ����� ������
	getline(os, buf, '\n');
	getline(os, in_type, '\n');//������� � ������ ��� ������
	getline(os, in_route, '\n');//������� � ������ ������� ������
	Time in_departure_time, in_arrival_time;//��������� ���� ���� ������ ������� ��� ����������� � ��� ��������
	int in_length, in_cargo_capacity;//��������� ���� ���� ������ ������� ������� ������ � ���������������� ������
	os>>in_length;//������� � ������ ������  ������
	os>>in_arrival_time.hours;//������� � ������ ���� �������� (������)
	os>>in_arrival_time.minutes;//������� � ������ ���� �������� (�������)
	os>>in_departure_time.hours;//������� � ������ ��� ����������� (������)
	os>>in_departure_time.minutes;//������� � ������ ��� ����������� (�������)
	os>>in_cargo_capacity;//���� � ������ ���������������� ������
	dt.set_type(in_type);//��������� ������� ��� ����� ���� ������
	dt.set_route(in_route);//��������� ������� ��� ����� ��������
	dt.set_length(in_length);//��������� ������� ��� ����� ������� ������
	dt.set_cargo_capacity(in_cargo_capacity);//��������� ������� ��� ����� ����������������
	dt.set_arrival_time(in_arrival_time);//��������� ������� ��� ����� ���� ��������
	dt.set_departure_time(in_departure_time);//��������� ������� ��� ���� �����������
	dt.set_number(in_number);//��������� ������� ��� ������ ������
	return os;//��������� ����
}
//----------------------------------------------------------------
Freight_train::~Freight_train()//����������
{
}