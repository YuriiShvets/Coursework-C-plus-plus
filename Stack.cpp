/*
Stack.cpp
Coursework
Shvets Ju. BS-33
Implementation to class "Stack"
*/

#include "Stack.h"

Stack::Stack():head(NULL)//�����������
{

}
//----------------------------------------------------------------
void Stack::push(Train *B)//������� ��� ��������� ��������
{
	Element *A=new Element;//�������� ���'��� �� �������
	A->next=head;//������������ ��������� �� �� ��������� ������� �������� �� ������ �����
	A->data=B;//�������� �����
	head=A;//��������� �� ������ ������� ������������ ������ ������ �������� 
}
//----------------------------------------------------------------
void Stack::print() const//������� ��� ����� ��������
{
	if(head==NULL)//�������� �� ���������� ��������
		cout<<"No trains found\n";//���� ���� �������� �������� �������� �����������
	for(Element *i=head; i!=NULL; i=i->next)//���� ��������� �� ��� ��������� �����
		i->data->print();//��� ������� �������� ����������� ������� �����
}
//----------------------------------------------------------------
void Stack::pop()//������� ��������� �������� �� �����
{
	if(head!=NULL)//�������� �� ���������� ��������
	{
		Element *i=head;//����������� �������� ������� ������ �����
		head=head->next;//��������� �� ������ ����� �������� ������ ���������� ��������
		delete i->data;//��������� ����� �� ������� ��������
		delete i;//��������� ������ �������
	}
	else
	{
		system("cls");//������� �����
		cout<<"No trains found\n";//�������� ����������� ��� ���������� �����
		_getch();//��������
	}
}
//----------------------------------------------------------------
void Stack::Write_to_the_file() const//������� ��� ������ � ����
{
	if(head==NULL)				//�������� �� ���������� ��������
	{
		system("cls");//������� �����
		cout<<"No trains found";//�������� ����������� ��� ���������� �����
		_getch();//��������
	}
	else
	{
		ofstream Trains("Trains.txt");//��������� ����
		Element *k;//��������� ��������
		for(int i=0; i<Size(); i++)//���� ��������� �� ��� ��������� �����
		{
			if(Trains.is_open()==0)	//�������� ����� �� ��������������
			{
				cout<<"failed to open file";//���� ����������� ��� ����������� ������� ����
				_getch();//��������
				break;//����� �� �����
			}//End of "if(Trains.is_open()==0)"
			k=head;//������������ ��������� ������ ������ �����
			for(int j=0; j<Size()-(i+1); j++)//�� ��������� ����� � ������� ����� ��������� �� �������� �� ���������� �� ������� (��� ������ ���������� � ��������� head)
				k=k->next;//������������ ��������� ������ ���������� ��������
			if(typeid(*(k->data))==typeid(Passenger_train))//���� ��'��� �� ��� ������������� ������
				Trains<<(*((Passenger_train*)(k->data)));//����������� ����������� �������� ������ � ���� ��'���� ������������� ������
			if(typeid(*(k->data))==typeid(Freight_train))//���� ��'��� �� ��� ���������� ������
				Trains<<(*((Freight_train*)(k->data)));//����������� ����������� �������� ������ � ���� ����� ���������� ������
		}//End of "for(int i=0; i<Size(); i++)"
		Trains.close();				//��������� ����
	}
	cout<<"Saved";//�������� ����������� ��� ���������� �������� � ����
}
//----------------------------------------------------------------
void Stack::Read_from_the_file()//������� ��� �������� ��'���� �� ������
{
	int k;//��������� ����� � ��� ������ �������� ������������� ���� ������
	ifstream Trains ("Trains.txt");	//��������� ����
	while(!Trains.eof())//���� ���� �� ��������
	{
		if(Trains.is_open()==0)		//�������� ����� �� ��������������
		{
			cout<<"failed to open file";//���� ����������� ��� ���������� �����
			_getch();//��������
			break;//����� � �����
		}//End of "if(Trains.is_open()==0)"
		k=0;
		Trains>>k;//�������� ������������� ����
		if(k==1)//���� ������������� ���� ����� 1
		{
			Passenger_train *B=new Passenger_train;//��������� ��'���� ������������� ������
			Trains>>(*B);			//�������� ��'��� � �����
			push(B);//������ ��'��� � ����
		}//End of "if(k==1)"
		if(k==2)//���� ������������� ���� ����� 2
		{
			Freight_train *B=new Freight_train;//��������� ��'��� ���������� ������
			Trains>>(*B);			//�������� ��'��� � �����
			push(B);//������ ��'��� � ����
		}//End of "if(k==2)"
	}//End of "while(!Trains.eof())"
	cout<<"Loaded";//�������� ����������� ��� ������ ������������ � �����
}
//----------------------------------------------------------------
void Stack::Sort()					//�������� ���������� ������(����������)
{									//���������� ���������� ������� ������ ������
	bool check=false;//��������� ����� ��� ���� ������� ����������� ������������� ����������
	Element *buf1, *bufi, *bufn;//��������� ��������� ���� ������ ������������ ������ ��'����
	int c;//���������� ����� - ��������
	while(check==false)//���� ��������� �� ������������
	{
		c=0;
		check=true;
		for(Element *i=head; i!=NULL; i=i->next)//���� ��������� �� ��� ��������� ����������
		{
			if(((i->next)!=NULL)&&(((i->data)->get_number())>(((i->next)->data)->get_number())))//���� ����� ������ ������ �� ����� ���������� ������
			{
				bufn=i->next;				//
				buf1=i;						//
				buf1->next=(i->next)->next;	//
				i=bufn;						//
				i->next=buf1;				// ������ ��'���� ������
				if(c==0)					//
					head=i;					//
				if(c>0)						//
					bufi->next=i;			//
				check=false;
			}//End of "if(((i->next)!=NULL)&&(((i->data)->get_number())>(((i->next)->data)->get_number())))"
			bufi=i;
			c++;
		}//End of "for(Element *i=head; i!=NULL; i=i->next)"
	}//End of "while(check==true)"
	cout<<"Sorted";//�������� ����������� ��� ������ ����������
}
//----------------------------------------------------------------
void Stack::Fing_the_object() const//������� ��� �������� ����� ������ �� ��������� ������� �������
{
	if(head==NULL)					//�������� �� ���������� ��������
		cout<<"No trains found";//�������� ����������� ��� ���������� ��������
	else
	{
		Element *max=head;//����������� �������� ������� ������ �����
		for(Element *i=head; i!=NULL; i=i->next)//��������� �� ��� ��������� �����
			if(((i->data)->get_length())>((max->data)->get_length()))//���� ������� ������� ����� ��� � ������ �� ���� ����� �������� "max"
				max=i;
		cout<<"Train with a maximum number of cars: � "<<(max->data)->get_number();//�������� ����� ������ �� ������������ ������� �������
	}
}
//----------------------------------------------------------------
void Stack::Clean_collection()//������� ��� �������� ��������
{
	int size=Size();//�������� ������� �������� �����
	if(size==0)						//�������� �� ���������� ��������
		cout<<"No trains found";//�������� ����������� ��� ���������� �����
	else
	{
		for(int i=0; i<size; i++)//������� �������� ����� ������� �� ������� �������� �����
			pop();//��������� ������� ��������� ��������
		cout<<"Cleaned";//�������� ����������� ��� ������ �������� �����
	}
}
//----------------------------------------------------------------
int  Stack::Size() const			//������� ������� �������� ��������
{
	int size=0;// ����������� ������ �����-�������� ��� ��������� ������� ��������
	for(Element *i=head; i!=NULL; i=i->next)//���� ��������� �� ��� ��������� �����
		size++;
	return size;//��������� ������� ��������
}
//----------------------------------------------------------------
Stack::~Stack()//����������
{
	Clean_collection();//��������� ������� �������� ��������
}