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
	//������������ � ����������
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
	//�������� � ���������� �������� � ����� �������
	bool addElement(int element);
	bool removeLastElement();
	//����� ��������� � ��������� i - �� �������� �������
	void shrink();
	//�������� � ���������� �������� � ������ �������
	bool insertAtBeginning(int value);
	bool removeAtBeginning();
	//�������� � ���������� �������� �� �������
	bool insertAtIndex(int value, int index);
	bool removeAtIndex(int index);
	//����� �������
	std::string display();


};

