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
	Node* curr = head;
	Node* next = nullptr;

	while (curr != nullptr) {
		next = curr->next;
		delete curr;
		curr = next;
	}

	cout << "list is successfully deleted" << endl;
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
