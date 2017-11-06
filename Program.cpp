/*
Program.cpp
Coursework
Shvets Ju. BS-33
Implementation to class "Program"
*/
#include "Program.h"

Program* Program::get_Program()//функція що використовується патерном проектування Singletone
{
	if(!p_Program)
			p_Program = new Program();
		return p_Program;
}

Program *Program::p_Program=0;

Program::Program()//конструктор
{
}
//----------------------------------------------------------------
void Program::Run()//функція для ведення діалога із користувачем
{
	int i;
	char s[10];
	do
	{
		system("cls");//очищуєсо екран
		cout<<"--------------- MENU --------------\n"
			<<"<1>.Create an object a passenger train\n"
			<<"<2>.Create an object a freight train\n"
			<<"<3>.Show trains\n"
			<<"<4>.Remove train\n"
			<<"<5>.Save to the file\n"
			<<"<6>.Load from the file\n"
			<<"<7>.Sort objekts\n"
			<<"<8>.Fing the object\n"
			<<"<9>.Clean collection\n"
			<<"<10>.Leav the program\n\n";
		cin.getline(s,10);
		i=atoi(s);
		switch(i)
		{
		case 1:
			{
				system ("cls");//очищуємо екран
				Create_passenger_train();//викликаємо функцію створення пасажирського потяга
				cin.get();
				break;
			}
		case 2:
			{
				system ("cls");//очищуємо екран
				Create_freight_train();//викликаємо функцію для створення вантажного потяга
				cin.get();
				break;
			}
		case 3:
			{
				system ("cls");//очищення екрана
				A.print();//викликаємо функцію для друку вмісту контейнера
				_getch();//затримка
				break;
			}
		case 4:
			{
				system("cls");//очищення екрана
				A.pop();//викликаємо функцію для видалення елемента
				cout<<"One train was deleted";
				_getch();//затримка
				break;
			}
		case 5:
			{
				system("cls");//очищення екрана
				A.Write_to_the_file();//викликаємо функцію для вивода вмісту контейнера у файл
				_getch();//затримка
				break;
			}
		case 6:
			{
				system("cls");//очищення екрана
				A.Read_from_the_file();//викликаємо функцію для ввода вмісту контейнера з файлу
				_getch();//затримка
				break;
			}
		case 7:
			{
				system("cls");//очищення екрана
				A.Sort();//викликаємо функцію для сортування вмісту екрана
				_getch();//затримка
				break;
			}
		case 8:
			{
				system ("cls");//очищуємо екран
				A.Fing_the_object();//викликаємо функцію для знаходження об'єкта
				_getch();//затримка
				break;
			}
		case 9:
			{
				system("cls");//очищення екрана
				A.Clean_collection();//викликаємо функцію для очищення колекції
				_getch();//затримка
				break;
			}
		case 10://виходимо з програми
			{
				break;
			}
		default:
			{
				if(i<1||i>10)//якщо введене число не належить [1, 10]
				{
					system("cls");//очищення екрана
					cout<<"Вводьте значення вiд 1 до 10\n";
					_getch();//затримка
				}
				break;
			}
		}
	}
	while (i!=10);
}
//----------------------------------------------------------------
void Program::Create_passenger_train()//функція для додавання пасажирського потяга
{
	Passenger_train *B=new Passenger_train();//створюємо об'єкт пасажирського потяга
	B->enter();
	A.push(B);//викликаємо функцію додавання елемента у стек
}
//----------------------------------------------------------------
void Program::Create_freight_train()//функція для додавання вантажного елемента
{
	Freight_train *B=new Freight_train();//створюємо об'єкт вантажного потяга
	B->enter();
	A.push(B);//викликаємо функцію додавання елемента в стек
}
//----------------------------------------------------------------
Program::~Program()//деструктор
{
}