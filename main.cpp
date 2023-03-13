#include "LinkedList.hpp"

int main() {
	LinkedList<int> list;


	list.append(1);
	list.append(2);
	list.append(3);
	list.append(4);
	list.append(5);

	cout << "Expected:	1,2,3,4,5" << endl;
	cout << "Actual:	";
	list.print();

	list.push_front(6);

	cout << "Expected:	6,1,2,3,4,5" << endl;
	cout << "Actual:	";
	list.print();

	return 0;
}