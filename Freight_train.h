/*
Freight_train.h
Coursework
Shvets Ju. BS-33
Interface to abstract class "Freight_train"
*/
#pragma once
#ifndef FREIGHT
#define FREIGHT
#include "Train.h"//��������� ���� �� ����������� ������ Train

class Freight_train: public Train	//����-������� ������������ ����� Train
{
	int cargo_capacity;				//���������������� ������
public:
	Freight_train();				//����������� �� ������������
	Freight_train(int in_number, string in_route, string in_type, int in_length, int in_cargo_capacity, Time in_departure_time, Time in_arrival_time);//����������� �� �����������
	void enter();
	void set_cargo_capacity(int in_cargo_capacity);//������� ��� ����� ���������������� ������
	int get_cargo_capacity() const;	//������� ��� ��������� ���������������� ������
	void print() const;				// ���� ��'����
	friend ostream& operator << (ostream &os, Freight_train &dt);//���������� �������� ������ � ����
	friend istream& operator >> (istream &os, Freight_train &dt);//���������� �������� �����  � ������
	~Freight_train();				//����������
};
#endif