#pragma once

#ifndef SMARTPOINTER_H

#define SMARTPOINTER_H

#include "common.h"

template <class T>
struct Status 
{
	T* ptr;//��������� �� ������
	int counter;//������� ���������� ������ �� ������
};
template <class T>
class SmartPointer 
{
	Status<T>* smartPtr;// ��������� �� ������
public:
	SmartPointer(T* ptr);//����������� � ����� ���������� ���� T
	SmartPointer(const SmartPointer& obj);//�����������
	~SmartPointer();//����������
	SmartPointer& operator=(const SmartPointer& obj); //����������

	T* operator->() const;//�������� ��������� ������� � �������
	void showCounter() 
	{
		std::cout << "�������� �������� ��� ������� "
			<< smartPtr << " �����: " << smartPtr->counter << std::endl;
	}
};

#endif