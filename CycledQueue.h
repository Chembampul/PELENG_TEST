#pragma once
#include <iostream>
#include "QueueNode.h"

template <typename T>
class CycledQueue {

protected:
	class QueueIterator;
	QueueNode<T>* front;
	QueueNode<T>* rear;
	QueueNode<T>* replaceableNode;
	int queueSize;
	int frontControl;
	int rearControl;
public:
	CycledQueue();
	CycledQueue(int size);
	~CycledQueue();
	bool isEmpty();
	bool isFull();
	void push(T data);
	void pop();
	void print();
	QueueIterator begin() { return QueueIterator(front); }
	T& operator[](int indx);

};
