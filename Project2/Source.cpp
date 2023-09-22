#include <iostream>
#include "ArrayList.h"

using namespace std;

int main() {
	ArrayList list(10, 10);
	cout << list.display();
	list.insertAtBeginning(2);
	cout << list.display();
	list.removeAtBeginning();
	cout << list.display();
	list.addElement(235);
	cout << list.display();
	list.removeLastElement();
	cout << list.display();
	return 0;
}