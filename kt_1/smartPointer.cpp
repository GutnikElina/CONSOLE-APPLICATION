#include "smartPointer.h"

template <class T>
SmartPointer<T>::SmartPointer(T* ptr) {
	if (!ptr)
		smartPtr = NULL;//указатель на объект пустой
	else {
		smartPtr = new Status<T>();
		smartPtr->ptr = ptr;//инициализирует объект указателем
		smartPtr->counter = 1;//счетчик «прикрепленных» объектов
	}
}
template <class T>
SmartPointer<T>::SmartPointer(const SmartPointer& obj)
	:smartPtr(obj.smartPtr) {
	if (smartPtr) smartPtr->counter++;//увеличение количества
}
template <class T>
SmartPointer<T>::~SmartPointer() {
	if (smartPtr) {
		smartPtr->counter--;//уменьшение количества ссылок на объект
			if (smartPtr->counter == 0) {//если число ссылок на объект равно нулю, то должен уничтожится объект
					delete smartPtr->ptr;//освобождение памяти,выделенной для объекта
					delete smartPtr;//освобождение памяти, выделенной для указателя
			}
	}
}
template <class T>
T* SmartPointer<T>::operator->() const {
	if (smartPtr) return smartPtr->ptr;
	else return NULL;
}
template <class T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer&
	obj) {
	if (smartPtr) {
		smartPtr->counter--;//уменьшаем счетчик «прикрепленных» объектов для текущего указателя
			if (smartPtr->counter == 0) {//если объектов больше нет,
				delete smartPtr->ptr;
				delete smartPtr;
			}
	}
	smartPtr = obj.smartPtr;//присваивание нового адреса указателю
	if (smartPtr) smartPtr->counter++;//увеличить счетчик
	return *this;
}

