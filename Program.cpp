/*
Program.cpp
Coursework
Shvets Ju. BS-33
Implementation to class "Program"
*/
#include "Program.h"

Program* Program::get_Program()//������� �� ��������������� �������� ������������ Singletone
{
	if(!p_Program)
			p_Program = new Program();
		return p_Program;
}

Program *Program::p_Program=0;

Program::Program()//�����������
{
}
//----------------------------------------------------------------
void Program::Run()//������� ��� ������� ������ �� ������������
{
	int i;
	char s[10];
	do
	{
		system("cls");//������� �����
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
				system ("cls");//������� �����
				Create_passenger_train();//��������� ������� ��������� ������������� ������
				cin.get();
				break;
			}
		case 2:
			{
				system ("cls");//������� �����
				Create_freight_train();//��������� ������� ��� ��������� ���������� ������
				cin.get();
				break;
			}
		case 3:
			{
				system ("cls");//�������� ������
				A.print();//��������� ������� ��� ����� ����� ����������
				_getch();//��������
				break;
			}
		case 4:
			{
				system("cls");//�������� ������
				A.pop();//��������� ������� ��� ��������� ��������
				cout<<"One train was deleted";
				_getch();//��������
				break;
			}
		case 5:
			{
				system("cls");//�������� ������
				A.Write_to_the_file();//��������� ������� ��� ������ ����� ���������� � ����
				_getch();//��������
				break;
			}
		case 6:
			{
				system("cls");//�������� ������
				A.Read_from_the_file();//��������� ������� ��� ����� ����� ���������� � �����
				_getch();//��������
				break;
			}
		case 7:
			{
				system("cls");//�������� ������
				A.Sort();//��������� ������� ��� ���������� ����� ������
				_getch();//��������
				break;
			}
		case 8:
			{
				system ("cls");//������� �����
				A.Fing_the_object();//��������� ������� ��� ����������� ��'����
				_getch();//��������
				break;
			}
		case 9:
			{
				system("cls");//�������� ������
				A.Clean_collection();//��������� ������� ��� �������� ��������
				_getch();//��������
				break;
			}
		case 10://�������� � ��������
			{
				break;
			}
		default:
			{
				if(i<1||i>10)//���� ������� ����� �� �������� [1, 10]
				{
					system("cls");//�������� ������
					cout<<"������� �������� �i� 1 �� 10\n";
					_getch();//��������
				}
				break;
			}
		}
	}
	while (i!=10);
}
//----------------------------------------------------------------
void Program::Create_passenger_train()//������� ��� ��������� ������������� ������
{
	Passenger_train *B=new Passenger_train();//��������� ��'��� ������������� ������
	B->enter();
	A.push(B);//��������� ������� ��������� �������� � ����
}
//----------------------------------------------------------------
void Program::Create_freight_train()//������� ��� ��������� ���������� ��������
{
	Freight_train *B=new Freight_train();//��������� ��'��� ���������� ������
	B->enter();
	A.push(B);//��������� ������� ��������� �������� � ����
}
//----------------------------------------------------------------
Program::~Program()//����������
{
}