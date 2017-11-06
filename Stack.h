/*
Stack.h
Coursework
Shvets Ju. BS-33
Interface to abstract class "Stack"
*/
#pragma once
#ifndef STACK
#define STACK
#include "Freight_train.h"	//п≥дключаЇмо файл ≥з класом Freight_train
#include "Passenger_train.h"//п≥дключаЇмо файл ≥з класом Passenger train

struct Element				//≈лемент стека
{
	Train *data;			//пот€г
	Element *next;			//вказ≥вник на наступний елемент стека
};

class Stack					//клас контейнера (стека)
{
	Element *head;			//вказ≥вник на перший елемент стека
	int Size() const;		//к≥льк≥сть елемент≥в в колекц≥њ
public:
	Stack();				//конструктор
	void push(Train *B);	//додаванн€ пот€га
	void print() const;		//друк колекц≥њ
	void pop();				//видаленн€ пот€га
	void Write_to_the_file() const;//записати у файл
	void Read_from_the_file();//зчитати з файлу
	void Sort();			//сортувати
	void Fing_the_object() const;//виводить номер пот€га ≥з найб≥льшою к≥льк≥стю вагон≥в
	void Clean_collection();//очистити клолекц≥ю
	~Stack();				//деструктор
};

#endif