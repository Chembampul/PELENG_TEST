#pragma once
#include <iostream>
#include "QueueNode.h"
#include "CycledQueue.h"

template <typename T>
class CycledQueue<T>::QueueIterator {
protected:
	typename QueueNode<T>* current;
public:
	QueueIterator() { current = NULL; }
	QueueIterator(typename CycledQueue<T>& obj) { current = obj.front; }
	QueueIterator(typename QueueNode<T>* front) { current = front; }
	~QueueIterator() {}
	T& operator*() { return current->getData(); }
	QueueIterator& operator++() {
		current = current->getpNext();
		return *this;
	}
	QueueIterator& operator+=(int offset) {
		for (int i = 0; i < offset; i++) {
			current = current->getpNext();
		}
		return *this;
	}
	T& operator+(int offset) {
		auto temp = current;
		for (int i = 0; i < offset; i++) {
			temp = temp->getpNext();
		}
		return temp->getData();
	}
	bool operator!=(typename QueueNode<T>* node) {
		return current != node;
	}
	bool operator==(typename QueueNode<T>* node) {
		return current == node;
	}

};