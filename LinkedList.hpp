#pragma once
#include <iostream>
using namespace std;
// header file for a Single Linked List

template<typename T>
class LinkedList{
public:
	// default constructor
	LinkedList();

	// destructor
	~LinkedList();

	// print the list
	void print();

	// push front of the list
	void push_front(T val);

	// append to the end of the list
	void append(T val);

	// returns the size of the list
	unsigned length();

	// empty the list 
	void clear();

	// delete element i in the list
	void remove(int index);


private:
	struct Node {
		T value;
		Node* next;

		Node(T v) : value(v), next(nullptr) {}
	};

	Node* head;
	unsigned size;
};

// Constructor: set the head to nullptr
template<typename T>
LinkedList<T>::LinkedList() : size(0) {
	head = nullptr;	// just set to null because there is nothing in the list yet 
}

// Destructor is actually a bit of a process
template<typename T>
LinkedList<T>::~LinkedList() {
	this->clear();
}

// delete the list
template<typename T>
void LinkedList<T>::clear() {
	Node* curr = head;
	Node* next = nullptr;

	while (curr != nullptr) {
		next = curr->next;
		delete curr;
		curr = next;
	}
	this->size = 0;
}



// print the list
template<typename T>
void LinkedList<T>::print() {
	Node* curr = head;
	while (curr != nullptr) {
		cout << curr->value;
		if (curr->next != nullptr) {
			cout << ", ";
		}
		curr = curr->next;
	}
	cout << endl;
}

// push element to the front of the list
template<typename T>
void LinkedList<T>::push_front(T val) {
	Node* n = new Node(val);

	if (this->size > 0) {
		n->next = head;
	}

	head = n;
	this->size++;
}

// push element to the back of the list
template<typename T>
void LinkedList<T>::append(T val) {
	Node* n = new Node(val);

	if (this->size == 0) {
		head = n;
	}
	else {
		Node* curr = head;

		// iterate through the list
		while (curr->next != nullptr) {
			curr = curr->next;
		}

		curr->next = n;
	}

	(this->size)++;
}

// size: returns the length of the list
template<typename T>
unsigned LinkedList<T>::length() {
	return this->size;
}

// delete: deletes the ith element of the list (index 0)
template<typename T>
void LinkedList<T>::remove(int index) {
	Node* curr = head;
	Node* prev = nullptr;

	// iterate through the list until curr == ith element
	for (int i = 0; i < index; i++) {
		prev = curr;
		curr = curr->next;
	}

	// now mark the element to remove, and move curr to i+1 element
	Node* remove = curr;
	curr = curr->next;

	// delete remove
	delete remove;
	remove = nullptr;

	// set new links between prev and curr (around the removed element)
	prev->next = curr;
	
	// decrement the size of the list
	this->size--;
}
