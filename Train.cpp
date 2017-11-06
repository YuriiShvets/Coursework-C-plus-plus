/*
Train.cpp
Coursework
Shvets Ju. BS-33
Implementation to abstract class "Train"
*/
#include "Train.h"

Train::Train()//���������� �� ������������
{
}
//----------------------------------------------------------------
 Train::Train(int in_number, string in_route, string in_type, int in_length,const Time &in_departure_time,const Time &in_arrival_time):number(in_number), route(in_route), type(in_type), length(in_length)//����������� � �����������
 {
	 departure_time.hours=in_departure_time.hours;		//����������� ��� ����������� (������)
	 departure_time.minutes=in_departure_time.minutes;	//���������� ��� ����������� (�������)
	 arrival_time.hours=in_arrival_time.hours;			//���������� ��� �������� (������)
	 arrival_time.minutes=in_arrival_time.minutes;		//���������� ��� �������� (�������)
 }
 //----------------------------------------------------------------
 void Train::enter()
 {
	cout<<"Train number: ";
	cin>>number;//���� ������ ������
	cin.get();
	cout<<"\nRoute: ";
	getline(cin,route);//������� ������� ������
	cout<<"\nLength: ";
	cin>>length;//������� ������� ������
	cout<<"\nDeparture time:\nhours: ";
	cin>>departure_time.hours;//������� ��� ����������� (������)
	cout<<"minutes: ";
	cin>>departure_time.minutes;//������� ��� ����������� (�������)
	if(((departure_time.minutes/60+departure_time.hours)>24)||(((departure_time.minutes/60+departure_time.hours)==24)&&(departure_time.minutes/60>0)))
		cout<<"You enter an invalid value of time\n";
	cout<<"\nArrival time:\nhours: ";
	cin>>arrival_time.hours;//����� ��� �������� (������)
	cout<<"minutes: ";
	cin>>arrival_time.minutes;//������� ��� �������� (������)
	if(((arrival_time.minutes/60+arrival_time.hours)>24)||(((arrival_time.minutes/60+arrival_time.hours)==24)&&(arrival_time.minutes/60>0)))
		cout<<"You enter an invalid value of time\n";
 }
 //----------------------------------------------------------------
 void Train::set_number(int in_number)	//������� ��� ����� ������ ������
 {
	 number=in_number;					//������� ����� ������
 }
 //----------------------------------------------------------------
 int Train::get_number() const	//������� ��� ���������� ������ ������
 {
	 return number;				//��������� ����� ������
 }
 //----------------------------------------------------------------
void Train::set_type(string in_type)//������� ��� ����� ���� ������
{
	type=in_type;					//������� ��� ������
}
//----------------------------------------------------------------
 string Train::get_type() const	//������� ��� ��������� ���� ������
 {
	 return type;				//��������� ��� ������
 }
 //----------------------------------------------------------------
 void Train::set_route(const string &in_route)	//������� ��� ����� �������� ������
 {
	 route=in_route;							//������� ������� ������
 }
 //----------------------------------------------------------------
 string Train::get_route() const//������� ��� ��������� ��������
 {
	 return route;				//��������� �������
 }
 //----------------------------------------------------------------
 void Train::set_length(int in_length)	//������� ��� ����� ������� ������
 {
	 length=in_length;					//������� ������� ������
 }
 //----------------------------------------------------------------
 int Train::get_length() const	//������� ��� ��������� ������� ������
 {
	 return length;				//��������� ������� ������
 }
 //----------------------------------------------------------------
 void Train::set_departure_time(const Time &in_departure_time)	//������� ��� ����� ���� �����������
 {
	 departure_time.hours=in_departure_time.hours;				//������� ��� ����������� (������)
	 departure_time.minutes=in_departure_time.minutes;			//������� ��� ����������� (�������)
 }
 //----------------------------------------------------------------
 Time Train::get_departure_time() const	//������� ��� ��������� ���� �����������
 {
	 return departure_time;				//��������� ��� �����������
 }
 //----------------------------------------------------------------
 void Train::set_arrival_time(const Time &in_arrival_time)	//������� ��� ����� ���� ��������
 {
	 arrival_time.hours=in_arrival_time.hours;				//������� ��� �������� (������)
	 arrival_time.minutes=in_arrival_time.minutes;			//������� ��� �������� (�������)
 }
 //----------------------------------------------------------------
 Time Train::get_arrival_time() const	//������� ��� ��������� ���� ��������
 {
	 return arrival_time;				//��������� ��� ��������
 }
 //----------------------------------------------------------------
 void Train::print() const//������� ��� ����� ��'����
 {
	 cout<<endl<<endl<<type<<"\nTrain number: "<<number<<"\nRoute: "<<route<<"\nlength - "<<length<<" wagons\narrival time - "<<arrival_time.hours<<":"<<arrival_time.minutes<<"\ndeparture time - "<<departure_time.hours<<":"<<departure_time.minutes<<endl;//������� ���� ��'����
 }
 //----------------------------------------------------------------
 Train::~Train()//����������
 {
 }