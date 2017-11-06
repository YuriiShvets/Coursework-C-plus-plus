/*
Train.cpp
Coursework
Shvets Ju. BS-33
Implementation to abstract class "Train"
*/
#include "Train.h"

Train::Train()//деструктор по замовчуванню
{
}
//----------------------------------------------------------------
 Train::Train(int in_number, string in_route, string in_type, int in_length,const Time &in_departure_time,const Time &in_arrival_time):number(in_number), route(in_route), type(in_type), length(in_length)//конструктор з параметрами
 {
	 departure_time.hours=in_departure_time.hours;		//≥н≥ц≥алазуЇмо час в≥дправленн€ (години)
	 departure_time.minutes=in_departure_time.minutes;	//≥н≥ц≥ал≥зуЇмо час в≥дправленн€ (хвилини)
	 arrival_time.hours=in_arrival_time.hours;			//≥н≥ц≥ал≥зуЇмо час прибутт€ (години)
	 arrival_time.minutes=in_arrival_time.minutes;		//≥н≥ц≥ал≥зуЇмо час прибутт€ (хвилини)
 }
 //----------------------------------------------------------------
 void Train::enter()
 {
	cout<<"Train number: ";
	cin>>number;//ввод номера пот€га
	cin.get();
	cout<<"\nRoute: ";
	getline(cin,route);//вводимо маршрут пот€га
	cout<<"\nLength: ";
	cin>>length;//вводимо к≥льк≥сть вагон≥в
	cout<<"\nDeparture time:\nhours: ";
	cin>>departure_time.hours;//вводимо час в≥дправленн€ (години)
	cout<<"minutes: ";
	cin>>departure_time.minutes;//вводимо час в≥дправленн€ (хвилини)
	if(((departure_time.minutes/60+departure_time.hours)>24)||(((departure_time.minutes/60+departure_time.hours)==24)&&(departure_time.minutes/60>0)))
		cout<<"You enter an invalid value of time\n";
	cout<<"\nArrival time:\nhours: ";
	cin>>arrival_time.hours;//вводи час прибутт€ (години)
	cout<<"minutes: ";
	cin>>arrival_time.minutes;//вводимо час прибутт€ (години)
	if(((arrival_time.minutes/60+arrival_time.hours)>24)||(((arrival_time.minutes/60+arrival_time.hours)==24)&&(arrival_time.minutes/60>0)))
		cout<<"You enter an invalid value of time\n";
 }
 //----------------------------------------------------------------
 void Train::set_number(int in_number)	//функц≥€ дл€ ввода номера пот€га
 {
	 number=in_number;					//вводимо номер пот€га
 }
 //----------------------------------------------------------------
 int Train::get_number() const	//функц≥€ дл€ поверненн€ номера пот€га
 {
	 return number;				//повертаЇмо номер пот€га
 }
 //----------------------------------------------------------------
void Train::set_type(string in_type)//функц≥€ дл€ ввода типу пот€га
{
	type=in_type;					//вводимо тип пот€га
}
//----------------------------------------------------------------
 string Train::get_type() const	//функц≥€ дл€ отриманн€ типу пот€га
 {
	 return type;				//повертаЇмо тип пот€га
 }
 //----------------------------------------------------------------
 void Train::set_route(const string &in_route)	//функц≥€ дл€ ввода маршруту пот€га
 {
	 route=in_route;							//вводимо маршрут пот€га
 }
 //----------------------------------------------------------------
 string Train::get_route() const//функц≥€ дл€ отриманн€ маршруту
 {
	 return route;				//повертаЇмо маршрут
 }
 //----------------------------------------------------------------
 void Train::set_length(int in_length)	//функц≥€ дл€ ввода к≥лькост≥ вагон≥в
 {
	 length=in_length;					//вводимо к≥льк≥сть вагон≥в
 }
 //----------------------------------------------------------------
 int Train::get_length() const	//функц≥€ дл€ отриманн€ к≥лькост≥ вагон≥в
 {
	 return length;				//повертаЇмо к≥льк≥сть вагон≥в
 }
 //----------------------------------------------------------------
 void Train::set_departure_time(const Time &in_departure_time)	//функц≥€ дл€ ввода часу в≥дправленн€
 {
	 departure_time.hours=in_departure_time.hours;				//вводимо час в≥дправленн€ (години)
	 departure_time.minutes=in_departure_time.minutes;			//вводимо час в≥дправленн€ (хвилини)
 }
 //----------------------------------------------------------------
 Time Train::get_departure_time() const	//функц≥€ дл€ отриманн€ часу в≥дправленн€
 {
	 return departure_time;				//повертаЇмо чвс в≥дправленн€
 }
 //----------------------------------------------------------------
 void Train::set_arrival_time(const Time &in_arrival_time)	//функц≥€ дл€ ввода часу прибутт€
 {
	 arrival_time.hours=in_arrival_time.hours;				//вводимо час прибутт€ (години)
	 arrival_time.minutes=in_arrival_time.minutes;			//вводимо час прибутт€ (хвилини)
 }
 //----------------------------------------------------------------
 Time Train::get_arrival_time() const	//функц≥€ дл€ отриманн€ часу прибутт€
 {
	 return arrival_time;				//повертаЇмо час прибутт€
 }
 //----------------------------------------------------------------
 void Train::print() const//функц≥€ дл€ друку об'Їкта
 {
	 cout<<endl<<endl<<type<<"\nTrain number: "<<number<<"\nRoute: "<<route<<"\nlength - "<<length<<" wagons\narrival time - "<<arrival_time.hours<<":"<<arrival_time.minutes<<"\ndeparture time - "<<departure_time.hours<<":"<<departure_time.minutes<<endl;//друкуЇмо вм≥ст об'Їкта
 }
 //----------------------------------------------------------------
 Train::~Train()//деструктор
 {
 }