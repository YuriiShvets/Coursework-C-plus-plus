/*
main.cpp
Coursework
Shvets Ju. BS-33
File with main function
*/

#include "Program.h"//��������� ���� �� ������ "Program"

void main()
{
	setlocale(LC_ALL,("ukrainian"));
	Program *K=Program::get_Program();//��������� ��'��� ����� "Program"
	K->Run();//��������� ������� �����������
	delete K;//��������� ��'��� ����� "Program"
}