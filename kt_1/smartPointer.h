#pragma once

#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#define _CRT_SECURE_NO_WARNINGS

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
};

#endif