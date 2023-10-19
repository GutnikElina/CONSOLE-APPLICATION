#pragma once

#ifndef SMARTPOINTER_H

#define SMARTPOINTER_H

#include "common.h"

template <class T>
struct Status 
{
	T* ptr;//указатель на объект
	int counter;//счетчик количества ссылок на объект
};
template <class T>
class SmartPointer 
{
	Status<T>* smartPtr;// указатель на объект
public:
	SmartPointer(T* ptr);//конструктор с одним параметром типа T
	SmartPointer(const SmartPointer& obj);//конструктор
	~SmartPointer();//деструктор
	SmartPointer& operator=(const SmartPointer& obj); //перегрузка

	T* operator->() const;//оператор получения доступа к объекту
	void showCounter() 
	{
		std::cout << "Значение счетчика для объекта "
			<< smartPtr << " равно: " << smartPtr->counter << std::endl;
	}
};

#endif