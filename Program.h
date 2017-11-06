/*
Program.h
Coursework
Shvets Ju. BS-33
Interface to class "Program"
*/
#pragma once
#ifndef PROGRAM
#define PROGRAM
#include "Stack.h"		//п≥дключаЇмо файл ≥з класом Stack


class Program			//клас програми
{
	static Program * p_Program;//вказ≥вник що використовуЇтьс€ патерном проектуванн€ Singletone
	Stack A;			//екземпл€р колекц≥њ
	Program();			//конструктор
	void Create_passenger_train();//додаванн€ пасажирського пот€га
	void Create_freight_train();//додаванн€ вантажного пот€га
public:
	static Program *get_Program();//функц≥€ що використовуЇтьс€ патерном проектуванн€ Singletone
	void Run();			//меню
	~Program();			//деструктор
};

#endif