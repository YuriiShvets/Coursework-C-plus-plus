/*
Stack.h
Coursework
Shvets Ju. BS-33
Interface to abstract class "Stack"
*/
#pragma once
#ifndef STACK
#define STACK
#include "Freight_train.h"	//��������� ���� �� ������ Freight_train
#include "Passenger_train.h"//��������� ���� �� ������ Passenger train

struct Element				//������� �����
{
	Train *data;			//�����
	Element *next;			//�������� �� ��������� ������� �����
};

class Stack					//���� ���������� (�����)
{
	Element *head;			//�������� �� ������ ������� �����
	int Size() const;		//������� �������� � ��������
public:
	Stack();				//�����������
	void push(Train *B);	//��������� ������
	void print() const;		//���� ��������
	void pop();				//��������� ������
	void Write_to_the_file() const;//�������� � ����
	void Read_from_the_file();//������� � �����
	void Sort();			//���������
	void Fing_the_object() const;//�������� ����� ������ �� ��������� ������� ������
	void Clean_collection();//�������� ���������
	~Stack();				//����������
};

#endif