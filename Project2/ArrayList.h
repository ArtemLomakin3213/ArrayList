#pragma once
#include <iostream>
#include <sstream>
class ArrayList {
private:
	int capacity;
	int size;
	int* data;
	const float k = 1.6;
	const int max_capacity = 10;

public:
	//конструкторы и деструктор
	ArrayList();
	ArrayList(int initialCapacity);
	ArrayList(int capacity, int value);
	ArrayList(const ArrayList& other);
	~ArrayList();

	// Getter and setter
	int getCap() const { return capacity; }
	int getSize() const { return size; }
	int getElementAt(int index) const;
	bool setElementAt(int index, int value);
	//Удаление и добавление элемента в конец массива
	bool addElement(int element);
	bool removeLastElement();
	//метод получения и установки i - го элемента массива
	void shrink();
	//Удаление и добавление элемента в начале массива
	bool insertAtBeginning(int value);
	bool removeAtBeginning();
	//Удаление и добавление элемента по индексу
	bool insertAtIndex(int value, int index);
	bool removeAtIndex(int index);
	//вывод массива
	std::string display();


};

