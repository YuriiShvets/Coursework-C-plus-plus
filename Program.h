/*
Program.h
Coursework
Shvets Ju. BS-33
Interface to class "Program"
*/
#pragma once
#ifndef PROGRAM
#define PROGRAM
#include "Stack.h"		//��������� ���� �� ������ Stack


class Program			//���� ��������
{
	static Program * p_Program;//�������� �� ��������������� �������� ������������ Singletone
	Stack A;			//��������� ��������
	Program();			//�����������
	void Create_passenger_train();//��������� ������������� ������
	void Create_freight_train();//��������� ���������� ������
public:
	static Program *get_Program();//������� �� ��������������� �������� ������������ Singletone
	void Run();			//����
	~Program();			//����������
};

#endif