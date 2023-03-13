#include "LinkedList.hpp"

int main() {
	LinkedList<int> list;


	list.append(1);
	list.append(2);
	list.append(3);
	list.append(4);
	list.append(5);


	list.print();

	list.push_front(6);

	list.print();

	return 0;
}
