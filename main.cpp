/*
main.cpp
Coursework
Shvets Ju. BS-33
File with main function
*/

#include "Program.h"//підключаємо файл із класом "Program"

void main()
{
	setlocale(LC_ALL,("ukrainian"));
	Program *K=Program::get_Program();//створюємо об'єкт класу "Program"
	K->Run();//викликаємо функцію коримтувача
	delete K;//видаляємо об'єкт класу "Program"
}