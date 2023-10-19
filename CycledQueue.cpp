#include "CycledQueue.h"

template <typename T>
CycledQueue<T>::CycledQueue() {
	queueSize = 0;
	frontControl = -1;
	front = NULL;
	rearControl = -1;
	rear = NULL;
	replaceableNode = NULL;
}

template <typename T>
CycledQueue<T>::CycledQueue(int size) {
	queueSize = size;
	frontControl = -1;
	front = NULL;
	rearControl = -1;
	rear = NULL;
	replaceableNode = NULL;
}

template <typename T>
CycledQueue<T>::~CycledQueue() {}

template <typename T>
bool CycledQueue<T>::isEmpty() {
	if (frontControl == -1)
		return true;
	return false;
}

template <typename T>
bool CycledQueue<T>::isFull() {
	if ((frontControl == 0 && rearControl == queueSize - 1) || frontControl == rearControl + 1)
		return true;
	return false;
}

template <typename T>
void CycledQueue<T>::push(T data) {
	if (isEmpty()) {
		frontControl = 0;
		rearControl = 0;
		QueueNode<T>* temp;
		temp = new QueueNode<T>;
		temp->setData(data);
		temp->setpNext(temp);
		front = temp;
		rear = temp;
		replaceableNode = temp;
	}
	else if (isFull()) {
		replaceableNode->setData(data);
		replaceableNode = replaceableNode->getpNext();
		front = front->getpNext();
		frontControl = (frontControl + 1) % queueSize;
		rear = rear->getpNext();
		rearControl = (rearControl + 1) % queueSize;
	}
	else {
		QueueNode<T>* temp;
		temp = new QueueNode<T>;
		temp->setData(data);
		temp->setpNext(front);
		rear->setpNext(temp);
		rear = temp;
		rearControl = (rearControl + 1) % queueSize;
	}
}

template <typename T>
void CycledQueue<T>::pop() {
	if (front == rear) {
		delete front;
		frontControl = -1;
		front = NULL;
		rearControl = -1;
		rear = NULL;
		replaceableNode = NULL;
	}
	else {
		QueueNode<T>* temp;
		temp = front;
		if (replaceableNode == temp)
			replaceableNode = front->getpNext();
		front = front->getpNext();
		frontControl = (frontControl + 1) % queueSize;
		rear->setpNext(front);
		delete temp;
	}
}

template <typename T>
void CycledQueue<T>::print() {
	auto iterator = this->begin();
	do {
		std::cout << *iterator << "\t";
		++iterator;
	} while (iterator != front);
	std::cout << std::endl;
}

template <typename T>
T& CycledQueue<T>::operator[](int indx) {
	auto iterator = this->begin();
	for (int i = 0; i < indx; i++) {
		++iterator;
	}
	return *iterator;
}