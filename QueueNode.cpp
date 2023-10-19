#include "QueueNode.h"

template <typename T>
QueueNode<T>* QueueNode<T>::getpNext() { return pNext; }

template <typename T>
T& QueueNode<T>::getData() { return data; }

template <typename T>
void QueueNode<T>::setpNext(QueueNode* pNextSet) { this->pNext = pNextSet; }

template <typename T>
void QueueNode<T>::setData(T dataSet) { this->data = dataSet; }

template <typename T>
void QueueNode<T>::operator=(QueueNode<T>& other) {
	this->pNext = other.getpNext();
	this->data = other.getData();
}