/*
Train.h
Coursework
Shvets Ju. BS-33
Interface to abstract class "Train"
*/
#pragma once	
#ifndef TRAIN
#define TRAIN
#include <iostream>	//�������� ��������� ��� ������ � �������
#include <conio.h>
#include <string>	//��������� �������� ��� ������ � ������
#include <fstream>	//�������� �������� ��� ������ � �������
using namespace std;

struct Time
{
	int hours;		//������
	int minutes;	// �������
};

class Train					//���������� ����
{
	int number;				//����� ������
	string route;			//�������
	string type;			//��� ������
	int length;				//������� ������
	Time departure_time;	//��� �����������
	Time arrival_time;		//��� ��������
public:
	Train();							//����������� �� ������������
	Train(int in_number, string in_route, string in_type, int in_length,const Time &in_departure_time,const Time &in_arrival_time);//����������� �� �����������
	void enter();
	void set_number(int in_number);		//������� ��� ����� ������ ������
	int get_number() const;				//������� ��� ��������� ������ ������
	void set_type(string in_type);		//������� ��� ����� ���� ������
	string get_type() const;			//������� ��� ��������� ���� ������
	void set_route(const string &in_route);//������� ��� ����� �������� ������
	string get_route() const;			//������� ��� ��������� �������� ������
	void set_length(int in_length);		//������� ��� ����� ������� ������
	int get_length() const;				//������� ��� ��������� ������� ������
	void set_departure_time(const Time &in_departure_time);//������� ��� ����� ���� �����������
	Time get_departure_time() const;	//������� ��� ��������� ���� �����������
	void set_arrival_time(const Time &in_arrival_time);//������� ��� ����� ���� ��������
	Time get_arrival_time() const;		//������� ��� ��������� ���� ��������
	virtual void print()const=0;		//���� ��'����
	virtual ~Train();					//����������
};
#endif