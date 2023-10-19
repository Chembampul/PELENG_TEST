#pragma once
#include <iostream>

template <typename T>
class QueueNode {
protected:
	QueueNode* pNext;
	T data;
public:
	QueueNode* getpNext();
	T& getData();
	void setpNext(QueueNode* pNextSet);
	void setData(T dataSet);
	void operator=(QueueNode& other);
};



