#include "ArrayList.h"

ArrayList::ArrayList() : capacity(0), size(0), data(nullptr) { }

ArrayList::ArrayList(int initialCapacity) : capacity(initialCapacity), size(0) {
	data = new int[capacity];
}

ArrayList::ArrayList(int capacity, int value) : capacity(capacity), size(capacity) {
	data = new int[capacity];
	for (int i = 0; i < size; i++) {
		data[i] = value;
	}
}

ArrayList::ArrayList(const ArrayList& other) : capacity(other.capacity), size(other.size) {
	data = new int[capacity];
	for (int i = 0; i < size; i++) {
		if (other.size > i)
			data[i] = other.data[i];
	}
}

int ArrayList::getElementAt(int index) const
{
	if (index >= 0 && index < size) {
		return data[index];
	}
	return -1;

}

bool ArrayList::setElementAt(int index, int value)
{
	if (index >= 0 && index < size) {
		data[index] = value;
		return true;
	}
	return false;
}

bool ArrayList::addElement(int element)
{
	return insertAtIndex(element, ++size);
}

bool ArrayList::removeLastElement() {
	if (size > 0) {
		size--;
		return true;
	}
	return false;
}

void ArrayList::shrink()
{
	if (size < capacity) {
		int* newData = new int[size];
		std::copy(data, data + size, newData);
		delete[] data;
		data = newData;
		capacity = size;
	}
}


bool ArrayList::insertAtIndex(int value, int index)
{
	if (index >= 0 && index <= size) {
		if (size == capacity) {
			int newCapacity = capacity * k;
			int* newData = new int[newCapacity];
			std::copy(data, data + size, newData);
			delete[] data;
			data = newData;
			capacity = newCapacity;
		}
		for (int i = size; i > index; i--) {
			data[i] = data[i - 1];
		}
		data[index] = value;
		size++;
		return true;
	}
	return false;
}


bool ArrayList::removeAtIndex(int index)
{
	if (index >= 0 && index < size) {
		for (int i = index; i < size - 1; i++) {
			data[i] = data[i + 1];
		}
		size--;
		if (size < capacity / 2) {
			int newCapacity = capacity / k;
			int* newData = new int[newCapacity];
			std::copy(data, data + size, newData);
			delete[] data;
			data = newData;
			capacity = newCapacity;
		}
		return true;
	}
	return false;
}

bool ArrayList::insertAtBeginning(int value) {
	return insertAtIndex(value, 0);
}

bool ArrayList::removeAtBeginning()
{
	return removeAtIndex(0);
}

std::string ArrayList::display() {
	std::ostringstream out;
	for (int i = 0; i < size; i++) {
		out << data[i] << " ";
	}
	out << std::endl;
	return out.str();
}

ArrayList::~ArrayList()
{
	delete[] data;
}
