/*
Passenger_train.h
Coursework
Shvets Ju. BS-33
Interface to abstract class "Passenger_train"
*/
#pragma once
#ifndef PASSENGER
#define PASSENGER
#include "Train.h"//��������� ���� �� ����������� ������ Train

class Passenger_train: public Train	//����-������� ����� Train
{
	int seats;						//������� ���� � �����
	bool dining_truck;				//�������� ������ ���������
public:
	Passenger_train();				//����������� �� ������������
	Passenger_train(int in_number, string in_route, string in_type, int in_length, int in_seats, bool in_dining_truck, Time in_departure_time, Time in_arrival_time);//����������� �� �����������
	void enter();
	void set_seats(int in_seats);	//������� ��� ����� ������� ���� � �����
	void set_dining_truck(bool in_dining_truck);//������� ��� ����� ������� ������-���������
	int get_seats() const;			//������� ��� ��������� ������� ���� � �����
	bool get_dining_truck() const;	//������� ��� ��������� ����������  ��� �������� ������-���������
	void print() const;				//���� ��'����
	friend ostream& operator << (ostream &os, Passenger_train &dt);//���������� �������� ������ � ����
	friend istream& operator >> (istream &is, Passenger_train &dt);//���������� �������� ����� � ������
	~Passenger_train();				//����������
};
#endif